#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <vector>
#include "Instruction.h"

class Interpreter {
public:
    void run(const std::vector<Instruction>& instructions);
};

#endif
