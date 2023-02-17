#include <iostream>

#include "header.hpp"
#include "slang.hpp"

int main() {
    std::cout << "Hello, World!" << hello() << std::endl;
    while (true) {
        auto token = yylex();
        //std::cout << "Read: " << token << std::endl;
    }
    return 0;
}