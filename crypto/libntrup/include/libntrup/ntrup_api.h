/**
 * @file ntrup_api.h
 * @author Krisna Pranav
 * @brief ntrup api
 * @version 1.0
 * @date 2024-04-01
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

/**
 * @param cstr
 * @param k
 * @param pk
 * @return int
 */
int crypto_kem_enc_ref(unsigned char *cstr, unsigned char *k, const unsigned char *pk);

/**
 * @param k
 * @param cstr
 * @param sk
 * @return int
 */
int crypto_kem_dec_ref(unsigned char *k, const unsigned char *cstr, const unsigned char *sk);

/**
 * @param pk
 * @param sk
 * @return int
 */
int crypto_kem_keypair_ref(unsigned char *pk, unsigned char *sk);

/**
 * @param cstr
 * @param k
 * @param pk
 * @return int
 */
int crypto_kem_enc_avx2(unsigned char *cstr, unsigned char *k, const unsigned char *pk);

/**
 * @param k
 * @param cstr
 * @param sk
 * @return int
 */
int crypto_kem_dec_avx2(unsigned char *k, const unsigned char *cstr, const unsigned char *sk);

/**
 * @param pk
 * @param sk
 * @return int
 */
int crypto_kem_keypair_avx2(unsigned char *pk, unsigned char *sk);