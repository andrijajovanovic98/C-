#ifndef TEXT_REPLACER_HPP
#define TEXT_REPLACER_HPP

#include <iostream>
#include <fstream>
#include <sstream>

bool        safeInfileOpen(char **argv, std::ifstream& fileIn);
bool        safeOutfileCreate(char **argv, std::ofstream& fileOut);
std::string replacStr1ToStr2(char **argv, std::ifstream &fileIn);

#endif