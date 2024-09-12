#include "text_replacer.hpp"

int main(int argc, char **argv)
{
    std::ifstream fileIn;
    std::ofstream fileOut;
    if (argc < 4 || !*argv[2] || !*argv[3])
    {
        std::cerr << "| <filename> <replacable text> <replace text> |" << std::endl;
        return (1);
    }
    if (!safeInfileOpen(argv, fileIn))
        return (1);

    if (!safeOutfileCreate(argv, fileOut))
        return (1);
    fileOut << replacStr1ToStr2(argv, fileIn);

    fileIn.close();
    fileOut.close();
    return (0);
}
