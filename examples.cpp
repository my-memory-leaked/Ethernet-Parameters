/**
 * @file examples.cpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief Contains examples of usage of the library.
 * @version 0.2
 * @date 2023-05-23
 *
 * @note This software is licensed under the BSD 3-Clause License.
 *       SPDX-License-Identifier: BSD-3-Clause
 *
 * @copyright Copyright (c) 2023, Karol Pisarski
 *            All rights reserved.
 */
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include "IPv4Address/IPv4Address.hpp"
#include "IPv6Address/IPv6Address.hpp"

int main(int argc, char **argv)
{
    //////////////////////////////////////////////////////////////////////////
    // IP v4 address usage examples.
    try
    {
        // Comparison.
        EthernetParameter::IPv4Address ipv4Address1("192.168.0.1");
        EthernetParameter::IPv4Address ipv4Address2("192.168.0.2");

        std::cout << "Comparing addresses:" << std::endl;
        std::cout << "IP v4 address 1: " << ipv4Address1 << std::endl;
        std::cout << "IP v4 address 2: " << ipv4Address2 << std::endl;

        if (ipv4Address1 == ipv4Address2)
        {
            std::cout << "Addresses are equal" << std::endl;
        }
        else
        {
            std::cout << "Addresses are not equal" << std::endl;
        }

        std::vector<unsigned char> binaryIpV4 = ipv4Address1.ToBinary();
        for (auto element : binaryIpV4)
        {
            std::cout << std::bitset<8>{element};
        }
        std::cout << std::endl;

        EthernetParameter::IPv4Address binaryIpV4Address(binaryIpV4);

        if (ipv4Address1 == binaryIpV4Address)
        {
            std::cout << "Binary for IPv4 conversion correct!" << std::endl;
        }
        else
        {
            std::cout << "Binary conversion for IPv4 error!" << std::endl;
        }
    }
    catch (const std::exception &ex)
    {
        std::cout << "Exception occurred: " << ex.what() << std::endl;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // IP v6 address usage examples.
    try
    {
        EthernetParameter::IPv6Address ipv6Address1;

        // Create an IPv6Address object with a binary content vector
        std::vector<uint8_t> binaryContent{0x20, 0x01, 0x0d, 0xb8, 0x85, 0xa3, 0x08, 0xd3, 0x13, 0x19, 0x86, 0x16, 0x08, 0x00, 0x27, 0x54};
        EthernetParameter::IPv6Address ipv6Address2(binaryContent);

        // Create an IPv6Address object with a string
        std::string addressString{"2001:0db8:85a3:08d3:1319:8a2e:0370:7334"};
        EthernetParameter::IPv6Address ipv6Address3(addressString);

        // Print out the IPv6 addresses
        std::cout << "IPv6 Address 1: " << ipv6Address1.ToString() << std::endl;
        std::cout << "IPv6 Address 2: " << ipv6Address2.ToString() << std::endl;
        std::cout << "IPv6 Address 3: " << ipv6Address3.ToString() << std::endl;

        // Comparison operators
        std::cout << "IPv6 Address 2 equals IPv6 Address 3: " << (ipv6Address2 == ipv6Address3 ? "true" : "false") << std::endl;
        std::cout << "IPv6 Address 1 not equals IPv6 Address 2: " << (ipv6Address1 != ipv6Address2 ? "true" : "false") << std::endl;

        // Binary content
        std::vector<uint8_t> binaryContent2 = ipv6Address3.ToBinary();
        uint8_t binaryArray[EthernetParameter::IPv6Address::IPV6_ADDRESS_BYTE_LENGTH]{};
        ipv6Address3.ToBinary(binaryArray);
    }
    catch (const std::exception &ex)
    {
        std::cout << "Exception occurred: " << ex.what() << std::endl;
    }

    //////////////////////////////////////////////////////////////////////////

    return 0;
} /* int main() */

/******************************************************************************
**********************************End of file**********************************
******************************************************************************/