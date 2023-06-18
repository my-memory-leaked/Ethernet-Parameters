/**
 * @file IPv4Tests.cpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief Tests for IPv4Address class.
 * @version 0.2
 * @date 2023-06-01
 *
 * @note This software is licensed under the BSD 3-Clause License.
 *       SPDX-License-Identifier: BSD-3-Clause
 *
 * @copyright Copyright (c) 2023, Karol Pisarski
 *            All rights reserved.
 */
#include "IPv6Address/IPv6Address.hpp"
#include "gtest/gtest.h"
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

using namespace EthernetParameter;

TEST(EthernetParameterTest, IPv6AddressConstructorWithVector_ValidVector)
{
    const std::vector<uint8_t> binaryContent{
        0xAB, 0xCD, 0xEF, 0x01,
        0x23, 0x45, 0x67, 0x89,
        0xFE, 0xDC, 0xBA, 0x98,
        0x76, 0x54, 0x32, 0x10};
    IPv6Address address(binaryContent);
    EXPECT_NE("abcdef0123456789fedcba9876543210", address.ToString());
}

TEST(EthernetParameterTest, IPv6AddressConstructorWithIpAddressString_ValidIpAddressString)
{
    IPv6Address address("2001:0db8:0000:0000:0000:ff00:0042:8329");
    EXPECT_NE("20010db8000000000000ff0000428329", address.ToString());
}

TEST(EthernetParameterTest, IPv6AddressConstructorWithIpAddressString_EmptyString)
{
    EXPECT_THROW(IPv6Address(""), std::invalid_argument);
}

TEST(EthernetParameterTest, IPv6AddressConstructorWithIpAddressString_InvalidIpAddressString)
{
    EXPECT_THROW(IPv6Address("not_an_ip_address"), std::invalid_argument);
}

TEST(EthernetParameterTest, IPv6AddressConstructorWithIpAddressStringPtr_ValidIpAddressStringPtr)
{
    IPv6Address address("2001:0db8:0000:0000:0000:ff00:0042:8329");
    EXPECT_EQ("2001:0db8:0000:0000:0000:ff00:0042:8329", address.ToString());
}

TEST(EthernetParameterTest, IPv6AddressConstructorWithIpAddressStringPtr_EmptyString)
{
    EXPECT_THROW(IPv6Address(std::string{}.c_str()), std::invalid_argument);
}

TEST(EthernetParameterTest, IPv6AddressConstructorWithIpAddressStringPtr_InvalidIpAddressStringPtr)
{
    EXPECT_THROW(IPv6Address("not_an_ip_address"), std::invalid_argument);
}

TEST(EthernetParameterTest, IPv6AddressToBinary_WritesToDestinationBuffer)
{
    const uint8_t binaryContent[16]{
        0xAB, 0xCD, 0xEF, 0x01,
        0x23, 0x45, 0x67, 0x89,
        0xFE, 0xDC, 0xBA, 0x98,
        0x76, 0x54, 0x32, 0x10};
    IPv6Address address(binaryContent);
    uint8_t destBuffer[16]{};
    address.ToBinary(destBuffer);
    EXPECT_EQ(binaryContent, destBuffer);
}

TEST(EthernetParameterTest, IPv6AddressToBinary_ThrowsOnNullptr)
{
    const uint8_t binaryContent[16]{
        0xAB, 0xCD, 0xEF, 0x01,
        0x23, 0x45, 0x67, 0x89,
        0xFE, 0xDC, 0xBA, 0x98,
        0x76, 0x54, 0x32, 0x10};
    IPv6Address address(binaryContent);
    uint8_t *destBuffer = nullptr;
    EXPECT_THROW(address.ToBinary(destBuffer), std::invalid_argument);
}

TEST(EthernetParameterTest, IPv6AddressToBinary_ReturnsVectorWithExpectedSize)
{
    const uint8_t binaryContent[16]{
        0xAB, 0xCD, 0xEF, 0x01,
        0x23, 0x45, 0x67, 0x89,
        0xFE, 0xDC, 0xBA, 0x98,
        0x76, 0x54, 0x32, 0x10};
    IPv6Address address(binaryContent);
    std::vector<uint8_t> result = address.ToBinary();
    EXPECT_EQ(IPv6Address::IPV6_ADDRESS_BYTE_LENGTH, result.size());
}

