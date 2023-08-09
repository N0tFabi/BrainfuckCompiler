# Brainfuck to C++ Compiler
This is a simple Brainfuck to C++ compiler written in C++. It converts Brainfuck code into C++ code that can be compiled and executed using a C++ compiler.

## Usage
Compile the program using a C++ compiler, and then you can run it from the command line. The program takes two or three command line arguments:

``` batch
.\BrainfuckCompiler.exe input.bf [output.cpp]
```

- <strong>input.bf</strong>: The path to the input Brainfuck code file.
- <strong>output.cpp</strong> (optional): The path to the output C++ code file. If not specified, the default filename "output.cpp" will be used.

The generated C++ code can be compiled using a C++ compiler to create an executable.

## How it Works
1. The program reads the Brainfuck code from the input file.
2. It converts the Brainfuck code into equivalent C++ code, where Brainfuck commands are translated into C++ code snippets that manipulate an array (tape) and its pointer.
3. The generated C++ code is saved to the specified output file (or "output.cpp" if not specified).

## Example
The file <strong>helloWorld.bf</strong>, located under ``\x86\Debug\`` contains a Brainfuck-Implementation of a program that prints "Hello, World!"

``` batch
.\BrainfuckCompiler.exe helloWorld.bf
```

This will create a new file <strong>output.cpp</strong> containing the C++ representation of the Brainfuck code.
