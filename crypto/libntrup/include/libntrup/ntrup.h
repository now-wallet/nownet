/**
 * @file ntrup.h
 * @author Krisna Pranav
 * @brief ntrup
 * @version 1.0
 * @date 2024-04-01
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#ifndef LIBNTRUP_NTRU_H
#define LIBNTRUP_NTRU_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ntrup_api.h"

#define crypto_kem_SECRETKEYBYTES 1600
#define crypto_kem_PUBLICKEYBYTES 1218
#define crypto_kem_CIPHERTEXTBYTES 1047

#define NTRU_SECRETKEYBYTES CRYPTO_SECRETKEYBYTES
#define NTRU_PUBLICKEYBYTES CRYPTO_PUBLICKEYBYTES
#define NTRU_CIPHERTEXTBYTES CRYPTO_CIPHERTEXTBYTES

#define CRYPTO_BYTES 32

#ifdef __cplusplus
}

#endif
#endif