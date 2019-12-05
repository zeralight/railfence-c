#ifndef COMMON_HPP
#define COMMON_HPP
#include <string>
#include <numeric>
#include <limits>
#include <cassert>
#include <vector>

using uint = unsigned;

inline bool parse_args(int argc, const char* const* argv, std::string& n, uint& d, uint& r) {
    if (argc != 7) return false;
    char flags[3][3] = {"-n", "-d", "-r"};
    bool found[] = {false, false, false};
    const char* values[] = {nullptr, nullptr, nullptr};

    for (int i = 1; i < argc; i += 2) {
        for (int j = 0; j < 3; ++j) {
            auto flag = flags[j];
            if (!strcmp(flag, argv[i])) {
                if (found[j]) return false;
                found[j] = true;
                values[j] = argv[i+1];
            }
        }
    }

    n = values[0];
    size_t pos;
    d = (uint) std::stol(values[1], &pos);
    if (pos != std::strlen(values[1])) return false;
    r = (uint) std::stol(values[2], &pos);
    if (pos != std::strlen(values[2])) return false;

    return true;
}


#endif