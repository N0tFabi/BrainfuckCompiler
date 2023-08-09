#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <array>

std::string bfToC(const std::string& bf) {
    std::string c = R"(
#include <iostream>
using namespace std;

int main() {
    unsigned char tape[30000] = {0};
    unsigned char* ptr = tape;
)";

    int indentationLevel = 1;

    for (char bfChar : bf) {
        switch (bfChar) {
        case '>': c += std::string(indentationLevel * 4, ' ') + "++ptr;\n"; break;
        case '<': c += std::string(indentationLevel * 4, ' ') + "--ptr;\n"; break;
        case '+': c += std::string(indentationLevel * 4, ' ') + "++(*ptr);\n"; break;
        case '-': c += std::string(indentationLevel * 4, ' ') + "--(*ptr);\n"; break;
        case '.': c += std::string(indentationLevel * 4, ' ') + "putchar(*ptr);\n"; break;
        case ',': c += std::string(indentationLevel * 4, ' ') + "*ptr = getchar();\n"; break;
        case '[':
            c += std::string(indentationLevel * 4, ' ') + "while (*ptr) {\n";
            indentationLevel++;
            break;
        case ']':
            indentationLevel--;
            c += std::string(indentationLevel * 4, ' ') + "}\n";
            break;
        default: break;
        }
    }

    c += R"(
    return 0;
}
    )";
    return c;
}

int main(int argc, char** argv) {
    if (argc < 2 || argc > 3) {
        std::cout << "Usage: " << argv[0] << " input.bf [output.cpp]" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    std::string bfCode((std::istreambuf_iterator<char>(inputFile)),
        std::istreambuf_iterator<char>());

    inputFile.close();

    std::string cCode = bfToC(bfCode);

    std::string outputFilename = "output.cpp";
    if (argc == 3) {
        outputFilename = argv[2];
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    outputFile.clear();
    outputFile << cCode;
    outputFile.close();

    std::cout << "Compilation successful. C++ code saved as " << outputFilename << std::endl;
    return 0;
}