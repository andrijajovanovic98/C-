#include "text_replacer.hpp"

bool    safeInfileOpen(char **argv, std::ifstream& fileIn)
{
    fileIn.open(argv[1]);
    if (!fileIn)
    {
        std::cerr << argv[1] << std::endl;
        std::cerr << "Error: The file cant be opened" << std::endl;
        return (false);
    }
    return (true);
}
bool safeOutfileCreate(char **argv, std::ofstream& fileOut)
{
    std::string newFileName;

    newFileName = std::string(argv[1]) + ".replace";
    fileOut.open(newFileName.c_str());
    if (!fileOut)
    {
        std::cerr << "Error: The outfile creation failed." << std::endl;
        return (false);
    }
    return (true);
}
std::string    replacStr1ToStr2(char **argv, std::ifstream &fileIn)
{
    std::string line;

    std::string toOutFile;
    while (std::getline(fileIn, line))
    {
        size_t pos = 0;
        while ((pos = line.find(argv[2], pos)) != std::string::npos)
        {
            toOutFile += line.substr(0, pos);
            toOutFile += argv[3];
            line = line.substr(pos + std::string(argv[2]).length());
        }
        toOutFile += line;
        toOutFile += "\n";
        
    }
    return (toOutFile);
}
 