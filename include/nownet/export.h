/**
 * @file export.h
 * @author Krisna Pranav
 * @brief export
 * @version 1.0
 * @date 2024-03-30
 *
 * @copyright Copyright (c) 2024 Krisna Pranav, NowWallet Authors
 *
 */

#pragma once

#ifdef _WIN32
#define EXPORT __cdecl
#else
#define EXPORT
#endif