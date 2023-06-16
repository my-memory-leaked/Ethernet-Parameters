/**
 * @file IPv4Address.cpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief IPv4Address ethernet parameter class implementation.
 * @version 0.4
 * @date 2023-05-19
 *
 * @note This software is licensed under the BSD 3-Clause License.
 *       SPDX-License-Identifier: BSD-3-Clause
 *
 * @copyright Copyright (c) 2023, Karol Pisarski
 *            All rights reserved.
 */
#include "IPv4Address.hpp"
#include <cstring>
#include <string>
#include <sstream>

namespace EthernetParameter
{
	/**
	 * @brief Default constructor for the IPv4Address class.
	 */
	IPv4Address::IPv4Address()
	{
	}

	/**
	 * @brief Destructor for the IPv4Address class.
	 */
	IPv4Address::~IPv4Address()
	{
	}

	/**
	 * @brief Constructor that creates an IPv4 address from a uint8_t array.
	 *
	 * This constructor initializes an IPv4 address by copying the data from a uint8_t array.
	 * The array must contain exactly 4 octets, representing the individual components of the IPv4 address.
	 *
	 * @param cData The pointer to the uint8_t array containing the address data.
	 *
	 * @throw std::invalid_argument If the provided pointer is null (nullptr).
	 */
	IPv4Address::IPv4Address(const uint8_t *cData)
	{
		if (cData)
		{
			memcpy(_octets, cData, IP_ADDRESS_OCTETS);
		}
		else
		{
			throw std::invalid_argument(NULL_PTR_ENCOUNTERED);
		}
	} /* IPv4Address::IPv4Address(const uint8_t *cData) */

	/**
	 * @brief Constructor for the IPv4Address class that accepts four octets as separate parameters.
	 * @param octet1 The first octet of the IPv4 address.
	 * @param octet2 The second octet of the IPv4 address.
	 * @param octet3 The third octet of the IPv4 address.
	 * @param octet4 The fourth octet of the IPv4 address.
	 */
	IPv4Address::IPv4Address(const uint8_t &cOctet1, const uint8_t &cOctet2, const uint8_t &cOctet3, const uint8_t &cOctet4)
	{
		_octets[0] = cOctet1;
		_octets[1] = cOctet2;
		_octets[2] = cOctet3;
		_octets[3] = cOctet4;
	} /* IPv4Address(const uint8_t &cOctet1, const uint8_t &cOctet2, const uint8_t &cOctet3, const uint8_t &cOctet4) */

	/**
	 * @brief Constructor for the IPv4Address class that accepts a string representation of an IPv4 address.
	 *
	 * This constructor initializes an IPv4 address using the provided string representation of an IPv4 address.
	 * The string should follow the standard IPv4 format, such as "192.168.0.1".
	 *
	 * @param cAddressStr A string representation of an IPv4 address.
	 *
	 * @throw std::invalid_argument If the provided string is empty.
	 */
	IPv4Address::IPv4Address(const std::string &cAddressStr)
	{
		if (!cAddressStr.empty())
		{
			std::string byteStr{};
			uint8_t byteCount{};

			for (const char &cOctet : cAddressStr)
			{
				if (cOctet == DOT)
				{
					// convert byte_str to int and add to address_bytes
					_octets[byteCount] = std::stoi(byteStr);
					byteStr.clear();
					byteCount++;
				}
				else
				{
					byteStr += cOctet;
				}
			} // for (const char &cOctet : cAddressStr)

			// add last byte to address_bytes
			_octets[byteCount] = std::stoi(byteStr);
		}
		else
		{
			throw std::invalid_argument(EMPTY_STRING);
		}
	} /* IPv4Address(const std::string &cAddressStr) */

