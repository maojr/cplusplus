#include <new>
#include <cstdlib>
#include <iostream>

void no_memory()
{
    std::cout << "Failed to allocate memory!\n";
    std::exit(1);
}

int main(int argc, char const *argv[])
{
    std::set_new_handler(no_memory);
    std::cout << "Attempting to allocate...";
    char* p= new char[9999999999999999];
    std::cout << "Ok\n";
    delete[] p;
    return 0;
}