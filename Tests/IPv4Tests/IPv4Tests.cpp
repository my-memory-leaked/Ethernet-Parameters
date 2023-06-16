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
#include "IPv4Address/IPv4Address.hpp"
#include "gtest/gtest.h"
#include <string>
#include <vector>
#include <sstream>

using namespace EthernetParameter;

// Test fixture for IPv4Address tests
class IPv4AddressTest : public ::testing::Test
{
protected:
    // Test data
    std::string validAddressStr = "192.168.0.1";
    std::vector<uint8_t> validBinaryAddress = {0b11000000, 0b10101000, 0b0, 0b00000001};

    EthernetParameter::IPv4Address validAddress;

    void SetUp() override
    {
        // Set up a valid IPv4Address object
        validAddress = EthernetParameter::IPv4Address(validAddressStr);
    }
};

// Test the default constructor
TEST_F(IPv4AddressTest, DefaultConstructor)
{
    EthernetParameter::IPv4Address address;
    // Add assertions to test the default constructor behavior
    // For example, you can check that all octets are initialized to 0
    ASSERT_EQ(address.GetOctet(0), 0);
    ASSERT_EQ(address.GetOctet(1), 0);
    ASSERT_EQ(address.GetOctet(2), 0);
    ASSERT_EQ(address.GetOctet(3), 0);
}

// Test the constructor that accepts a string representation of an IPv4 address
TEST_F(IPv4AddressTest, StringConstructor)
{
    // Add assertions to test the string constructor behavior
    EthernetParameter::IPv4Address ipStrAddr("192.168.0.1");
    ASSERT_EQ(ipStrAddr, validAddress);
}

// Test the constructor that accepts four octets as separate parameters
TEST_F(IPv4AddressTest, FourOctetConstructor)
{
    // Create an IPv4Address object using the constructor
    EthernetParameter::IPv4Address address(192, 168, 0, 1);
    // Add assertions to test the four octet constructor behavior
    ASSERT_EQ(address.GetOctet(0), 192);
    ASSERT_EQ(address.GetOctet(1), 168);
    ASSERT_EQ(address.GetOctet(2), 0);
    ASSERT_EQ(address.GetOctet(3), 1);
}

// Test the constructor that accepts binary data
TEST_F(IPv4AddressTest, BinaryConstructor)
{
    // Create an IPv4Address object using the constructor
    EthernetParameter::IPv4Address address(validBinaryAddress);
    // Add assertions to test the binary constructor behavior
    ASSERT_EQ(address.GetOctet(0), 0b11000000);
    ASSERT_EQ(address.GetOctet(1), 0b10101000);
    ASSERT_EQ(address.GetOctet(2), 0b0);
    ASSERT_EQ(address.GetOctet(3), 0b00000001);
}

// Test the ToString() method
TEST_F(IPv4AddressTest, ToString)
{
    // Add assertions to test the ToString() method
    ASSERT_EQ(validAddress.ToString(), validAddressStr);
}

// Test the ToBinary() method
TEST_F(IPv4AddressTest, ToBinary)
{
    // Add assertions to test the ToBinary() method
    ASSERT_EQ(validAddress.ToBinary(), validBinaryAddress);
}

// Test the Clear() method
TEST_F(IPv4AddressTest, Clear)
{
    // Call the Clear() method
    validAddress.Clear();
    // Add assertions to test the Clear() method
    ASSERT_EQ(validAddress.GetOctet(0), 0);
    ASSERT_EQ(validAddress.GetOctet(1), 0);
    ASSERT_EQ(validAddress.GetOctet(2), 0);
    ASSERT_EQ(validAddress.GetOctet(3), 0);
}

// Test the equality operator (==)
TEST_F(IPv4AddressTest, EqualityOperator)
{
    // Create a new IPv4Address object with the same address
    EthernetParameter::IPv4Address equalAddress(validAddressStr);
    // Create a different IPv4Address object with a different address
    EthernetParameter::IPv4Address differentAddress("10.0.0.1");

    // Add assertions to test the equality operator
    ASSERT_EQ(validAddress, equalAddress);     // The addresses should be equal
    ASSERT_NE(validAddress, differentAddress); // The addresses should be different
}

// Test the inequality operator (!=)
TEST_F(IPv4AddressTest, InequalityOperator)
{
    // Create a new IPv4Address object with the same address
    EthernetParameter::IPv4Address equalAddress(validAddressStr);
    // Create a different IPv4Address object with a different address
    EthernetParameter::IPv4Address differentAddress("10.0.0.1");

    // Add assertions to test the inequality operator
    ASSERT_NE(validAddress, differentAddress);      // The addresses should be different
    ASSERT_EQ(validAddress != equalAddress, false); // The addresses should be equal
}

// Test the assignment operator (=)
TEST_F(IPv4AddressTest, AssignmentOperator)
{
    // Create a new IPv4Address object
    EthernetParameter::IPv4Address address;
    // Assign the validAddress to the new object
    address = validAddress;

    // Add assertions to test the assignment operator
    ASSERT_EQ(address, validAddress); // The addresses should be equal
}

// Test the copy constructor
TEST_F(IPv4AddressTest, CopyConstructor)
{
    // Create a new IPv4Address object using the copy constructor
    EthernetParameter::IPv4Address address(validAddress);

    // Add assertions to test the copy constructor
    ASSERT_EQ(address, validAddress); // The addresses should be equal
}

// Test the GetOctet() method
TEST_F(IPv4AddressTest, GetOctet)
{
    // Add assertions to test the GetOctet() method
    ASSERT_EQ(validAddress.GetOctet(0), 192);
    ASSERT_EQ(validAddress.GetOctet(1), 168);
    ASSERT_EQ(validAddress.GetOctet(2), 0);
    ASSERT_EQ(validAddress.GetOctet(3), 1);
}

// Test the SetOctet() method
TEST_F(IPv4AddressTest, SetOctet)
{
    // Set the octets to new values
    validAddress.SetOctet(0, 10);
    validAddress.SetOctet(1, 20);
    validAddress.SetOctet(2, 30);
    validAddress.SetOctet(3, 40);

    // Add assertions to test the SetOctet() method
    ASSERT_EQ(validAddress.GetOctet(0), 10);
    ASSERT_EQ(validAddress.GetOctet(1), 20);
    ASSERT_EQ(validAddress.GetOctet(2), 30);
    ASSERT_EQ(validAddress.GetOctet(3), 40);
}
// Test the output operator (<<)
TEST_F(IPv4AddressTest, OutputOperator)
{
    std::ostringstream oss;
    oss << validAddress;
    // Add assertions to test the output operator
    ASSERT_EQ(oss.str(), validAddressStr);
}
/******************************************************************************
**********************************End of file**********************************
******************************************************************************/