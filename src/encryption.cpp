#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <set>
#include <sstream>
#include <cstdlib>
#include <regex>
#include <cassert>

#include "common.hpp"


static std::string make_a_round(const std::string&, std::vector<std::vector<char>>&);
static std::string encrypt(const std::string&, uint, uint);

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);

    std::string n;
    uint d;
    uint r;
    if (!parse_args(argc, argv, n, d, r)) {
        std::cerr << "USAGE: encryption -n \"message_to_encrypt\" -d cipher_depth -r repeat_times\n";
        std::exit(-1);
    }

    auto cipher = encrypt(n, d, r);
    std::cout << "'" << cipher << "'\n";
}

static std::string encrypt(const std::string& plain, uint d, uint r) {
    std::vector<std::vector<char>> table(d);
    for (auto& v: table) v.resize(plain.size());

    std::string res(std::move(plain));
    for (uint i = 0; i < r; ++i)
        res = make_a_round(res, table);

    return res;
}

static std::string make_a_round(const std::string& plain, std::vector<std::vector<char>>& table) {
    for (auto& v: table) std::fill(std::begin(v), std::end(v), 0);

    size_t i = 0, j = 0;
    int p = 1;
    for (char c: plain) {
        table[i][j] = c;
        ++j;
        if (table.size() > 1) {
            if (i+1 == table.size()) p = -1;
            else if (i == 0) p = 1;
            i += p;
        }
    }

    std::string res;
    for (const auto& v: table) {
        for (char c: v)
            if (0 != c) res += c;
    }

    return res;
}

