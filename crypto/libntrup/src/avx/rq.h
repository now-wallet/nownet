/**
 * @file rq.h
 * @author Krisna Pranav
 * @brief rq
 * @version 1.0
 * @date 2024-04-04
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#ifndef rq_h
#define rq_h

#include "modq.h"
#include "small.h"

#define rq_encode crypto_kem_sntrup4591761_avx_rq_encode
extern void rq_encode(unsigned char *, const modq *);

#define rq_decode crypto_kem_sntrup4591761_avx_rq_decode
extern void rq_decode(modq *, const unsigned char *);

#define rq_roundencode crypto_kem_sntrup4591761_avx_rq_roundencode
extern void rq_roundencode(unsigned char *, const modq *);

#define rq_decoderounded crypto_kem_sntrup4591761_avx_rq_decoderounded
extern void rq_decoderounded(modq *, const unsigned char *);

#endif