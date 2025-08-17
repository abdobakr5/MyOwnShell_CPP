#include <iostream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // Uncomment this block to pass the first stage
  std::cout << "$ ";
  bool repeat = true;
  while (repeat) {
    std::string input;
    std::getline(std::cin, input);
    if (input == "exit") {
      repeat = false;
    } else {
      std::cout << input << ": command not found" << std::endl;
      std::cout << "$ ";
    }
  }
}
