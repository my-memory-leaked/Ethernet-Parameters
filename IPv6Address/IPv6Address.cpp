/**
 * @file IPv6Address.cpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief Implementation of the IPv6Address class for representing IPv6 addresses.
 * @version 0.2
 * @date 2023-06-17
 *
 * @note This software is licensed under the BSD 3-Clause License.
 *       SPDX-License-Identifier: BSD-3-Clause
 *
 * @copyright Copyright (c) 2023, Karol Pisarski
 *            All rights reserved.
 */
#include "IPv6Address.hpp"
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <cstring>

namespace EthernetParameter
{
    /**
     * @brief Default constructor for IPv6Address class.
     * Initializes an empty IPv6 address.
     */
    IPv6Address::IPv6Address()
    {
    }

    /**
     * @brief Constructor that takes a binary content.
     * @param cBinaryContent A pointer to an array of uint8_t.
     * The length of the array must be equal to the length of IPv6 address in bytes.
     * @throw std::invalid_argument if the length of cBinaryContent is invalid or if cBinaryContent is a null pointer.
     */
    IPv6Address::IPv6Address(const uint8_t *cBinaryContent)
    {
        if (cBinaryContent)
        {
            if ((sizeof(cBinaryContent) / sizeof(uint8_t)) == IPV6_ADDRESS_BYTE_LENGTH)
                memcpy(_ipv6Address, cBinaryContent, IPV6_ADDRESS_BYTE_LENGTH);
            else
                throw std::invalid_argument(INVALID_BINARY_CONTENT_SIZE_EXCEPTION_MESSAGE);
        }
        else
        {
            throw std::invalid_argument(NULL_PTR_EXCEPTION_MESSAGE);
        }
    } /* IPv6Address::IPv6Address(const uint8_t *cBinaryContent) */

    /**
     * @brief Constructor that takes a binary content.
     * @param cBinaryContent A reference to a vector of uint8_t.
     * The size of the vector must be equal to the length of IPv6 address in bytes.
     * @throw std::invalid_argument if the size of cBinaryContent is invalid or if cBinaryContent is empty.
     */
    IPv6Address::IPv6Address(const std::vector<uint8_t> &cBinaryContent)
    {
        if (!cBinaryContent.empty())
        {
            if (cBinaryContent.size() == IPV6_ADDRESS_BYTE_LENGTH)
                memcpy(_ipv6Address, cBinaryContent.data(), IPV6_ADDRESS_BYTE_LENGTH);
            else
                throw std::invalid_argument(INVALID_BINARY_CONTENT_SIZE_EXCEPTION_MESSAGE);
        }
        else
        {
            throw std::invalid_argument(NULL_PTR_EXCEPTION_MESSAGE);
        }
    } /* IPv6Address::IPv6Address(const std::vector<uint8_t> &cBinaryContent) */

    /**
     * @brief Constructor that takes an IPv6 address string.
     * @param cAddressCStr A pointer to a null-terminated string that represents an IPv6 address.
     * @throw std::invalid_argument if cAddressCStr is a null pointer or if it is an empty string or if it is an invalid IPv6 address string.
     */
    IPv6Address::IPv6Address(const char *cAddressCStr)
    {
        if (cAddressCStr && strlen(cAddressCStr) > 0)
            ParseIpV6(cAddressCStr);
        else
            throw std::invalid_argument(EMPTY_STRING_EXCEPTION_MESSAGE);
    } /* IPv6Address::IPv6Address(const char *cAddressCStr) */

    /**
     * @brief Constructor that takes an IPv6 address string.
     * @param cAddressStr A reference to a string that represents an IPv6 address.
     * @throw std::invalid_argument if cAddressStr is empty or if it is an invalid IPv6 address string.
     */
    IPv6Address::IPv6Address(const std::string &cAddressStr)
    {
        if (!cAddressStr.empty())
        {
            if (cAddressStr.length() > 0)
                ParseIpV6(cAddressStr.c_str());
            else
                throw std::invalid_argument(EMPTY_STRING_EXCEPTION_MESSAGE);
        }
        else
        {
            throw std::invalid_argument(EMPTY_STRING_EXCEPTION_MESSAGE);
        }
    } /* IPv6Address::IPv6Address(const std::string &cAddressStr) */

