#include "gb/app/frontend/realtime/network_config.hpp"

#include <algorithm>
#include <filesystem>
#include <fstream>

namespace gb::frontend {

std::optional<NetworkFrontendConfig> loadNetworkFrontendConfig(const std::string& path) {
    std::ifstream in(path);
    if (!in) {
        return std::nullopt;
    }

    NetworkFrontendConfig config{};
    std::string line;
    while (std::getline(in, line)) {
        const auto eq = line.find('=');
        if (eq == std::string::npos) {
            continue;
        }
        const std::string key = line.substr(0, eq);
        const std::string value = line.substr(eq + 1);
        try {
            if (key == "netplay_delay") {
                config.netplayDelayFrames = std::clamp(std::stoi(value), 0, 10);
            } else if (key == "link_mode") {
                config.linkMode = std::clamp(std::stoi(value), 0, 3);
            }
        } catch (...) {
        }
    }
    return config;
}

bool saveNetworkFrontendConfig(const std::string& path, const NetworkFrontendConfig& config) {
    std::error_code ec;
    std::filesystem::create_directories(std::filesystem::path(path).parent_path(), ec);

    std::ofstream out(path, std::ios::trunc);
    if (!out) {
        return false;
    }
    out << "netplay_delay=" << std::clamp(config.netplayDelayFrames, 0, 10) << "\n";
    out << "link_mode=" << std::clamp(config.linkMode, 0, 3) << "\n";
    return static_cast<bool>(out);
}

} // namespace gb::frontend
