#include "Interpreter.h"
#include <iostream>
#include <stack>
#include <unordered_map>
#include <map>

void Interpreter::run(const std::vector<Instruction>& instructions) {
    std::stack<int> stack;
    std::unordered_map<std::string, int> labelMap;
    std::map<std::string, int> storage;
    int pc = 0; // Program counter

    // First pass to map labels
    for (int i = 0; i < instructions.size(); ++i) {
        if (instructions[i].opcode == "LABEL") {
            labelMap[instructions[i].operand] = i;
        }
    }

    while (pc < instructions.size()) {
        const auto& instr = instructions[pc];
        // std::cout << "Executing: " << instr.opcode << " " << instr.operand << std::endl;

        if (instr.opcode == "PUSH") {
            stack.push(std::stoi(instr.operand));
        } else if (instr.opcode == "INPUT") {
            int value;
            std::cout << instr.operand;
            std::cin >> value;
            stack.push(value);
        } else if (instr.opcode == "ADD") {
            if (stack.size() < 2) {
                std::cerr << "Error: Not enough operands for ADD" << std::endl;
            } else {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a + b);
            }
        } else if (instr.opcode == "SUB") {
            if (stack.size() < 2) {
                std::cerr << "Error: Not enough operands for SUB" << std::endl;
            } else {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a - b);
            }
        } else if (instr.opcode == "MUL") {
            if (stack.size() < 2) {
                std::cerr << "Error: Not enough operands for MUL" << std::endl;
            } else {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a * b);
            }
        } else if (instr.opcode == "DIV") {
            if (stack.size() < 2) {
                std::cerr << "Error: Not enough operands for DIV" << std::endl;
            } else {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                if (b == 0) {
                    std::cerr << "Error: Division by zero" << std::endl;
                } else {
                    stack.push(a / b);
                }
            }
        } else if (instr.opcode == "PRINT") {
            if (!stack.empty()) {
                std::cout << stack.top() << std::endl;
                stack.pop();
            } else {
                std::cerr << "Error: Stack is empty, cannot PRINT" << std::endl;
            }
        } else if (instr.opcode == "JUMP_IF_ZERO") {
            if (stack.empty()) {
                std::cerr << "Error: Stack is empty, cannot JUMP_IF_ZERO" << std::endl;
            } else {
                int value = stack.top(); stack.pop();
                if (value == 0) {
                    pc = labelMap[instr.operand];
                    continue;
                }
            }
        } else if (instr.opcode == "JUMP") {
            pc = labelMap[instr.operand];
            continue;
        } else if (instr.opcode == "LABEL") {
            // Do nothing, labels are handled in the first pass
        } else if (instr.opcode == "STORE") {
            if (stack.empty()) {
                std::cerr << "Error: Stack is empty, cannot STORE" << std::endl;
            } else {
                int value = stack.top(); stack.pop();
                storage[instr.operand] = value;
            }
        } else if (instr.opcode == "LOAD") {
            if (storage.find(instr.operand) == storage.end()) {
                std::cerr << "Error: Variable not found, cannot LOAD" << std::endl;
            } else {
                stack.push(storage[instr.operand]);
            }
        } else if (instr.opcode == "DUP") {
            if (stack.empty()) {
                std::cerr << "Error: Stack is empty, cannot DUP" << std::endl;
            } else {
                stack.push(stack.top());
            }
        } else if (instr.opcode == "SUBTRACT") {
            if (stack.size() < 2) {
                std::cerr << "Error: Not enough operands for SUBTRACT" << std::endl;
            } else {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();
                stack.push(a - b);
            }
        } else if (instr.opcode == "JUMP_IF_NEGATIVE") {
            if (stack.empty()) {
                std::cerr << "Error: Stack is empty, cannot JUMP_IF_NEGATIVE" << std::endl;
            } else {
                int value = stack.top(); stack.pop();
                if (value < 0) {
                    pc = labelMap[instr.operand];
                    continue;
                }
            }
        } else if (instr.opcode == "LOOP_START") {
            // Do nothing for now, handled in conditional loops
        } else if (instr.opcode == "LOOP_END") {
            pc = labelMap[instr.operand] - 1; // Jump back to the start of the loop
        } else if (instr.opcode == "END") {
            break;
        } else {
            std::cerr << "Unknown instruction: " << instr.opcode << std::endl;
        }

        pc++;
    }
}
