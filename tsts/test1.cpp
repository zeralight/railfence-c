#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <string>
#include <array>

using uint = unsigned;

int main() {
    const std::string plain = "CRYPTOLOGY IS THE PRACTICE AND STUDY OF TECHNIQUES FOR SECURE COMMUNICATION IN THE PRESENCE OF THIRD PARTIES CALLED ADVERSARIES.";
    const uint d = 4;
    const uint r = 5;
    const std::string command = std::string("./build/encryption") + " -n \"" + plain + "\" -d " +  std::to_string(d) + " -r " + std::to_string(r);
    
    FILE* f = popen(command.c_str(), "r");
    std::string output;
    std::array<char, 1024> buf;
    while (fgets(buf.data(), 1024, f))
        output += buf.data();

    std::cout << "Cipher(" << plain << ", " << d << ", " << r << ") = " << output << '\n';
}