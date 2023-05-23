#include <iostream>
#include "IPv4Address/IPv4Address.hpp"

int main(int argc, char **argv) 
{
    IPv4Address ip("192.168.1.0");

    // Ostream operator.
    std::cout << ip << std::endl;    

    return 0;
}
