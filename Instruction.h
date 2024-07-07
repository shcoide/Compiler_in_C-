#pragma once

#include <string>

class Instruction {
public:
    std::string opcode;
    std::string operand;

    Instruction(const std::string& op, const std::string& val) : opcode(op), operand(val) {}
};
