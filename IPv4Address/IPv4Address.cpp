/**
 * @file IPv4Address.cpp
 * @author Karol Pisarski (karol.pisarski@outlook.com)
 * @brief IPv4Address ethernet parameter class implementation.
 * @version 0.1
 * @date 2023-05-19
 *
 * @copyright Copyright (c) 2023
 */
#include "IPv4Address.hpp"
#include <cstring>
#include <string>
#include <sstream>

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
 * @brief Constructor for the IPv4Address class that accepts a string representation of an IPv4 address.
 * @param addressStr A string representation of an IPv4 address (e.g. "192.168.0.1").
 */
IPv4Address::IPv4Address(const std::string &cAddressStr)
{
	std::string byteStr;
	uint8_t byteCount = 0;

	for (const char &octet : cAddressStr)
	{
		if (octet == DOT)
		{
			// convert byte_str to int and add to address_bytes
			_octets[byteCount] = std::stoi(byteStr);
			byteStr.clear();
			byteCount++;
		}
		else
		{
			byteStr += octet;
		}
	}
	// add last byte to address_bytes
	_octets[byteCount] = std::stoi(byteStr);
}

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
}

/**
 * @brief Converts the IPv4 address to a string representation.
 * @return A string representation of the IPv4 address.
 */
std::string IPv4Address::ToString() const
{
	std::string result{};
	if (*_octets != NULL)
	{
		for (uint8_t i = 0; i < IP_ADDRESS_OCTETS; i++)
		{
			result += std::to_string(_octets[i]);

			if (i != 3)
				result += DOT;
		}
	}

	return result;
}

/**
 * @brief Resets all octets of the IPv4 address to 0.
 */
void IPv4Address::Clear()
{
	for (uint8_t i = 0; i < IP_ADDRESS_OCTETS; i++)
		_octets[i] = 0;
}

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
}

/**
 * @brief Overloads the != operator to compare two IPv4 addresses for inequality.
 * @param ip The IPv4 address to compare against.
 * @return True if the IPv4 addresses are not equal, false otherwise.
 */
bool IPv4Address::operator!=(const IPv4Address &cIp) const
{
	for (uint8_t i = 0; i < IP_ADDRESS_OCTETS; i++)
	{
		if (_octets[i] != cIp._octets[i])
			return true;
	}
}

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
	for (uint8_t i = 0; i < IP_ADDRESS_OCTETS; i++)
	{
		if (_octets[i] != cIp._octets[i])
			return false;
	}
	return true;
}


IPv4Address& IPv4Address::operator=(const IPv4Address& cIp)
{
	if(this == &cIp)	// If they are the same object
		return *this;

	// TODO Check if the last octet contains some data
	memcpy(this->_octets, cIp._octets, IP_ADDRESS_MAX_LENGTH);
	return *this;
}


/**
 * @brief Returns the octet at the specified index.
 *
 * @param index The index of the octet to retrieve.
 * @return The value of the octet at the specified index.
 */
uint8_t IPv4Address::getOctet(const uint8_t &cIndex) const
{
	return _octets[cIndex];
}

/**
 * @brief Sets the octet at the specified index to the specified value.
 *
 * @param index The index of the octet to set.
 * @param value The value to set the octet to.
 */
void IPv4Address::setOctet(const uint8_t &cIndex, const uint8_t &cValue)
{
	_octets[cIndex] = cValue;
}
/******************************************************************************
**********************************End of file**********************************
******************************************************************************/