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
            
            // exit
            if (input == "exit 0") {
                return 0; 
            }

            // echo
            if (input.rfind("echo", 0) == 0) {
                if (input.size() > 5) {
                    std::cout << input.substr(5) << std::endl;
                } else {
                    std::cout << std::endl;
                }
                std::cout << "$ ";
                continue;
            }

            // type
            if (input.rfind("type", 0) == 0) {
                if (input.size() > 5) {
                    std::string arg = input.substr(5);

                    if (arg == "echo") {
                        std::cout << "echo is a shell builtin" << std::endl;
                    } else if (arg == "type") {
                        std::cout << "type is a shell builtin" << std::endl;
                    } else if (arg == "exit") {
                        std::cout << "exit is a shell builtin" << std::endl;
                    } else {
                        std::cout << arg << ": not found" << std::endl;
                    }
                } else {
                    std::cout << "type: missing argument" << std::endl;
                }
                std::cout << "$ ";
                continue;
            }

            // unknown
            std::cout << input << ": command not found" << std::endl;
        }

        std::cout << "$ ";
    }

    return 0;
}
