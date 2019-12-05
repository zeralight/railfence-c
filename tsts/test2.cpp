#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>
#include <array>

using uint = unsigned;

int main() {
    const std::string cipher = "TAOTINEN KAT I ODIOAEI OHHLSCTE TTETOEL BI IHI GAO   EPSEA TO SS  EEK  ELRCPTSIY EANRPHMCYEK E CREAAIEJURTE  IEASHI MA DRN RH  "
                               "AUWTA RF EFTFHENTPSF Q   TAILB E TTECAPMSIYIY SRPURNTBL YCL OANAO  E  TVREAOSHOTTNULSRHK";
    const uint d = 3;
    const uint r = 3;
    const std::string command = std::string("./build/decryption") + " -n \"" + cipher + "\" -d " +  std::to_string(d) + " -r " + std::to_string(r);
    
    FILE* f = popen(command.c_str(), "r");
    std::string output;
    std::array<char, 1024> buf;
    while (fgets(buf.data(), 1024, f))
        output += buf.data();

    std::cout << "Decrypt(" << cipher << ", " << d << ", " << r << ") = " << output << '\n';
}