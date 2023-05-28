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
#include <vector>

namespace EthernetParameter
{
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
        /// @brief Total length (in bytes) of IPv4 address including dots.
        inline static constexpr uint8_t IP_ADDRESS_MAX_LENGTH = 15;

        /// @brief Basic constructor.
        IPv4Address();

        /// @brief Basic destructor.
        ~IPv4Address();

        /// @brief Basic constructor with string IP as parameter.
        /// @param cAddressStr The string representation of the IP address.
        IPv4Address(const std::string &cAddressStr);

        /// @brief Basic constructor with specific octet values.
        /// @param cOctet1 The value of the first octet.
        /// @param cOctet2 The value of the second octet.
        /// @param cOctet3 The value of the third octet.
        /// @param cOctet4 The value of the fourth octet.
        IPv4Address(const uint8_t &cOctet1, const uint8_t &cOctet2, const uint8_t &cOctet3, const uint8_t &cOctet4);

        /// @brief Constructor that creates an IPv4 address from binary data.
        /// @param cBinaryAddress The binary representation of the IPv4 address.
        IPv4Address(const std::vector<uint8_t> &cBinaryAddress);

        /// @brief Returns the current IP address as a string.
        /// @return The IP address as a string.
        std::string ToString() const;

        ///@brief Returns the IPv4 address as binary data.
        ///@return The IPv4 address as binary data.
        std::vector<uint8_t> ToBinary() const;

        /// @brief Clears the entire IP address.
        void Clear();

        /// @brief Overloads the insertion operator for output.
        /// @param os The output stream.
        /// @param cAddress The IPv4 address to output.
        /// @return The output stream after the IPv4 address has been written.
        friend std::ostream &operator<<(std::ostream &os, const IPv4Address &cAddress);

        /// @brief Not equal comparison operator.
        /// @param cIp The IPv4 address to compare.
        /// @return `true` if the addresses are not equal, `false` otherwise.
        bool operator!=(const IPv4Address &cIp) const;

        /// @brief Equal comparison operator.
        /// @param cIp The IPv4 address to compare.
        /// @return `true` if the addresses are equal, `false` otherwise.
        bool operator==(const IPv4Address &cIp) const;

        /// @brief Assignment operator for the IPv4Address class.
        /// @param cIp The IPv4 address to assign.
        /// @return A reference to the assigned IPv4 address.
        IPv4Address &operator=(const IPv4Address &cIp);

    protected:
        /// @brief Setter for a specific octet.
        /// @param cIndex The index of the octet to set.
        /// @param cValue The value to set for the octet.
        void setOctet(const uint8_t &cIndex, const uint8_t &cValue);

        /// @brief Getter for a specific octet.
        /// @param cIndex The index of the octet to retrieve.
        /// @return The value of the octet at the specified index.
        uint8_t getOctet(const uint8_t &cIndex) const;

    private:
        /// @brief Number of IPv4 octets.
        inline static constexpr uint8_t IP_ADDRESS_OCTETS = 4;

        /// @brief IPv4 address container.
        uint8_t _octets[IP_ADDRESS_OCTETS]{};

        /// @brief Separator between octets.
        inline static constexpr uint8_t DOT{'.'};

        /// @brief Invalid IP address binary data error message.
        static constexpr char INVALID_BINARY_ADDRESS_SIZE[]{"Invalid binary address size}"};

    }; /* class IPv4Address */

}

#endif /* IPV4ADDRESS_H */

/******************************************************************************
********************************* End of file *********************************
******************************************************************************/