#pragma once

#include <chrono>

namespace gb::frontend {

inline constexpr int kFastForwardMultiplier = 3;
inline constexpr std::chrono::microseconds kNormalFrameBudget{16742};

inline int emulationFramesPerTick(bool /*fastForward*/) {
    return 1;
}

inline std::chrono::microseconds emulationFrameBudget(bool fastForward) {
    if (!fastForward) {
        return kNormalFrameBudget;
    }
    return std::chrono::microseconds(kNormalFrameBudget.count() / kFastForwardMultiplier);
}

} // namespace gb::frontend
