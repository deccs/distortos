/**
 * \file
 * \brief SpiMasterBase class header
 *
 * \author Copyright (C) 2016 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDE_DISTORTOS_DEVICES_COMMUNICATION_SPIMASTERBASE_HPP_
#define INCLUDE_DISTORTOS_DEVICES_COMMUNICATION_SPIMASTERBASE_HPP_

#include <cstddef>

namespace distortos
{

namespace devices
{

class SpiMasterErrorSet;

/**
 * SpiMasterBase class is an interface with callbacks for low-level SPI master driver, which can serve as a base for
 * high-level SPI master drivers
 *
 * \ingroup devices
 */

class SpiMasterBase
{
public:

	/**
	 * \brief SpiMasterBase's destructor
	 */

	virtual ~SpiMasterBase() = 0;

	/**
	 * \brief "Transfer complete" event
	 *
	 * Called by low-level SPI master driver when the transfer is physically finished.
	 *
	 * \param [in] errorSet is the set of error bits
	 * \param [in] bytesTransfered is the number of bytes transferred by low-level SPI master driver (read from write
	 * buffer and/or written to read buffer), may be unreliable if \a errorSet is not empty (i.e. transfer error was
	 * detected)
	 */

	virtual void transferCompleteEvent(SpiMasterErrorSet errorSet, size_t bytesTransfered) = 0;
};

}	// namespace devices

}	// namespace distortos

#endif	// INCLUDE_DISTORTOS_DEVICES_COMMUNICATION_SPIMASTERBASE_HPP_
