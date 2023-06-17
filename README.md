# Ethernet Parameters
The Ethernet parameters play a crucial role in establishing network connectivity and facilitating communication between devices. This code aims to provide a clear understanding of these parameters and their significance within the project.

I didn't use inheritance in the project because when I need libraries, I take individual files!

Please note that this library may not be memory-efficient, and it is important to consider its usage on microcontrollers or resource-constrained devices. If you intend to use this library on such platforms, it is advisable to carefully assess its memory requirements and consider rewriting or optimizing the code to ensure efficient memory utilization! Especially, I am using the sstream library that weighs way too much!

# Introduction
Ethernet is a widely used networking technology that enables devices to connect and communicate within a local area network (LAN). In this project, Ethernet parameters are utilized to store in memory and configure network settings used in network connections.

# IPv4 Address
The IPv4 address is a 32-bit numerical identifier assigned to each device connected to a network. It serves as a unique identifier for the device and allows it to send and receive data over an IPv4-based network. The IPv4 address is typically represented in dot-decimal notation (e.g., 192.168.0.1), where each octet represents 8 bits of the address.

# IPv6 Address

In addition to IPv4 addresses, IPv6 addresses are also used to identify devices on a network. IPv6 addresses are 128-bit numerical identifiers and are represented in hexadecimal format.

An IPv6 address is typically represented as eight groups of four hexadecimal digits, separated by colons (e.g., 2001:0db8:85a3:0000:0000:8a2e:0370:7334). Conventions are applied to make IPv6 addresses more manageable, such as omitting leading zeros within each group and replacing consecutive groups of zeros with a double colon (::).

Ethernet Parameters and IPv6

When configuring network settings, Ethernet parameters play a vital role in establishing connectivity and enabling communication over IPv6 networks. These parameters include the IPv6 address, along with other network-related settings such as subnet mask, default gateway, and DNS server addresses.

To utilize IPv6 within your project, ensure that the Ethernet parameters correctly store and configure the IPv6 address assigned to the device. This address should be obtained from the network's IPv6 addressing scheme, which may involve manual assignment or dynamic allocation through protocols like DHCPv6 (Dynamic Host Configuration Protocol for IPv6).

Remember to adapt your code to handle the longer IPv6 address format and consider any specific requirements or restrictions imposed by the networking environment in which your project operates.

By incorporating proper handling of Ethernet parameters, including the IPv6 address, your project can effectively establish connectivity and communicate with other devices within an IPv6 network.

# BSD 3-Clause License

Copyright (c) 2023, Karol Pisarski

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