    /**
     * @brief Returns a string representation of the IPv6 address.
     * @return A string representation of the IPv6 address.
     */
    std::string IPv6Address::ToString() const
    {
        std::stringstream ss;
        ss << std::hex << std::setfill('0');
        for (int i = 0; i < IPV6_ADDRESS_GROUPS_NUMBER; i++)
        {
            ss << std::setw(4) << _ipv6Address[i];
            if (i < IPV6_ADDRESS_GROUPS_NUMBER - 1)
                ss << ":";
        }
        return ss.str();
    } /* std::string IPv6Address::ToString() const */

    /**
     * @brief Copies the IPv6 address to a binary buffer.
     * @param destDataPtr A pointer to a buffer of uint8_t that will be filled with the IPv6 address.
     * @throw std::invalid_argument if destDataPtr is a null pointer.
     */
    void IPv6Address::ToBinary(uint8_t *destDataPtr) const
    {
        if (destDataPtr)
        {
            uint8_t bytes[2]{};
            uint16_t group{};
            for (int i = 0; i < IPV6_ADDRESS_GROUPS_NUMBER; ++i)
            {
                group = _ipv6Address[i];
                memcpy(bytes, &group, sizeof(bytes));
                *destDataPtr++ = bytes[0];
                *destDataPtr++ = bytes[1];
            }
        }
        else
            throw std::invalid_argument(NULL_PTR_EXCEPTION_MESSAGE);
    } /* void IPv6Address::ToBinary(uint8_t *destDataPtr) const */

    /**
     * @brief Returns the binary representation of the IPv6 address as a vector.
     * @return A vector of uint8_t that represents the binary representation of the IPv6 address.
     */
    std::vector<uint8_t> IPv6Address::ToBinary() const
    {
        std::vector<uint8_t> binaryRepresentation;
        binaryRepresentation.reserve(IPV6_ADDRESS_BYTE_LENGTH);
        ToBinary(binaryRepresentation.data());
        return binaryRepresentation;
    } /* std::vector<uint8_t> IPv6Address::ToBinary() const */

    /**
     * @brief Sets the IPv6 address from a binary buffer.
     * @param cBinaryAddress A pointer to a buffer of uint8_t that represents the binary representation of the IPv6 address.
     * @throw std::invalid_argument if cBinaryAddress is a null pointer.
     */
    void IPv6Address::SetFromBinary(const uint8_t *cBinaryAddress)
    {
        if (cBinaryAddress)
        {
            uint8_t bytes[2]{};
            uint16_t group;
            for (int i = 0; i < IPV6_ADDRESS_GROUPS_NUMBER; ++i)
            {
                bytes[0] = *cBinaryAddress++;
                bytes[1] = *cBinaryAddress++;
                memcpy(&group, bytes, sizeof(group));
                _ipv6Address[i] = group;
            }
        }
        else
            throw std::invalid_argument(NULL_PTR_EXCEPTION_MESSAGE);
    } /* void IPv6Address::SetFromBinary(const uint8_t *cBinaryAddress) */

    /**
     * @brief Sets the IPv6 address from a binary buffer.
     * @param cBinaryAddress A reference to a vector of uint8_t that represents the binary representation of the IPv6 address.
     * @throw std::invalid_argument if the size of cBinaryAddress is invalid or if cBinaryAddress is empty.
     */
    void IPv6Address::SetFromBinary(const std::vector<uint8_t> &cBinaryAddress)
    {
        if (cBinaryAddress.size() == IPV6_ADDRESS_BYTE_LENGTH)
        {
            SetFromBinary(cBinaryAddress.data());
        }
        else
            throw std::invalid_argument(INVALID_BINARY_CONTENT_SIZE_EXCEPTION_MESSAGE);
    } /* void IPv6Address::SetFromBinary(const std::vector<uint8_t> &cBinaryAddress) */

    /**
     * @brief Sets all the bytes of the IPv6 address to 0.
     */
    void IPv6Address::Clear()
    {
        memset(_ipv6Address, 0, IPV6_ADDRESS_BYTE_LENGTH);
    } /* void IPv6Address::Clear() */

