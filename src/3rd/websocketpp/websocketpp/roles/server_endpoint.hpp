

#ifndef WEBSOCKETPP_SERVER_ENDPOINT_HPP
#define WEBSOCKETPP_SERVER_ENDPOINT_HPP

#include <websocketpp/endpoint.hpp>

#include <websocketpp/logger/levels.hpp>

#include <websocketpp/common/system_error.hpp>

namespace websocketpp {

/// Server endpoint role based on the given config
/**
 *
 */
template <typename config>
class server : public endpoint<connection<config>,config> {
public:
    /// Type of this endpoint
    typedef server<config> type;

    /// Type of the endpoint concurrency component
    typedef typename config::concurrency_type concurrency_type;
    /// Type of the endpoint transport component
    typedef typename config::transport_type transport_type;

    /// Type of the connections this server will create
    typedef connection<config> connection_type;
    /// Type of a shared pointer to the connections this server will create
    typedef typename connection_type::ptr connection_ptr;

    /// Type of the connection transport component
    typedef typename transport_type::transport_con_type transport_con_type;
    /// Type of a shared pointer to the connection transport component
    typedef typename transport_con_type::ptr transport_con_ptr;

    /// Type of the endpoint component of this server
    typedef endpoint<connection_type,config> endpoint_type;

    explicit server() : endpoint_type(true)
    {
        endpoint_type::m_alog.write(log::alevel::devel, "server constructor");
    }

    /// Destructor
    ~server<config>() {}

#ifdef _WEBSOCKETPP_DEFAULT_DELETE_FUNCTIONS_
    // no copy constructor because endpoints are not copyable
    server<config>(server<config> &) = delete;
    
    // no copy assignment operator because endpoints are not copyable
    server<config> & operator=(server<config> const &) = delete;
#endif // _WEBSOCKETPP_DEFAULT_DELETE_FUNCTIONS_

#ifdef _WEBSOCKETPP_MOVE_SEMANTICS_
    /// Move constructor
    server<config>(server<config> && o) : endpoint<connection<config>,config>(std::move(o)) {}

#ifdef _WEBSOCKETPP_DEFAULT_DELETE_FUNCTIONS_
    // no move assignment operator because of const member variables
    server<config> & operator=(server<config> &&) = delete;
#endif // _WEBSOCKETPP_DEFAULT_DELETE_FUNCTIONS_

#endif // _WEBSOCKETPP_MOVE_SEMANTICS_

    /// Create and initialize a new connection
    /**
     * The connection will be initialized and ready to begin. Call its start()
     * method to begin the processing loop.
     *
     * Note: The connection must either be started or terminated using
     * connection::terminate in order to avoid memory leaks.
     *
     * @return A pointer to the new connection.
     */
    connection_ptr get_connection() {
        return endpoint_type::create_connection();
    }

    /// Starts the server's async connection acceptance loop (exception free)
    /**
     * Initiates the server connection acceptance loop. Must be called after
     * listen. This method will have no effect until the underlying io_service
     * starts running. It may be called after the io_service is already running.
     *
     * Refer to documentation for the transport policy you are using for
     * instructions on how to stop this acceptance loop.
     * 
     * @param [out] ec A status code indicating an error, if any.
     */
    void start_accept(lib::error_code & ec) {
        if (!transport_type::is_listening()) {
            ec = error::make_error_code(error::async_accept_not_listening);
            return;
        }
        
        ec = lib::error_code();
        connection_ptr con = get_connection();
        
        transport_type::async_accept(
            lib::static_pointer_cast<transport_con_type>(con),
            lib::bind(&type::handle_accept,this,con,lib::placeholders::_1),
            ec
        );
        
        if (ec && con) {
            // If the connection was constructed but the accept failed,
            // terminate the connection to prevent memory leaks
            con->terminate(lib::error_code());
        }
    }

    /// Starts the server's async connection acceptance loop
    /**
     * Initiates the server connection acceptance loop. Must be called after
     * listen. This method will have no effect until the underlying io_service
     * starts running. It may be called after the io_service is already running.
     *
     * Refer to documentation for the transport policy you are using for
     * instructions on how to stop this acceptance loop.
     */
    void start_accept() {
        lib::error_code ec;
        start_accept(ec);
        if (ec) {
            throw exception(ec);
        }
    }

    /// Handler callback for start_accept
    void handle_accept(connection_ptr con, lib::error_code const & ec) {
        if (ec) {
            con->terminate(ec);

            if (ec == error::operation_canceled) {
                endpoint_type::m_elog.write(log::elevel::info,
                    "handle_accept error: "+ec.message());
            } else {
                endpoint_type::m_elog.write(log::elevel::rerror,
                    "handle_accept error: "+ec.message());
            }
        } else {
            con->start();
        }

        lib::error_code start_ec;
        start_accept(start_ec);
        if (start_ec == error::async_accept_not_listening) {
            endpoint_type::m_elog.write(log::elevel::info,
                "Stopping acceptance of new connections because the underlying transport is no longer listening.");
        } else if (start_ec) {
            endpoint_type::m_elog.write(log::elevel::rerror,
                "Restarting async_accept loop failed: "+ec.message());
        }
    }
};

} // namespace websocketpp

#endif //WEBSOCKETPP_SERVER_ENDPOINT_HPP
