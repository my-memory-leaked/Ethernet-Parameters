/**
 * @file IPv6Address.cpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief Implementation of the IPv6Address class for representing IPv6 addresses.
 * @version 0.1
 * @date 2023-05-23
 *
 * @note This software is licensed under the BSD 3-Clause License.
 *       SPDX-License-Identifier: BSD-3-Clause
 *
 * @copyright Copyright (c) 2023, Karol Pisarski
 *            All rights reserved.
 */
#include "IPv6Address.hpp"
#include <sstream>

namespace EthernetParameter
{
    /**
     * @brief Default constructor for IPv6Address class.
     * Initializes an empty IPv6 address.
     */
    IPv6Address::IPv6Address()
    {
    } /* IPv6Address() */

    /**
     * @brief Parameterized constructor for IPv6Address class.
     * Parses the given IPv6 address string and initializes the IPv6 address.
     * @param cAddressStr The IPv6 address string to parse and initialize the address.
     */
    IPv6Address::IPv6Address(const std::string &cAddressStr)
    {
        parseIPv6(cAddressStr);
    } /* IPv6Address(const std::string &cAddressStr) */

    /**
     * @brief Constructor for IPv6Address class that initializes the address using binary data.
     * @param cBinaryContent The binary content representing the IPv6 address.
     */
    IPv6Address::IPv6Address(const std::vector<size_t> &cBinaryContent)
    {
        // Ensure that the binary content size is valid for an IPv6 address.
        if (cBinaryContent.size() != BINARY_IPV6_ADDRESS_LENGTH)
        {
            throw std::invalid_argument(INVALID_BINARY_CONTENT_SIZE_ERROR_MESSAGE);
        }

        // Clear the existing address components
        _address.clear();

        size_t component {};
        // Extract the components from the binary content
        for (size_t i = 0; i < BINARY_IPV6_ADDRESS_LENGTH; i += 2)
        {
            component = (cBinaryContent[i] << BITS_IN_BYTE) | cBinaryContent[i + 1];
            _address.push_back(component);
        }
    }   /* IPv6Address(const std::vector<size_t> &cBinaryContent) */

    /**
     * @brief Destructor for IPv6Address class.
     * Does not perform any specific cleanup tasks.
     */
    IPv6Address::~IPv6Address()
    {
    }   /* ~IPv6Address() */

    /**
     * @brief Clears the IPv6 address.
     * Removes all components of the address, making it empty.
     */
    void IPv6Address::Clear()
    {
        _address.clear();
    }   /* IPv6Address::Clear() */

    /**
     * @brief Converts the IPv6 address to a string representation.
     * @return The string representation of the IPv6 address.
     */
    std::string IPv6Address::ToString() const
    {
        std::stringstream ss;
        for (size_t i = 0; i < _address.size(); ++i)
        {
            ss << std::hex << _address[i];
            if (i != _address.size() - 1)
            {
                ss << ASCII_COLON;
            }
        }
        return ss.str();
    }   /* IPv6Address::ToString() */

    /**
     * @brief Returns the binary content of the IPv6 address.
     * @return The binary content of the IPv6 address as a vector of bytes.
     */
    std::vector<size_t> IPv6Address::ToBinary() const
    {
        std::vector<size_t> binaryContent;
        for (const auto &component : _address)
        {
            binaryContent.push_back(static_cast<size_t>((component >> BITS_IN_BYTE) & 0xFF));
            binaryContent.push_back(static_cast<size_t>(component & 0xFF));
        }
        return binaryContent;
    } /* IPv6Address::ToBinary() */

    /**
     * @brief Equality comparison operator for IPv6Address class.
     * @param other The IPv6 address to compare with.
     * @return True if the IPv6 addresses are equal, false otherwise.
     */
    bool IPv6Address::operator==(const IPv6Address &other) const
    {
        return _address == other._address;
    }   /* IPv6Address::operator==(const IPv6Address &other) const */

    /**
     * @brief Inequality comparison operator for IPv6Address class.
     * @param other The IPv6 address to compare with.
     * @return True if the IPv6 addresses are not equal, false otherwise.
     */
    bool IPv6Address::operator!=(const IPv6Address &other) const
    {
        return !(*this == other);
    }   /* IPv6Address::operator!=(const IPv6Address &other) const */

    /**
     * @brief Stream insertion operator for the IPv6Address class.
     * Inserts the string representation of the IPv6 address into the output stream.
     * @param os The output stream.
     * @param cAddress The IPv6 address to insert into the stream.
     * @return The output stream.
     */
    std::ostream &operator<<(std::ostream &os, const IPv6Address &cAddress)
    {
        return os << cAddress.ToString();
    }   /* &operator<<(std::ostream &os, const IPv6Address &cAddress) */

    /**
     * @brief Assignment operator for the IPv6Address class.
     * Assigns the given IPv6 address to the current instance.
     * @param cAddress The IPv6 address to assign.
     * @return The reference to the assigned IPv6 address.
     */
    IPv6Address &IPv6Address::operator=(const IPv6Address &cAddress)
    {
        if (this != &cAddress)
        {
            _address = cAddress._address;
        }
        return *this;
    } /* &IPv6Address::operator=(const IPv6Address &cAddress) */

    /**
     * @brief Parses the IPv6 address string and initializes the address components.
     * @param cAddressStr The IPv6 address string to parse.
     */
    void IPv6Address::parseIPv6(const std::string &cAddressStr)
    {
        std::stringstream ss(cAddressStr);
        std::string segment{};
        size_t value{};
        std::stringstream converter {};

        while (std::getline(ss, segment, ASCII_COLON))
        {
            converter = std::stringstream(segment);
            converter >> std::hex >> value;
            _address.push_back(value);
        }
    } /* IPv6Address::parseIPv6(const std::string &cAddressStr) */
}

/******************************************************************************
**********************************End of file**********************************
******************************************************************************/