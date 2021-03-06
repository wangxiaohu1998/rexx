
#include <stdio.h>
#include <openssl/err.h>
#include <openssl/fips.h>

/* BEGIN ERROR CODES */
#ifndef OPENSSL_NO_ERR

# define ERR_FUNC(func) ERR_PACK(ERR_LIB_FIPS,func,0)
# define ERR_REASON(reason) ERR_PACK(ERR_LIB_FIPS,0,reason)

static ERR_STRING_DATA FIPS_str_functs[] = {
    {ERR_FUNC(FIPS_F_DH_BUILTIN_GENPARAMS), "DH_BUILTIN_GENPARAMS"},
    {ERR_FUNC(FIPS_F_DH_INIT), "DH_INIT"},
    {ERR_FUNC(FIPS_F_DRBG_RESEED), "DRBG_RESEED"},
    {ERR_FUNC(FIPS_F_DSA_BUILTIN_PARAMGEN), "DSA_BUILTIN_PARAMGEN"},
    {ERR_FUNC(FIPS_F_DSA_BUILTIN_PARAMGEN2), "DSA_BUILTIN_PARAMGEN2"},
    {ERR_FUNC(FIPS_F_DSA_DO_SIGN), "DSA_do_sign"},
    {ERR_FUNC(FIPS_F_DSA_DO_VERIFY), "DSA_do_verify"},
    {ERR_FUNC(FIPS_F_FIPS_CHECK_DSA), "FIPS_CHECK_DSA"},
    {ERR_FUNC(FIPS_F_FIPS_CHECK_DSA_PRNG), "fips_check_dsa_prng"},
    {ERR_FUNC(FIPS_F_FIPS_CHECK_EC), "FIPS_CHECK_EC"},
    {ERR_FUNC(FIPS_F_FIPS_CHECK_EC_PRNG), "fips_check_ec_prng"},
    {ERR_FUNC(FIPS_F_FIPS_CHECK_INCORE_FINGERPRINT),
     "FIPS_check_incore_fingerprint"},
    {ERR_FUNC(FIPS_F_FIPS_CHECK_RSA), "fips_check_rsa"},
    {ERR_FUNC(FIPS_F_FIPS_CHECK_RSA_PRNG), "fips_check_rsa_prng"},
    {ERR_FUNC(FIPS_F_FIPS_CIPHER), "FIPS_cipher"},
    {ERR_FUNC(FIPS_F_FIPS_CIPHERINIT), "FIPS_cipherinit"},
    {ERR_FUNC(FIPS_F_FIPS_CIPHER_CTX_CTRL), "FIPS_CIPHER_CTX_CTRL"},
    {ERR_FUNC(FIPS_F_FIPS_DIGESTFINAL), "FIPS_digestfinal"},
    {ERR_FUNC(FIPS_F_FIPS_DIGESTINIT), "FIPS_digestinit"},
    {ERR_FUNC(FIPS_F_FIPS_DIGESTUPDATE), "FIPS_digestupdate"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_BYTES), "FIPS_DRBG_BYTES"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_CHECK), "FIPS_DRBG_CHECK"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_CPRNG_TEST), "FIPS_DRBG_CPRNG_TEST"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_ERROR_CHECK), "FIPS_DRBG_ERROR_CHECK"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_GENERATE), "FIPS_drbg_generate"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_INIT), "FIPS_drbg_init"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_INSTANTIATE), "FIPS_drbg_instantiate"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_NEW), "FIPS_drbg_new"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_RESEED), "FIPS_drbg_reseed"},
    {ERR_FUNC(FIPS_F_FIPS_DRBG_SINGLE_KAT), "FIPS_DRBG_SINGLE_KAT"},
    {ERR_FUNC(FIPS_F_FIPS_DSA_SIGN_DIGEST), "FIPS_dsa_sign_digest"},
    {ERR_FUNC(FIPS_F_FIPS_DSA_VERIFY_DIGEST), "FIPS_dsa_verify_digest"},
    {ERR_FUNC(FIPS_F_FIPS_GET_ENTROPY), "FIPS_GET_ENTROPY"},
    {ERR_FUNC(FIPS_F_FIPS_MODULE_MODE_SET), "FIPS_module_mode_set"},
    {ERR_FUNC(FIPS_F_FIPS_PKEY_SIGNATURE_TEST), "fips_pkey_signature_test"},
    {ERR_FUNC(FIPS_F_FIPS_RAND_ADD), "FIPS_rand_add"},
    {ERR_FUNC(FIPS_F_FIPS_RAND_BYTES), "FIPS_rand_bytes"},
    {ERR_FUNC(FIPS_F_FIPS_RAND_PSEUDO_BYTES), "FIPS_rand_pseudo_bytes"},
    {ERR_FUNC(FIPS_F_FIPS_RAND_SEED), "FIPS_rand_seed"},
    {ERR_FUNC(FIPS_F_FIPS_RAND_SET_METHOD), "FIPS_rand_set_method"},
    {ERR_FUNC(FIPS_F_FIPS_RAND_STATUS), "FIPS_rand_status"},
    {ERR_FUNC(FIPS_F_FIPS_RSA_SIGN_DIGEST), "FIPS_rsa_sign_digest"},
    {ERR_FUNC(FIPS_F_FIPS_RSA_VERIFY_DIGEST), "FIPS_rsa_verify_digest"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_AES), "FIPS_selftest_aes"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_AES_CCM), "FIPS_selftest_aes_ccm"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_AES_GCM), "FIPS_selftest_aes_gcm"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_AES_XTS), "FIPS_selftest_aes_xts"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_CMAC), "FIPS_selftest_cmac"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_DES), "FIPS_selftest_des"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_DSA), "FIPS_selftest_dsa"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_ECDSA), "FIPS_selftest_ecdsa"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_HMAC), "FIPS_selftest_hmac"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_SHA1), "FIPS_selftest_sha1"},
    {ERR_FUNC(FIPS_F_FIPS_SELFTEST_X931), "FIPS_selftest_x931"},
    {ERR_FUNC(FIPS_F_FIPS_SET_PRNG_KEY), "FIPS_SET_PRNG_KEY"},
    {ERR_FUNC(FIPS_F_HASH_FINAL), "HASH_FINAL"},
    {ERR_FUNC(FIPS_F_RSA_BUILTIN_KEYGEN), "RSA_BUILTIN_KEYGEN"},
    {ERR_FUNC(FIPS_F_RSA_EAY_INIT), "RSA_EAY_INIT"},
    {ERR_FUNC(FIPS_F_RSA_EAY_PRIVATE_DECRYPT), "RSA_EAY_PRIVATE_DECRYPT"},
    {ERR_FUNC(FIPS_F_RSA_EAY_PRIVATE_ENCRYPT), "RSA_EAY_PRIVATE_ENCRYPT"},
    {ERR_FUNC(FIPS_F_RSA_EAY_PUBLIC_DECRYPT), "RSA_EAY_PUBLIC_DECRYPT"},
    {ERR_FUNC(FIPS_F_RSA_EAY_PUBLIC_ENCRYPT), "RSA_EAY_PUBLIC_ENCRYPT"},
    {ERR_FUNC(FIPS_F_RSA_X931_GENERATE_KEY_EX), "RSA_X931_generate_key_ex"},
    {0, NULL}
};

