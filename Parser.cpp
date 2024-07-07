#include "Parser.h"
#include <sstream>
#include <iostream>

std::vector<Instruction> Parser::parse(const std::string& source) {
    std::vector<Instruction> instructions;
    std::istringstream stream(source);
    std::string line;

    while (std::getline(stream, line)) {
        std::istringstream linestream(line);
        std::string opcode;
        linestream >> opcode;

        if (opcode == "PUSH" || opcode == "INPUT" || opcode == "JUMP_IF_ZERO" || opcode == "JUMP" || 
            opcode == "LABEL" || opcode == "STORE" || opcode == "LOAD" || opcode == "DUP" ||
            opcode == "SUBTRACT" || opcode == "JUMP_IF_NEGATIVE") {
            std::string value;
            linestream >> std::ws;
            std::getline(linestream, value);
            instructions.push_back(Instruction(opcode, value));
        } else if (opcode == "ADD" || opcode == "SUB" || opcode == "MUL" || opcode == "DIV" || 
                   opcode == "PRINT" || opcode == "END" || opcode == "LOOP_START" || opcode == "LOOP_END") {
            instructions.push_back(Instruction(opcode, ""));
        } else {
            std::cerr << "Unknown instruction: " << opcode << std::endl;
        }
    }

    return instructions;
}
