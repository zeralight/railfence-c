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
static std::string decrypt(const std::string&, uint, uint);


int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(false);

    std::string n;
    uint d;
    uint r;
    if (!parse_args(argc, argv, n, d, r)) {
        std::cerr << "USAGE: encryption -n \"message_to_decrypt\" -d cipher_depth -r repeat_times\n";
        std::exit(-1);
    }

    auto cipher = decrypt(n, d, r);
    std::cout << "'" << cipher << "'\n";
}

static std::string decrypt(const std::string& cipher, uint d, uint r) {
    std::vector<std::vector<char>> table(d);
    for (auto& v: table) v.resize(cipher.size());

    std::string res = std::move(cipher);
    for (uint _ = 0; _ < r; ++_)
        res = make_a_round(res, table);
    
    return res;
}

static std::string make_a_round(const std::string& cipher, std::vector<std::vector<char>>& table) {
    for (auto& v: table) std::fill(std::begin(v), std::end(v), 0);

    size_t i = 0, j = 0;
    int p = 1;
    for (size_t _ = 0; _ < cipher.size(); ++_) {
        table[i][j] = 1;
        ++j;
        if (table.size() > 1) {
            if (i+1 == table.size()) p = -1;
            else if (i == 0) p = 1;
            i += p;
        }
    }

    size_t n = 0;
    for (auto& v: table) {
        for (char& c: v)
            if (c == 1) c = cipher[n++];
    }

    std::string res;
    res.resize(cipher.size());
    i = 0, j = 0;
    p = 1;
    for (char& c: res) {
        if (0 != table[i][j]) c = table[i][j];
        ++j;
        if (table.size() > 1) {
            if (i+1 == table.size()) p = -1;
            else if (i == 0) p = 1;
            i += p;
        }
    }

    return res;
}

