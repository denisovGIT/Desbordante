#pragma once

#include <thread>

#include "algorithms/options/common_option.h"
#include "algorithms/options/names_and_descriptions.h"

namespace algos::config {

using ThreadNumType = ushort;
const CommonOption<ThreadNumType> ThreadNumberOpt{
        {names::kThreads, descriptions::kDThreads}, 0, [](auto &value) {
            if (value == 0) {
                value = std::thread::hardware_concurrency();
                if (value == 0) {
                    throw std::runtime_error(
                            "Unable to detect number of concurrent "
                            "threads supported by your system. "
                            "Please, specify it manually.");
                }
            }
        }};

}  // namespace algos::config
