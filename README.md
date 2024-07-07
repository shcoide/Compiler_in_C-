# Simple Instruction-Based Interpreter

This project implements a simple instruction-based interpreter capable of performing arithmetic operations, handling conditional jumps, and executing loops. The interpreter reads instructions from a source file, parses them, and executes them in sequence.

## Features

- Basic arithmetic operations: `ADD`, `SUB`, `MUL`, `DIV`
- Stack operations: `PUSH`, `DUP`
- Conditional and unconditional jumps: `JUMP_IF_ZERO`, `JUMP_IF_NEGATIVE`, `JUMP`
- Input/Output: `INPUT`, `PRINT`
- Loop control: `LOOP_START`, `LOOP_END`
- Storage operations: `STORE`, `LOAD`

## File Structure

- `Parser.h` and `Parser.cpp`: Handle the parsing of instructions from the source file.
- `Interpreter.h` and `Interpreter.cpp`: Execute the parsed instructions.
- `Instruction.h`: Defines the structure of an instruction.
- `main.cpp`: Entry point of the program.

## Getting Started

### Prerequisites

Ensure you have a C++ compiler installed on your system. This project is compatible with GCC, Clang, or any other C++11 compatible compiler.

### Clone the Repository

```bash
git clone https://github.com/your-username/simple-interpreter.git
cd simple-interpreter
