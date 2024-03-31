/**
 * @file udp.h
 * @author Krisna Pranav
 * @brief udp
 * @version 1.0
 * @date 2024-03-31
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#pragma once

#include "context.h"

#ifdef __cplusplus
extern "C"
{
#endif

    struct udp_flowinfo
    {
        char remote_host[256];
        uint16_t remote_port;
        int socket_id;
    };

    struct udp_bind_result
    {
        int socket_id;
    };

    typedef int (*udp_flow_filter)(void *userdata, const struct udp_flowinfo *remote_address, void **flow_userdata, int *timeout_seconds);

    typedef void(udp_create_flow_func)(void *userdata, void **flow_userdata, int *timeout_seconds);

    typedef void (*udp_flow_recv_func)(const struct udp_flow_info *remote_address, const char *pkt_data, size_t pkt_length, void *flow_userdata);

    typedef void (*udp_flow_timeout_func)(const struct udp_flowinfo *remote_address, void *flow_userdata);

#ifdef __cplusplus
}
#endif