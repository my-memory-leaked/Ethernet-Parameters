/**
 * @file IPv6Address.hpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief Defines the IPv6Address class for representing IPv6 addresses.
 * @version 0.2
 * @date 2023-06-17
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
        /**
         * @brief Binary ipv6 address length in bytes.
         */
        static constexpr uint8_t IPV6_ADDRESS_BYTE_LENGTH{16};

        /**
         * @brief Default constructor.
         */
        IPv6Address();

        /**
         * @brief Constructor that sets the IPv6 address from binary content.
         * @param cBinaryContent Pointer to the binary content.
         */
        IPv6Address(const uint8_t *cBinaryContent);

        /**
         * @brief Constructor that sets the IPv6 address from binary content.
         * @param cBinaryContent Vector of binary content.
         */
        IPv6Address(const std::vector<uint8_t> &cBinaryContent);

        /**
         * @brief Parameterized constructor that sets the IPv6 address from a string.
         * @param cAddressStr The IPv6 address string.
         */
        IPv6Address(const char *cAddressCStr);

        /**
         * @brief Parameterized constructor that sets the IPv6 address from a string.
         * @param cAddressStr The IPv6 address string.
         */
        IPv6Address(const std::string &cAddressStr);

        /**
         * @brief Returns the IPv6 address as a string.
         * @return The IPv6 address as a string.
         */
        std::string ToString() const;

        /**
         * @brief Writes the binary representation of the IPv6 address to a destination buffer.
         * @param destDataPtr Pointer to the destination buffer.
         */
        void ToBinary(uint8_t *destDataPtr) const;

        /**
         * @brief Returns the binary representation of the IPv6 address.
         * @return The binary representation of the IPv6 address.
         */
        std::vector<uint8_t> ToBinary() const;

        /**
         * @brief Sets the IPv6 address from binary content.
         * @param cBinaryAddress Pointer to the binary content.
         */
        void SetFromBinary(const uint8_t *cBinaryAddress);

        /**
         * @brief Sets the IPv6 address from binary content.
         * @param cBinaryAddress Vector of binary content.
         */
        void SetFromBinary(const std::vector<uint8_t> &cBinaryAddress);

        /**
         * @brief Clears the IPv6 address data.
         */
        void Clear();

        /**
         * @brief Assignment operator.
         * @param cAddress The IPv6 address to assign.
         * @return A reference to the IPv6 address.
         */
        IPv6Address &operator=(const IPv6Address &cAddress);

        /**
         * @brief Equality comparison operator.
         * @param cAddress The IPv6 address to compare.
         * @return True if the IPv6 addresses are equal, false otherwise.
         */
        bool operator==(const IPv6Address &cAddress) const;

        /**
         * @brief Inequality comparison operator.
         * @param cAddress The IPv6 address to compare.
         * @return True if the IPv6 addresses are not equal, false otherwise.
         */
        bool operator!=(const IPv6Address &cAddress) const;

        /**
         * @brief Friend function to write the IPv6 address to an output stream.
         * @param os The output stream.
         * @param cAddress The IPv6 address.
         * @return The output stream.
         */
        friend std::ostream &operator<<(std::ostream &os, const IPv6Address &cAddress);

    private:
        /**
         * @brief Number of groups in IPv6 address.
         */
        static constexpr uint8_t IPV6_ADDRESS_GROUPS_NUMBER{8};

        /**
         * @brief The components of the IPv6 address.
         */
        uint16_t _ipv6Address[IPV6_ADDRESS_GROUPS_NUMBER]{};

        /**
         * @brief Parses the IPv6 address string.
         * @param cAddressStr The IPv6 address string to parse.
         */
        void ParseIpV6(const char *cAddressCStr);

        /**
         * @brief Invalid binary content size error message.
         */
        static constexpr char INVALID_BINARY_CONTENT_SIZE_EXCEPTION_MESSAGE[]{"[EthernetParameter::IPv6Address] Invalid binary content size for IPv6 address!"};

        /**
         * @brief Null pointer exception error message.
         */
        static constexpr char NULL_PTR_EXCEPTION_MESSAGE[]{"[EthernetParameter::IPv6Address] Null pointer exception!"};

        /**
         * @brief Empty string exception error message.
         */
        static constexpr char EMPTY_STRING_EXCEPTION_MESSAGE[]{"[EthernetParameter::IPv6Address] Empty string exception!"};

        /**
         * @brief Invalid IPv6 address exception error message.
         */
        static constexpr char INVALID_IPV6_ADDRESS_EXCEPTION_MESSAGE[]{"[EthernetParameter::IPv6Address] Invalid IPv6 address!"};
    }; /* class IPv6Address */
}

#endif
/******************************************************************************
**********************************End of file**********************************
******************************************************************************/