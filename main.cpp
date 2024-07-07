#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Interpreter.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <source file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << argv[1] << std::endl;
        return 1;
    }

    std::string line;
    std::string source;
    while (std::getline(file, line)) {
        source += line + "\n";
    }
    file.close();

    Parser parser;
    std::vector<Instruction> instructions = parser.parse(source);

    Interpreter interpreter;
    interpreter.run(instructions);

    return 0;
}
