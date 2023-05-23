/**
 * @file IPv4Address.hpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief IPv4Address ethernet parameter class definition.
 * @version 0.1
 * @date 2023-05-19
 *
 * @note This software is licensed under the BSD 3-Clause License.
 *       SPDX-License-Identifier: BSD-3-Clause
 *
 * @copyright Copyright (c) 2023, Karol Pisarski
 *            All rights reserved.
 */
#ifndef IPV4ADDRESS_H
#define IPV4ADDRESS_H
#include <cstdint>
#include <string>

/**
 * @class IPv4Address
 * @brief Represents an IPv4 address.
 *
 * This class represents an IPv4 address as a set of 4 octets (8-bit unsigned integers).
 * It provides methods to construct an address from a string or a set of octets,
 * as well as to get and set individual octets, clear the address, and convert it to a string.
 */
class IPv4Address
{
public:
    /// Total length (in bytes) of IPv4 address including dots
    inline static constexpr uint8_t IP_ADDRESS_MAX_LENGTH = 15;

    /// Basic constructor
    IPv4Address();
    /// Basic destructor
    ~IPv4Address();
    /// Basic constructor with string IP as parameter
    IPv4Address(const std::string &cAddressStr);
    /// Basic constructor with specific octet
    IPv4Address(const uint8_t &cOctet1, const uint8_t &cOctet2, const uint8_t &cOctet3, const uint8_t &cOctet4);

    /// Returns current IP address as string
    std::string ToString() const;
    /// Clears whole IP address
    void Clear();
    /// Friend function to overload the insertion operator for output
    friend std::ostream &operator<<(std::ostream &os, const IPv4Address &cAddress);
    /// Not equal comparison operator
    bool operator!=(const IPv4Address &cIp) const;
    /// Equal comparison operator
    bool operator==(const IPv4Address &cIp) const;
    ///  Assignment operator for IPv4Address class
    IPv4Address &operator=(const IPv4Address &cIp);

protected:
    /// Setter of specific octet
    void setOctet(const uint8_t &cIndex, const uint8_t &cValue);
    /// Getter of specific octet
    uint8_t getOctet(const uint8_t &cIndex) const;

private:
    /// Number of IPv4 octets
    inline static constexpr uint8_t IP_ADDRESS_OCTETS = 4;
    /// IPv4 address container
    uint8_t _octets[IP_ADDRESS_OCTETS]{};
    /// Separator between octets
    inline static constexpr uint8_t DOT{'.'};

}; /* class IPv4Address */

#endif /* IPV4ADDRESS_H */
/******************************************************************************
********************************* End of file *********************************
******************************************************************************/