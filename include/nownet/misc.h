/**
 * @file misc.h
 * @author Krisna Pranav
 * @brief misc
 * @version 1.0
 * @date 2024-04-01
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#pragma once

#include "export.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @param netid
     */
    void EXPORT set_netid(const char *netid);

    /**
     * @return const char*
     */
    const char *EXPORT get_netid();

    /**
     * @param level
     * @return int
     */
    int EXPORT log_level(const char *level);

    typedef void (*logger_func)(const char *message, void *context);

    typedef void (*logger_sync)(void *context);

    /**
     * @param func
     * @param sync
     * @param context
     */
    void EXPORT set_syncing_logger(logger_func func, logger_sync sync, void *context);

    /**
     * @param func
     * @param context
     */
    void EXPORT set_logger(logger_func func, void *context);

    /**
     * @param hex
     * @return char*
     */
    char *EXPORT hex_to_base32z(const char *hex);

#ifdef __cplusplus
}
#endif