	/**
	 * @brief Constructor that creates an IPv4 address from binary data.
	 *
	 * This constructor initializes an IPv4 address using the provided binary representation of the address.
	 * The binary data should be a vector of uint8_t elements with a size of 4, representing the individual components of the IPv4 address.
	 *
	 * @param cBinaryAddress The binary representation of the IPv4 address.
	 *
	 * @throw std::invalid_argument If the provided binary address vector is empty or has an invalid size.
	 */
	IPv4Address::IPv4Address(const std::vector<uint8_t> &cBinaryAddress)
	{
		if (!cBinaryAddress.empty())
		{
			if (cBinaryAddress.size() != IP_ADDRESS_OCTETS)
			{
				throw std::invalid_argument(INVALID_BINARY_ADDRESS_SIZE);
			}

			memcpy(_octets, cBinaryAddress.data(), IP_ADDRESS_OCTETS);
		}
		else
		{
			throw std::invalid_argument(EMPTY_BINARY_VECTOR);
		}
	} /* IPv4Address::IPv4Address(const std::vector<uint8_t> &cBinaryAddress) */

	/**
	 * @brief Sets the value of the octet at the specified index.
	 *
	 * This function sets the value of the octet at the specified index in the IPv4 address to the provided value.
	 * The index should be in the range [0, 3] since there are 4 octets in an IPv4 address.
	 *
	 * @param cIndex The index of the octet to set.
	 * @param cValue The value to set the octet to.
	 *
	 * @throws std::out_of_range If the provided index is out of range [0, 3].
	 */
	void IPv4Address::SetOctet(const uint8_t &cIndex, const uint8_t &cValue)
	{
		if (cIndex < IP_ADDRESS_OCTETS)
		{
			_octets[cIndex] = cValue;
		}
		else
		{
			throw std::out_of_range(OCTET_OUT_OF_RANGE);
		}
	} /* IPv4Address::SetOctet(const uint8_t &cIndex, const uint8_t &cValue) */

	/**
	 * @brief Returns the value of the octet at the specified index.
	 *
	 * This function retrieves the value of the octet at the specified index in the IPv4 address.
	 * The index should be in the range [0, 3] since there are 4 octets in an IPv4 address.
	 *
	 * @param cIndex The index of the octet to retrieve.
	 * @return The value of the octet at the specified index.
	 *
	 * @throws std::out_of_range If the provided index is out of range [0, 3].
	 */
	uint8_t IPv4Address::GetOctet(const uint8_t &cIndex) const
	{
		if (cIndex < IP_ADDRESS_OCTETS)
		{
			return _octets[cIndex];
		}
		else
		{
			throw std::out_of_range(OCTET_OUT_OF_RANGE);
		}
	} /* IPv4Address::GetOctet(const uint8_t &cIndex) const */

	/**
	 * @brief Converts the IPv4 address to a string representation.
	 * @return A string representation of the IPv4 address.
	 */
	std::string IPv4Address::ToString() const
	{
		std::string ipV4StrRetVal{};

		for (uint8_t i = 0; i < IP_ADDRESS_OCTETS; i++)
		{
			ipV4StrRetVal += std::to_string(_octets[i]);

			if (i != 3)
			{
				ipV4StrRetVal += DOT;
			}
		}

		return ipV4StrRetVal;
	} /* IPv4Address::ToString() */

	/**
	 * @brief Converts the IPv4 address to binary data and stores it in the provided destination pointer.
	 *
	 * This function converts the IPv4 address to binary data and copies it to the memory location pointed by `destDataPtr`.
	 * The destination pointer should have sufficient memory allocated to store the binary data (at least 4 bytes).
	 *
	 * @param destDataPtr A pointer to the destination memory location to store the binary data.
	 *
	 * @throw std::invalid_argument If the provided destination pointer is null (nullptr).
	 */
	void IPv4Address::ToBinary(uint8_t *destDataPtr) const
	{
		if (destDataPtr)
		{
			memcpy(destDataPtr, _octets, IP_ADDRESS_OCTETS);
		}
		else
		{
			throw std::invalid_argument(NULL_PTR_ENCOUNTERED);
		}
	} /* IPv4Address::ToBinary(uint8_t *destDataPtr) const */

