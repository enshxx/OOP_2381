#ifndef Input_h
#define Input_h
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>
class Input
{
    public:
    char _getch();
    char _read();
    std::map<std::string, char> read_dictionary(const std::string& filename);
};
#endif