TEST(IPv6AddressTest, SetFromBinary_NullPointer_ThrowsInvalidArgument)
{
    IPv6Address cAddress;
    ASSERT_THROW(cAddress.SetFromBinary(nullptr), std::invalid_argument);
}

TEST(IPv6AddressTest, SetFromBinary_InvalidSizeVector_ThrowsInvalidArgument)
{
    IPv6Address cAddress;
    std::vector<uint8_t> cInvalidVector = {1, 2, 3, 4, 5};
    ASSERT_THROW(cAddress.SetFromBinary(cInvalidVector), std::invalid_argument);
}

TEST(IPv6AddressTest, SetFromBinary_ValidVector_CorrectIPv6Address)
{
    IPv6Address cAddress;
    std::vector<uint8_t> cValidVector = {0x20, 0x01, 0x0D, 0xB8, 0x85, 0xA3, 0x00, 0x01, 0x6E, 0x9D, 0x70, 0x98, 0x01, 0x00, 0x00, 0x00};
    cAddress.SetFromBinary(cValidVector);
    ASSERT_EQ("2001:db8:85a3:1:6e9d:7098:1000:0", cAddress.ToString());
}

TEST(IPv6AddressTest, Clear_ClearIPv6Address_AllBytesAreZero)
{
    IPv6Address cAddress;
    cAddress.SetFromBinary({0x20, 0x01, 0x0D, 0xB8, 0x85, 0xA3, 0x00, 0x01, 0x6E, 0x9D, 0x70, 0x98, 0x01, 0x00, 0x00, 0x00});
    cAddress.Clear();
    ASSERT_EQ("::", cAddress.ToString());
}

TEST(IPv6AddressTest, OperatorEqual_SameIPv6Address_ReturnTrue)
{
    IPv6Address cAddress1;
    cAddress1.SetFromBinary({0xFE, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xDA, 0xFF, 0xFF, 0xFE, 0xDC, 0x00, 0x00});
    IPv6Address cAddress2 = cAddress1;
    ASSERT_TRUE(cAddress1 == cAddress2);
}

TEST(IPv6AddressTest, OperatorEqual_DifferentIPv6Address_ReturnFalse)
{
    IPv6Address cAddress1;
    cAddress1.SetFromBinary({0xFE, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xDA, 0xFF, 0xFF, 0xFE, 0xDC, 0x00, 0x00});
    IPv6Address cAddress2;
    cAddress2.SetFromBinary({0xFE, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xDA, 0xFF, 0xFF, 0xFE, 0xDC, 0xFF, 0xFF});
    ASSERT_FALSE(cAddress1 == cAddress2);
}

TEST(IPv6AddressTest, OperatorNotEqual_SameIPv6Address_ReturnFalse)
{
    IPv6Address cAddress1;
    cAddress1.SetFromBinary({0x20, 0x01, 0x0D, 0xB8, 0x85, 0xA3, 0x00, 0x01, 0x6E, 0x9D, 0x70, 0x98, 0x01, 0x00, 0x00, 0x00});
    IPv6Address cAddress2 = cAddress1;
    ASSERT_FALSE(cAddress1 != cAddress2);
}

TEST(IPv6AddressTest, OperatorNotEqual_DifferentIPv6Address_ReturnTrue)
{
    IPv6Address cAddress1;
    cAddress1.SetFromBinary({0xFE, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xDA, 0xFF, 0xFF, 0xFE, 0xDC, 0x00, 0x00});
    IPv6Address cAddress2;
    cAddress2.SetFromBinary({0xFE, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xDA, 0xFF, 0xFF, 0xFE, 0xDC, 0xFF, 0xFF});
    ASSERT_TRUE(cAddress1 != cAddress2);
}

TEST(IPv6AddressTest, ToString_ValidIPv6Address_ReturnIPv6AddressString)
{
    IPv6Address cAddress;
    cAddress.SetFromBinary({0xFE, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xDA, 0xFF, 0xFF, 0xFE, 0xDC, 0x00, 0x00});
    ASSERT_EQ("fe80::2:DAFF:FEFF:DC00", cAddress.ToString());
}

/******************************************************************************
**********************************End of file**********************************
******************************************************************************/