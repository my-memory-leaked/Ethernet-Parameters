/**
 * @file examples.cpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief Contains examples of usage of the library.
 * @version 0.1
 * @date 2023-05-23
 *
 * @note This software is licensed under the BSD 3-Clause License.
 *       SPDX-License-Identifier: BSD-3-Clause
 *
 * @copyright Copyright (c) 2023, Karol Pisarski
 *            All rights reserved.
 */
#include <iostream>
#include "IPv4Address/IPv4Address.hpp"

int main(int argc, char **argv) 
{
    //////////////////////////////////////////////////////////////////////////
    // IP v4 address usage examples.
    IPv4Address address;

    std::string input {};
    std::cout << "Enter an IPv4 address: ";
    std::cin >> input;

    address = IPv4Address(input);
    std::cout << "You entered: " << address << std::endl;


    // Comparison.
    IPv4Address ipv4Address1("192.168.0.1");
    IPv4Address ipv4Address2("192.168.0.2");

    std::cout << "Comparing addresses:" << std::endl;
    std::cout << "IP v4 address 1: " << ipv4Address1 << std::endl;
    std::cout << "IP v4 address 2: " << ipv4Address2 << std::endl;

    if (ipv4Address1 == ipv4Address2) 
    {
        std::cout << "Addresses are equal" << std::endl;
    } else 
    {
        std::cout << "Addresses are not equal" << std::endl;
    }
    //////////////////////////////////////////////////////////////////////////






    return 0;
}   /* int main() */
/******************************************************************************
**********************************End of file**********************************
******************************************************************************/