static ERR_STRING_DATA FIPS_str_reasons[] = {
    {ERR_REASON(FIPS_R_ADDITIONAL_INPUT_ERROR_UNDETECTED),
     "additional input error undetected"},
    {ERR_REASON(FIPS_R_ADDITIONAL_INPUT_TOO_LONG),
     "additional input too long"},
    {ERR_REASON(FIPS_R_ALREADY_INSTANTIATED), "already instantiated"},
    {ERR_REASON(FIPS_R_AUTHENTICATION_FAILURE), "authentication failure"},
    {ERR_REASON(FIPS_R_CONTRADICTING_EVIDENCE), "contradicting evidence"},
    {ERR_REASON(FIPS_R_DRBG_NOT_INITIALISED), "drbg not initialised"},
    {ERR_REASON(FIPS_R_DRBG_STUCK), "drbg stuck"},
    {ERR_REASON(FIPS_R_ENTROPY_ERROR_UNDETECTED), "entropy error undetected"},
    {ERR_REASON(FIPS_R_ENTROPY_NOT_REQUESTED_FOR_RESEED),
     "entropy not requested for reseed"},
    {ERR_REASON(FIPS_R_ENTROPY_SOURCE_STUCK), "entropy source stuck"},
    {ERR_REASON(FIPS_R_ERROR_INITIALISING_DRBG), "error initialising drbg"},
    {ERR_REASON(FIPS_R_ERROR_INSTANTIATING_DRBG), "error instantiating drbg"},
    {ERR_REASON(FIPS_R_ERROR_RETRIEVING_ADDITIONAL_INPUT),
     "error retrieving additional input"},
    {ERR_REASON(FIPS_R_ERROR_RETRIEVING_ENTROPY), "error retrieving entropy"},
    {ERR_REASON(FIPS_R_ERROR_RETRIEVING_NONCE), "error retrieving nonce"},
    {ERR_REASON(FIPS_R_FINGERPRINT_DOES_NOT_MATCH),
     "fingerprint does not match"},
    {ERR_REASON(FIPS_R_FINGERPRINT_DOES_NOT_MATCH_NONPIC_RELOCATED),
     "fingerprint does not match nonpic relocated"},
    {ERR_REASON(FIPS_R_FINGERPRINT_DOES_NOT_MATCH_SEGMENT_ALIASING),
     "fingerprint does not match segment aliasing"},
    {ERR_REASON(FIPS_R_FIPS_MODE_ALREADY_SET), "fips mode already set"},
    {ERR_REASON(FIPS_R_FIPS_SELFTEST_FAILED), "fips selftest failed"},
    {ERR_REASON(FIPS_R_FUNCTION_ERROR), "function error"},
    {ERR_REASON(FIPS_R_GENERATE_ERROR), "generate error"},
    {ERR_REASON(FIPS_R_GENERATE_ERROR_UNDETECTED),
     "generate error undetected"},
    {ERR_REASON(FIPS_R_INSTANTIATE_ERROR), "instantiate error"},
    {ERR_REASON(FIPS_R_INSUFFICIENT_SECURITY_STRENGTH),
     "insufficient security strength"},
    {ERR_REASON(FIPS_R_INTERNAL_ERROR), "internal error"},
    {ERR_REASON(FIPS_R_INVALID_KEY_LENGTH), "invalid key length"},
    {ERR_REASON(FIPS_R_INVALID_PARAMETERS), "invalid parameters"},
    {ERR_REASON(FIPS_R_IN_ERROR_STATE), "in error state"},
    {ERR_REASON(FIPS_R_KEY_TOO_SHORT), "key too short"},
    {ERR_REASON(FIPS_R_NONCE_ERROR_UNDETECTED), "nonce error undetected"},
    {ERR_REASON(FIPS_R_NON_FIPS_METHOD), "non fips method"},
    {ERR_REASON(FIPS_R_NOPR_TEST1_FAILURE), "nopr test1 failure"},
    {ERR_REASON(FIPS_R_NOPR_TEST2_FAILURE), "nopr test2 failure"},
    {ERR_REASON(FIPS_R_NOT_INSTANTIATED), "not instantiated"},
    {ERR_REASON(FIPS_R_PAIRWISE_TEST_FAILED), "pairwise test failed"},
    {ERR_REASON(FIPS_R_PERSONALISATION_ERROR_UNDETECTED),
     "personalisation error undetected"},
    {ERR_REASON(FIPS_R_PERSONALISATION_STRING_TOO_LONG),
     "personalisation string too long"},
    {ERR_REASON(FIPS_R_PRNG_STRENGTH_TOO_LOW), "prng strength too low"},
    {ERR_REASON(FIPS_R_PR_TEST1_FAILURE), "pr test1 failure"},
    {ERR_REASON(FIPS_R_PR_TEST2_FAILURE), "pr test2 failure"},
    {ERR_REASON(FIPS_R_REQUEST_LENGTH_ERROR_UNDETECTED),
     "request length error undetected"},
    {ERR_REASON(FIPS_R_REQUEST_TOO_LARGE_FOR_DRBG),
     "request too large for drbg"},
    {ERR_REASON(FIPS_R_RESEED_COUNTER_ERROR), "reseed counter error"},
    {ERR_REASON(FIPS_R_RESEED_ERROR), "reseed error"},
    {ERR_REASON(FIPS_R_SELFTEST_FAILED), "selftest failed"},
    {ERR_REASON(FIPS_R_SELFTEST_FAILURE), "selftest failure"},
    {ERR_REASON(FIPS_R_STRENGTH_ERROR_UNDETECTED),
     "strength error undetected"},
    {ERR_REASON(FIPS_R_TEST_FAILURE), "test failure"},
    {ERR_REASON(FIPS_R_UNINSTANTIATE_ERROR), "uninstantiate error"},
    {ERR_REASON(FIPS_R_UNINSTANTIATE_ZEROISE_ERROR),
     "uninstantiate zeroise error"},
    {ERR_REASON(FIPS_R_UNSUPPORTED_DRBG_TYPE), "unsupported drbg type"},
    {ERR_REASON(FIPS_R_UNSUPPORTED_PLATFORM), "unsupported platform"},
    {0, NULL}
};

#endif

void ERR_load_FIPS_strings(void)
{
#ifndef OPENSSL_NO_ERR

    if (ERR_func_error_string(FIPS_str_functs[0].error) == NULL) {
        ERR_load_strings(0, FIPS_str_functs);
        ERR_load_strings(0, FIPS_str_reasons);
    }
#endif
}