    /**
     * @brief Copy assignment operator.
     * @param cAddress The IPv6 address to copy.
     * @return A reference to the left-hand side object.
     */
    IPv6Address &IPv6Address::operator=(const IPv6Address &cAddress)
    {
        if (this != &cAddress)
            memcpy(_ipv6Address, cAddress._ipv6Address, IPV6_ADDRESS_BYTE_LENGTH);
        return *this;
    } /* IPv6Address &IPv6Address::operator=(const IPv6Address &cAddress) */

    /**
     * @brief Equality comparison operator.
     * @param cAddress The IPv6 address to compare with.
     * @return True if the IPv6 addresses are equal, false otherwise.
     */
    bool IPv6Address::operator==(const IPv6Address &cAddress) const
    {
        return memcmp(_ipv6Address, cAddress._ipv6Address, IPV6_ADDRESS_BYTE_LENGTH) == 0;
    } /* bool IPv6Address::operator==(const IPv6Address &cAddress) const */

    /**
     * @brief Inequality comparison operator.
     * @param cAddress The IPv6 address to compare with.
     * @return True if the IPv6 addresses are not equal, false otherwise.
     */
    bool IPv6Address::operator!=(const IPv6Address &cAddress) const
    {
        return memcmp(_ipv6Address, cAddress._ipv6Address, IPV6_ADDRESS_BYTE_LENGTH) != 0;
    } /* bool IPv6Address::operator!=(const IPv6Address &cAddress) const */

    /**
     * @brief Stream insertion operator.
     * Inserts the string representation of the IPv6 address into the output stream.
     * @param os The output stream.
     * @param cAddress The IPv6 address to insert into the stream.
     * @return The output stream.
     */
    std::ostream &operator<<(std::ostream &os, const IPv6Address &cAddress)
    {
        return os << cAddress.ToString();
    } /* std::ostream &operator<<(std::ostream &os, const IPv6Address &cAddress) */

    //////////////////////////////////////////////////////////////////////////////////////////
    // Private Methods.

    /**
     * @brief Parses an IPv6 address string and fills the IPv6Address object.
     * @param cAddressCStr A pointer to a null-terminated string that represents an IPv6 address.
     * @throw std::invalid_argument if cAddressCStr is an invalid IPv6 address string.
     */
    void IPv6Address::ParseIpV6(const char *cAddressCStr)
    {
        uint8_t groupIndex = 0;
        uint16_t value = 0;
        uint8_t digits = 0;
        const char *token = cAddressCStr;

        while (groupIndex < IPV6_ADDRESS_GROUPS_NUMBER)
        {
            // Parse each token as a hexadecimal number
            value = 0;
            digits = 0;

            while (*token != '\0' && *token != ':')
            {
                char c = *token;
                value <<= 4; // Shift left by 4 bits

                if (c >= '0' && c <= '9')
                    value |= (c - '0'); // Add the decimal digit
                else if (c >= 'a' && c <= 'f')
                    value |= (c - 'a' + 10); // Add the hexadecimal digit (lowercase)
                else if (c >= 'A' && c <= 'F')
                    value |= (c - 'A' + 10); // Add the hexadecimal digit (uppercase)
                else
                    throw std::invalid_argument(INVALID_IPV6_ADDRESS_EXCEPTION_MESSAGE);

                digits++;
                token++;
            } /* while (*token != '\0' && *token != ':')*/

            if (digits == 0 || digits > 4)
                throw std::invalid_argument(INVALID_IPV6_ADDRESS_EXCEPTION_MESSAGE);

            _ipv6Address[groupIndex] = value;
            groupIndex++;

            if (*token == '\0')
                break;

            token++; // Skip the colon

        } /*while (groupIndex < IPV6_ADDRESS_GROUPS_NUMBER)*/

        if (groupIndex != IPV6_ADDRESS_GROUPS_NUMBER || *token != '\0')
            throw std::invalid_argument(INVALID_IPV6_ADDRESS_EXCEPTION_MESSAGE);

    } /* void IPv6Address::ParseIpV6(const char *cAddressCStr) */

}

/******************************************************************************
**********************************End of file**********************************
******************************************************************************/