/**
 * @file larp.hpp
 * @author Krisna Pranav
 * @brief larp
 * @version 1.0
 * @date 2024-04-01
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#ifndef LLARP_HPP
#define LLARP_HPP

#include <future>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace larp
{
    namespace vpn
    {
        class Platform;
    } // namespace vpn

    class EventLoop;
    struct Config;
    struct RouterContact;
    struct Config;
    struct Crypto;
    struct CryptoManager;
    struct AbstractRouter;
    class NodeDB;

    namespace thread
    {
        class ThreadPool;
    } // namespace thread

} // namespace larp

#endif