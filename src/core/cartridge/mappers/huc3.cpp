#include "factory.hpp"

#include <memory>

namespace gb {
namespace cartridge_mapper {
namespace {

class HuC3Mapper final : public Mapper {
public:
    HuC3Mapper(std::vector<u8>& rom, std::vector<u8>& ram)
        : base_(makeMbc3Mapper(rom, ram)) {
        baseStateSize_ = base_->state().size();
    }

    u8 read(u16 address) const override {
        if (huc3Mode_ && address >= 0xA000 && address <= 0xBFFF) {
            // Suporte basico para leitura de registrador virtual HuC3.
            if (command_ == 0x0B) {
                return static_cast<u8>(huc3Value_ & 0x0F);
            }
            if (command_ == 0x0C) {
                return 0x01;
            }
        }
        return base_->read(address);
    }

    void write(u16 address, u8 value) override {
        if (address <= 0x1FFF) {
            // HuC3 usa comandos especiais no range de RAM enable.
            if ((value & 0xF0) == 0x10) {
                huc3Mode_ = true;
                command_ = static_cast<u8>(value & 0x0F);
                return;
            }
            if (value == 0x00) {
                huc3Mode_ = false;
                command_ = 0;
            }
        }

        if (huc3Mode_ && address >= 0xA000 && address <= 0xBFFF) {
            if (command_ == 0x0A) {
                huc3Value_ = static_cast<u8>(value & 0x0F);
                return;
            }
        }

        base_->write(address, value);
    }

    [[nodiscard]] std::vector<u8> state() const override {
        std::vector<u8> out = base_->state();
        out.push_back(static_cast<u8>(huc3Mode_ ? 1 : 0));
        out.push_back(command_);
        out.push_back(huc3Value_);
        return out;
    }

    void loadState(const std::vector<u8>& state) override {
        if (state.size() >= (baseStateSize_ + 3)) {
            const auto endIt = state.begin() + static_cast<std::vector<u8>::difference_type>(baseStateSize_);
            std::vector<u8> baseState(state.begin(), endIt);
            base_->loadState(baseState);
            const std::size_t extOffset = baseStateSize_;
            huc3Mode_ = state[extOffset] != 0;
            command_ = static_cast<u8>(state[extOffset + 1] & 0x0F);
            huc3Value_ = static_cast<u8>(state[extOffset + 2] & 0x0F);
            return;
        }
        base_->loadState(state);
    }

private:
    std::unique_ptr<Mapper> base_{};
    std::size_t baseStateSize_ = 0;
    bool huc3Mode_ = false;
    u8 command_ = 0;
    u8 huc3Value_ = 0;
};

} // namespace

std::unique_ptr<Mapper> makeHuC3Mapper(std::vector<u8>& rom, std::vector<u8>& ram) {
    return std::make_unique<HuC3Mapper>(rom, ram);
}

} // namespace cartridge_mapper
} // namespace gb
