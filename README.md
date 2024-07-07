# Simple Compiler in CPP

This project implements a simple instruction-based interpreter or compiler in CPP capable of performing arithmetic operations, handling conditional jumps, and executing loops. The interpreter reads instructions from a source file, parses them, and executes them in sequence.

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
- `test.txt`: Write the code here as per instruction

## Getting Started

### Prerequisites

Ensure you have a C++ compiler installed on your system. This project is compatible with GCC, Clang, or any other C++11 compatible compiler.

### Clone the Repository

```bash
git clone https://github.com/shcoide/Compiler_in_Cpp.git
cd Compiler_in_Cpp
```
### Compile and Run the compiler

```bash
g++ main.cpp Parser.cpp Interpreter.cpp -o mycompiler
./mycompiler test.txt
```
### Writing code

The simple code can be written in test.txt file by using the templete given

- `ADD`: Adds the top two values on the stack.
- `SUB`: Subtracts the top two values on the stack.
- `MUL`: Multiplies the top two values on the stack.
- `DIV`: Divides the top two values on the stack (error if division by zero).
- `PUSH <value>`: Pushes a value onto the stack.
- `DUP`: Duplicates the top value on the stack.
- `INPUT <prompt>`: Prompts the user for input and pushes the entered value onto the stack.
- `PRINT`: Prints the top value on the stack and removes it.
- `JUMP <label>`: Jumps to the specified label unconditionally.
- `JUMP_IF_ZERO <label>`: Jumps to the specified label if the top value on the stack is zero.
- `JUMP_IF_NEGATIVE <label>`: Jumps to the specified label if the top value on the stack is negative.
- `LABEL <name>`: Defines a label.
- `LOOP_START <label>`: Defines the start of a loop.
- `LOOP_END <label>`: Defines the end of a loop and jumps back to the specified label.
- `STORE <name>`: Stores the top value on the stack in a variable.
- `LOAD <name>`: Loads the value of a variable onto the stack.
