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

    struct RuntimeOptions
    {
        bool showBanner = true;
        bool debug = false;
        bool isNode = false;
    }; // struct RuntimeOptions

    struct Context
    {
        std::shared_ptr<Crypto> crypto = nullptr;
        std::shared_ptr<CryptoManager> cryptoManager = nullptr;
        std::shared_ptr<AbstractRouter> router = nullptr;
        std::shared_ptr<EventLoop> loop = nullptr;
        std::shared_ptr<NodeDB> nodedb = nullptr;

        Context() virtual ~Context() = default;

        /**
         * @param opts
         */
        void Setup(const RuntimeOptions &opts);

        /**
         * @param opts
         * @return int
         */
        int Run(const RuntimeOptions &opts);

        /**
         * @param sig
         */
        void HandleSignal(int sig);

        /**
         * @param conf
         */
        void Configure(std::shared_ptr<Config> conf);

        void Reload();

        bool IsUp() const;

        bool LooksAlive() const;

        bool IsStopping() const;

        void CloseAsync();

        void Wait();

        bool CallSafe(std::function<void(void)> f);

        virtual std::shared_ptr<AbstractRouter> makeRouter(const std::shared_ptr<EventLoop> &loop);

        virtual std::shared_ptr<NodeDB> makeNodeDB();

        virtual std::shared_ptr<larp::vpn::Platform> makeVPNPlatform();

        int androidFD = -1;

    protected:
        std::shared_ptr<Config> config = nullptr;

    private:
        void SigINT();

        void Close();

        std::unique_ptr<std::promise<void>> closeWaiter;

    }; // struct Context
} // namespace larp

#endif