	/**
	 * @brief Returns the IPv4 address as binary data.
	 * @return The IPv4 address as binary data.
	 */
	std::vector<uint8_t> IPv4Address::ToBinary() const
	{
		std::vector<uint8_t> binaryAddress(IP_ADDRESS_OCTETS);
		memset(binaryAddress.data(), 0, binaryAddress.size());
		memcpy(binaryAddress.data(), _octets, IP_ADDRESS_OCTETS);
		return binaryAddress;
	}

	/**
	 * @brief Sets the IPv4 address from a binary representation.
	 * @param cBinaryAddress Pointer to the binary representation of the IPv4 address.
	 * @throws std::invalid_argument if the binary address pointer is null.
	 */
	void IPv4Address::SetFromBinary(const uint8_t *cBinaryAddress)
	{
		if (!cBinaryAddress)
		{
			throw std::invalid_argument(NULL_PTR_ENCOUNTERED);
		}

		memcpy(_octets, cBinaryAddress, IP_ADDRESS_OCTETS);
	} /* IPv4Address::SetFromBinary(const uint8_t *cBinaryAddress) */

	/**
	 * @brief Sets the IPv4 address from a binary representation.
	 * @param cBinaryAddress The binary representation of the IPv4 address.
	 * @throws std::invalid_argument if the binary address vector is empty or if a null pointer is provided.
	 */
	void IPv4Address::SetFromBinary(const std::vector<uint8_t> &cBinaryAddress)
	{
		if (cBinaryAddress.empty())
		{
			throw std::invalid_argument(EMPTY_BINARY_VECTOR);
		}

		memcpy(_octets, cBinaryAddress.data(), IP_ADDRESS_OCTETS);
	} /* IPv4Address::SetFromBinary(const std::vector<uint8_t> &cBinaryAddress) */

	/**
	 * @brief Resets all octets of the IPv4 address to 0.
	 */
	void IPv4Address::Clear()
	{
		memset(_octets, 0, IP_ADDRESS_OCTETS);
	} /* IPv4Address::Clear() */

	/**
	 * @brief Overloads the << operator to enable output of the IPv4 address to an output stream.
	 * @param os The output stream to write to.
	 * @param address The IPv4 address to output.
	 * @return The output stream that was written to.
	 */
	std::ostream &operator<<(std::ostream &os, const IPv4Address &cAddress)
	{
		os << cAddress.ToString();
		return os;
	} /* operator<<(std::ostream &os, const IPv4Address &cAddress) */

	/**
	 * @brief Overloads the != operator to compare two IPv4 addresses for inequality.
	 * @param ip The IPv4 address to compare against.
	 * @return True if the IPv4 addresses are not equal, false otherwise.
	 */
	bool IPv4Address::operator!=(const IPv4Address &cIp) const
	{
		return memcmp(_octets, cIp._octets, IP_ADDRESS_OCTETS) != 0;
	} /* bool IPv4Address::operator!=(const IPv4Address &cIp) const */

	/**
	 * @brief Overloads the == operator for IPv4Address objects.
	 *
	 * Compares each octet of two IPv4Address objects for equality.
	 *
	 * @param ip An IPv4Address object to compare.
	 * @return True if all octets are equal, false otherwise.
	 */
	bool IPv4Address::operator==(const IPv4Address &cIp) const
	{
		return memcmp(_octets, cIp._octets, IP_ADDRESS_OCTETS) == 0;
	} /* bool IPv4Address::operator==(const IPv4Address &cIp) const */

	/**
	 * @brief Assignment operator for IPv4Address class.
	 * This operator assigns the value of another IPv4Address object to the current object.
	 * @param cIp The IPv4Address object to be assigned.
	 * @return A reference to the modified IPv4Address object.
	 */
	IPv4Address &IPv4Address::operator=(const IPv4Address &cIp)
	{
		if (this != &cIp) // If they aren't the same object
		{
			memcpy(this->_octets, cIp._octets, IP_ADDRESS_MAX_LENGTH);
		}

		return *this;
	} /* IPv4Address &IPv4Address::operator=(const IPv4Address &cIp) */

}

/******************************************************************************
**********************************End of file**********************************
******************************************************************************/