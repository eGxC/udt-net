/*****************************************************************
 *
 * BSD LICENCE (http://www.opensource.org/licenses/bsd-license.php)
 *
 * Copyright (c) 2010, Cory Thomas
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *   * Neither the name of the <ORGANIZATION> nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ****************************************************************/

#pragma once

class CPacket;

namespace Udt
{
	enum PacketType;

	/// <summary>
	/// UDT data packet.
	/// </summary>
	public ref class Packet
	{
	private:
		const CPacket* _packet;
		bool _deletePacket;

		void AssertNotDisposed();

	internal:

		/// <summary>
		/// Initialize a new instance.
		/// </summary>
		/// <param name="packet">Native packet to wrap.</param>
		/// <param name="deletePacket">
		/// True to delete the native <paramref name="packet"/> when this object
		/// is disposed.
		/// </param>
		Packet(const CPacket* packet, bool deletePacket);

	public:
		~Packet(void);

		/// <summary>
		/// Get the payload or the control information field length.
		/// </summary>
		property int Length { int get(void); }
		
		/// <summary>
		/// Get the packet type.
		/// </summary>
		property Udt::PacketType PacketType { Udt::PacketType get(void); }

		/// <summary>
		/// Get whether the packet was sent with in-order delivery.
		/// </summary>
		/// <value>True if the packet was sent in order</value>
		property bool InOrderDelivery { bool get(void); }

		/// <summary>
		/// Get the message sequence number.
		/// </summary>
		property int MessageSequenceNumber { int get(void); }
	};
}