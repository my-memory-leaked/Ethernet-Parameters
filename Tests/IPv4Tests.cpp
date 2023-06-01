/**
 * @file IPv4Tests.cpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief Tests for IPv4Address class.
 * @version 0.1
 * @date 2023-06-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "IPv4Address/IPv4Address.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <sstream>

using namespace EthernetParameter;

// Test fixture for IPv4Address tests
class IPv4AddressTest : public testing::Test
{
protected:
    // Helper function to compare two IPv4 addresses
    bool CompareIPv4Addresses(const IPv4Address &address1, const IPv4Address &address2)
    {
        for (uint8_t i = 0; i < IPv4Address::IP_ADDRESS_OCTETS; i++)
        {
            if (address1.GetOctet(i) != address2.GetOctet(i))
                return false;
        }
        return true;
    }
};

// Test default constructor
TEST_F(IPv4AddressTest, DefaultConstructor)
{
    IPv4Address address;
    for (uint8_t i = 0; i < IPv4Address::IP_ADDRESS_OCTETS; i++)
    {
        EXPECT_EQ(address.GetOctet(i), 0);
    }
}

// Test constructor with string representation
TEST_F(IPv4AddressTest, StringConstructor)
{
    std::string addressStr = "192.168.0.1";
    IPv4Address address(addressStr);
    EXPECT_TRUE(address == IPv4Address(192, 168, 0, 1));
}

// Test constructor with separate octets
TEST_F(IPv4AddressTest, SeparateOctetsConstructor)
{
    IPv4Address address(192, 168, 0, 1);
    EXPECT_TRUE(CompareIPv4Addresses(address, IPv4Address("192.168.0.1")));
}

// Test constructor with binary address
TEST_F(IPv4AddressTest, BinaryAddressConstructor)
{
    std::vector<uint8_t> binaryAddress = {192, 168, 0, 1};
    IPv4Address address(binaryAddress);
    EXPECT_TRUE(CompareIPv4Addresses(address, IPv4Address("192.168.0.1")));
}

// Test ToString method
TEST_F(IPv4AddressTest, ToString)
{
    IPv4Address address("192.168.0.1");
    EXPECT_EQ(address.ToString(), "192.168.0.1");
}

// Test ToBinary method
TEST_F(IPv4AddressTest, ToBinary)
{
    IPv4Address address("192.168.0.1");
    std::vector<uint8_t> binaryAddress = address.ToBinary();
    EXPECT_EQ(binaryAddress, std::vector<uint8_t>({192, 168, 0, 1}));
}

// Test Clear method
TEST_F(IPv4AddressTest, Clear)
{
    IPv4Address address("192.168.0.1");
    address.Clear();
    for (uint8_t i = 0; i < IPv4Address::IP_ADDRESS_OCTETS; i++)
    {
        EXPECT_EQ(address.GetOctet(i), 0);
    }
}

// Test equality operator
TEST_F(IPv4AddressTest, EqualityOperator)
{
    IPv4Address address1("192.168.0.1");
    IPv4Address address2("192.168.0.1");
    EXPECT_EQ(address1, address2);
}

// Test inequality operator
TEST_F(IPv4AddressTest, InequalityOperator)
{
    IPv4Address address1("192.168.0.1");
    IPv4Address address2("192.168.0.2");
    EXPECT_NE(address1, address2);
}

// Test assignment operator
TEST_F(IPv4AddressTest, AssignmentOperator)
{
    IPv4Address address1("192.168.0.1");
    IPv4Address address2;
    address2 = address1;
    EXPECT_EQ(address1, address2);
}

// Test streaming operator
TEST_F(IPv4AddressTest, StreamingOperator)
{
    IPv4Address address("192.168.0.1");
    std::ostringstream oss;
    oss << address;
    EXPECT_EQ(oss.str(), "192.168.0.1");
}

// Test getOctet and setOctet methods
TEST_F(IPv4AddressTest, OctetMethods)
{
    IPv4Address address("192.168.0.1");
    EXPECT_EQ(address.GetOctet(0), 192);
    address.SetOctet(0, 10);
    EXPECT_EQ(address.GetOctet(0), 10);
}
/******************************************************************************
**********************************End of file**********************************
******************************************************************************/