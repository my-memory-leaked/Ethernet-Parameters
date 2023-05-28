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
#include <string>
#include <vector>
#include <bitset>
#include "IPv4Address/IPv4Address.hpp"
#include "IPv6Address/IPv6Address.hpp"

int main(int argc, char **argv)
{
    //////////////////////////////////////////////////////////////////////////
    // IP v4 address usage examples.
    // Comparison.
    EthernetParameter::IPv4Address ipv4Address1("192.168.0.1");
    EthernetParameter::IPv4Address ipv4Address2("192.168.0.2");

    std::cout << "Comparing addresses:" << std::endl;
    std::cout << "IP v4 address 1: " << ipv4Address1 << std::endl;
    std::cout << "IP v4 address 2: " << ipv4Address2 << std::endl;

    ipv4Address1 == ipv4Address2 ? std::cout << "Addresses are equal" << std::endl :
                                   std::cout << "Addresses are not equal" << std::endl;

    std::vector<unsigned char> binaryIpV4 = ipv4Address1.ToBinary();
    for (auto element : binaryIpV4)
    {
        std::cout << std::bitset<8>{element};  
    }
    std::cout << std::endl;


    EthernetParameter::IPv4Address binaryIpV4Address(binaryIpV4);

    ipv4Address1 == binaryIpV4Address ? std::cout << "Binary for ip v4 conversion correct!" << std::endl :
                                        std::cout << "Binary conversion for ip v4 error!";

    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    // IP v6 address usage examples.
    std::string addressStr1 = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
    std::string addressStr2 = "2001:0db8:85a3:0000:0000:8a2e:0370:7334";
    std::string addressStr3 = "2001:0db8:85a3:0000:0000:8a2e:0370:7335";

    EthernetParameter::IPv6Address ipv6Address1(addressStr1);
    EthernetParameter::IPv6Address ipv6Address2(addressStr2);
    EthernetParameter::IPv6Address ipv6Address3(addressStr3);

    std::cout << "IPv6 address 1: " << ipv6Address1.ToString() << std::endl;
    std::cout << "IPv6 address 2: " << ipv6Address2 << std::endl;
    std::cout << "IPv6 address 3: " << ipv6Address2 << std::endl;

    ipv6Address1 == ipv6Address2 ? std::cout << std::hex << "IPv6 address 1 is equal to IPv6 address 2." << std::endl :
                                   std::cout << "IPv6 address 1 is not equal to IPv6 address 2." << std::endl;

    ipv6Address1 != ipv6Address3 ? std::cout << "IPv6 address 1 is not equal to IPv6 address 3." << std::endl :
                                   std::cout << "IPv6 address 1 is equal to IPv6 address 3.";

    
    // Print ipv6 binary data.
    std::vector<size_t> binaryIpV6 = ipv6Address1.ToBinary();
    for (auto i : binaryIpV6)
    {
        std::cout << std::bitset<8>{i};  
    }
    std::cout << std::endl;


    EthernetParameter::IPv6Address binaryIpV6Address(binaryIpV6);

    ipv6Address1 == binaryIpV6 ? std::cout << std::hex << "Binary conversion for ip v6 correct!" << std::endl :
                                 std::cout << "Binary conversion for ip v6 error!";
    //////////////////////////////////////////////////////////////////////////



    return 0;
} /* int main() */

/******************************************************************************
**********************************End of file**********************************
******************************************************************************/