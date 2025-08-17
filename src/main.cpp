#include <iostream>
#include <string>

int main() {
    // auto-flush for cout/cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    std::string input;
    std::cout << "$ ";

    while (std::getline(std::cin, input)) {
        if (!input.empty()) {
            if (input == "exit 0") {
                return 0; 
            }
            std::cout << input << ": command not found" << std::endl;
        }
        std::cout << "$ ";
    }

    return 0;
}
