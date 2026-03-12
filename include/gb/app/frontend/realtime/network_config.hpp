#pragma once

#include <optional>
#include <string>

namespace gb::frontend {

struct NetworkFrontendConfig {
    int netplayDelayFrames = 0;
    int linkMode = 0;
};

std::optional<NetworkFrontendConfig> loadNetworkFrontendConfig(const std::string& path);
bool saveNetworkFrontendConfig(const std::string& path, const NetworkFrontendConfig& config);

} // namespace gb::frontend
