/**
 * @file IPv6Address.hpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief Defines the IPv6Address class for representing IPv6 addresses.
 * @version 0.1
 * @date 2023-05-23
 *
 * @note This software is licensed under the BSD 3-Clause License.
 *       SPDX-License-Identifier: BSD-3-Clause
 *
 * @copyright Copyright (c) 2023, Karol Pisarski
 *            All rights reserved.
 */
#ifndef IPV6ADDRESS_H
#define IPV6ADDRESS_H
#include <cstdint>
#include <string>
#include <vector>

namespace EthernetParameter
{
    /**
     * @class IPv6Address
     * @brief Represents an IPv6 address.
     */
    class IPv6Address
    {
    public:
        /// @brief Default constructor.
        IPv6Address();

        /// @brief Parameterized constructor.
        /// @param cAddressStr The IPv6 address string.
        IPv6Address(const std::string &cAddressStr);

        /// @brief Constructor for IPv6Address class that initializes the address using binary data.
        /// @param cBinaryContent The binary content representing the IPv6 address.
        IPv6Address(const std::vector<size_t> &cBinaryContent);

        /// @brief Destructor.
        ~IPv6Address();

        /// @brief Clears the IPv6 address.
        void Clear();

        /// @brief Converts the IPv6 address to a string representation.
        /// @return The string representation of the IPv6 address.
        std::string ToString() const;

        /// @brief Returns the binary content of the IPv6 address.
        /// @return The binary content of the IPv6 address as a vector.
        std::vector<size_t> ToBinary() const;

        /// @brief Equality comparison operator.
        /// @param cIp cIp The IPv6 address to compare.
        /// @return True if the IPv6 addresses are equal, false otherwise.
        bool operator==(const IPv6Address &cIp) const;

        /// @brief Inequality comparison operator.
        /// @param cIp cIp The IPv6 address to compare.
        /// @return True if the IPv6 addresses are not equal, false otherwise.
        bool operator!=(const IPv6Address &cIp) const;

        /// @brief Stream insertion operator.
        /// @param os The output stream.
        /// @param cAddress The IPv6 address to insert into the stream.
        /// @return The output stream.
        friend std::ostream &operator<<(std::ostream &os, const IPv6Address &cAddress);

        /// @brief Assignment operator.
        /// @param cAddress The IPv6 address to assign.
        /// @return The reference to the assigned IPv6 address.
        IPv6Address &operator=(const IPv6Address &cAddress);

    private:
        /// @brief The components of the IPv6 address.
        std::vector<size_t> _address;

        /// @brief Parses the IPv6 address string.
        /// @param cAddressStr The IPv6 address string to parse.
        void parseIPv6(const std::string &cAddressStr);

        /// @brief Colon separator character.
        static constexpr char ASCII_COLON{':'};

        /// @brief Number of bits in a byte.
        static constexpr uint8_t BITS_IN_BYTE{8};

        /// @brief Binary ipv6 address length in bytes.
        static constexpr uint8_t BINARY_IPV6_ADDRESS_LENGTH{16};

        /// @brief Invalid binary content size error message.
        static constexpr char INVALID_BINARY_CONTENT_SIZE_ERROR_MESSAGE[]{"Invalid binary content size for IPv6 address"};

    }; /* class IPv6Address */
}

#endif
/******************************************************************************
**********************************End of file**********************************
******************************************************************************/