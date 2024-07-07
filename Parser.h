#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include "Instruction.h"

class Parser {
public:
    std::vector<Instruction> parse(const std::string& source);
};

#endif
