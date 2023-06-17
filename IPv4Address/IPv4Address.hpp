/**
 * @file IPv4Address.hpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief IPv4Address ethernet parameter class definition.
 * @version 0.4
 * @date 2023-06-16
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
        /**
         * @brief Number of IPv4 octets.
         */
        static constexpr uint8_t IP_ADDRESS_OCTETS = 4;

        /**
         * @brief Total length (in bytes) of IPv4 address including dots.
         */
        static constexpr uint8_t IP_ADDRESS_MAX_LENGTH = 15;

        /**
         * @brief Default constructor for the IPv4Address class.
         *
         * This constructor creates an empty IPv4 address.
         */
        IPv4Address();

        /**
         * @brief Destructor for the IPv4Address class.
         */
        ~IPv4Address();

        /**
         * @brief Constructor for the IPv4Address class that creates an IPv4 address from binary data.
         * @param cData The binary representation of the IPv4 address.
         * @throws std::invalid_argument If the provided pointer is null (nullptr).
         */
        IPv4Address(const uint8_t *cData);

        /**
         * @brief Constructor for the IPv4Address class that accepts specific octet values.
         * @param cOctet1 The value of the first octet.
         * @param cOctet2 The value of the second octet.
         * @param cOctet3 The value of the third octet.
         * @param cOctet4 The value of the fourth octet.
         */
        IPv4Address(const uint8_t &cOctet1, const uint8_t &cOctet2, const uint8_t &cOctet3, const uint8_t &cOctet4);

        /**
         * @brief Constructor for the IPv4Address class that accepts a string representation of an IPv4 address.
         * @param cAddressStr A string representation of an IPv4 address (e.g., "192.168.0.1").
         * @throws std::invalid_argument If the provided string is empty.
         */
        IPv4Address(const std::string &cAddressStr);

        /**
         * @brief Constructor for the IPv4Address class that creates an IPv4 address from binary data.
         * @param cBinaryAddress The binary representation of the IPv4 address.
         * @throws std::invalid_argument If the provided binary address vector is empty or has an invalid size.
         */
        IPv4Address(const std::vector<uint8_t> &cBinaryAddress);

        /**
         * @brief Setter for a specific octet.
         * @param cIndex The index of the octet to set.
         * @param cValue The value to set for the octet.
         * @throws std::out_of_range If the provided index is out of range [0, 3].
         */
        void SetOctet(const uint8_t &cIndex, const uint8_t &cValue);

        /**
         * @brief Getter for a specific octet.
         * @param cIndex The index of the octet to retrieve.
         * @return The value of the octet at the specified index.
         * @throws std::out_of_range If the provided index is out of range [0, 3].
         */
        uint8_t GetOctet(const uint8_t &cIndex) const;

        /**
         * @brief Returns the current IP address as a string representation.
         * @return The IP address as a string.
         */
        std::string ToString() const;

        /**
         * @brief Copies the binary representation of the IPv4 address to the provided destination pointer.
         * @param destDataPtr Pointer to the destination memory location to copy the binary address data to.
         * @throws std::invalid_argument If the provided destination pointer is null (nullptr).
         */
        void ToBinary(uint8_t *destDataPtr) const;

        /**
         * @brief Returns the IPv4 address as binary data.
         * @return The IPv4 address as binary data.
         */
        std::vector<uint8_t> ToBinary() const;

        /**
         * @brief Sets the IPv4 address from a binary representation.
         * @param cBinaryAddress Pointer to the binary representation of the IPv4 address.
         * @throws std::invalid_argument if the binary address pointer is null.
         */
        void SetFromBinary(const uint8_t *cBinaryAddress);

        /**
         * @brief Sets the IPv4 address from a binary representation.
         * @param cBinaryAddress The binary representation of the IPv4 address.
         * @throws std::invalid_argument if the binary address vector is empty.
         */
        void SetFromBinary(const std::vector<uint8_t> &cBinaryAddress);

        /**
         * @brief Clears the entire IP address.
         */
        void Clear();

        /**
         * @brief Overloads the insertion operator for output.
         * @param os The output stream.
         * @param cAddress The IPv4 address to output.
         * @return The output stream after the IPv4 address has been written.
         */
        friend std::ostream &operator<<(std::ostream &os, const IPv4Address &cAddress);

        /**
         * @brief Not equal comparison operator.
         * @param cIp The IPv4 address to compare.
         * @return `true` if the addresses are not equal, `false` otherwise.
         */
        bool operator!=(const IPv4Address &cIp) const;

        /**
         * @brief Equal comparison operator.
         * @param cIp The IPv4 address to compare.
         * @return `true` if the addresses are equal, `false` otherwise.
         */
        bool operator==(const IPv4Address &cIp) const;

        /**
         * @brief Assignment operator for the IPv4Address class.
         * @param cIp The IPv4 address to assign.
         * @return A reference to the assigned IPv4 address.
         */
        IPv4Address &operator=(const IPv4Address &cIp);

    private:
        /**
         * @brief IPv4 address container.
         */
        uint8_t _octets[IP_ADDRESS_OCTETS]{};

        /**
         * @brief Separator between octets.
         */
        static constexpr uint8_t DOT{'.'};

        /**
         * @brief Error message indicating an invalid binary address size.
         */
        static constexpr char INVALID_BINARY_ADDRESS_SIZE[]{"[EthernetParameter::IPv4Address] Invalid binary address size!"};

        /**
         * @brief Error message indicating an out-of-range octet index.
         */
        static constexpr char OCTET_OUT_OF_RANGE[]{"[EthernetParameter::IPv4Address] Octet index out of range!"};

        /**
         * @brief Error message indicating a null pointer encountered.
         */
        static constexpr char NULL_PTR_ENCOUNTERED[]{"[EthernetParameter::IPv4Address] Null pointer encountered!"};

        /**
         * @brief Error message indicating an empty binary vector encountered.
         */
        static constexpr char EMPTY_BINARY_VECTOR[]{"[EthernetParameter::IPv4Address] Empty binary vector encountered!"};

        /**
         * @brief Error message indicating an empty string encountered.
         */
        static constexpr char EMPTY_STRING[]{"[EthernetParameter::IPv4Address] Empty string encountered!"};
    }; /* class IPv4Address */
}

#endif /* IPV4ADDRESS_H */

/******************************************************************************
********************************* End of file *********************************
******************************************************************************/