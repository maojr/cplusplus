// H3C interview:
// Write a program to append 100 random number, seperated by a space to 'rand.txt' file,
// if file not exist, create that file. The read the file and output the numbers.

#include <stdlib.h>

#include <fstream>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::ofstream out;
    out.open("rand.txt", std::ios::app);
    for (int i = 0; i < 100; ++i)
        out << rand() << " ";
    out.close(); //flush the output

    std::ifstream in;
    in.open("rand.txt", std::ios::in);
    if (!in.is_open()) {
        std::cout << "Error open file!" << std::endl;
        return -1;
    }
    while (!in.eof()) {
        int rand;
        in >> rand;
        std::cout << rand << std::endl;
    }

    return 0;
}
