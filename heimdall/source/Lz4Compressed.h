#include <cstring>
#include <cstdint>
#include <cstdio>

bool isLz4Compressed(FILE* file) {
    std::uint8_t buffer[4];
    if (fread(buffer, 1, sizeof(buffer), file) != sizeof(buffer)) {
        return false;
    }

    std::uint8_t lz4_standard[] = {0x04, 0x22, 0x4D, 0x18};
    std::uint8_t lz4_legacy[] = {0x02, 0x21, 0x4C, 0x18};

    if (std::memcmp(buffer, lz4_standard, sizeof(buffer)) == 0 || std::memcmp(buffer, lz4_legacy, sizeof(buffer)) == 0) {
        return true;
    }
    return false;
}
