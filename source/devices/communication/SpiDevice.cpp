/**
 * \file
 * \brief SpiDevice class implementation
 *
 * \author Copyright (C) 2016-2018 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "distortos/devices/communication/SpiDevice.hpp"

#include "distortos/devices/communication/SpiDeviceProxy.hpp"
#include "distortos/devices/communication/SpiDeviceSelectGuard.hpp"
#include "distortos/devices/communication/SpiMaster.hpp"
#include "distortos/devices/communication/SpiMasterProxy.hpp"

#include "distortos/internal/CHECK_FUNCTION_CONTEXT.hpp"

#include <cerrno>

namespace distortos
{

namespace devices
{

/*---------------------------------------------------------------------------------------------------------------------+
| public functions
+---------------------------------------------------------------------------------------------------------------------*/

SpiDevice::~SpiDevice()
{
	CHECK_FUNCTION_CONTEXT();

	if (openCount_ == 0)
		return;

	const Proxy proxy {*this};

	spiMaster_.close();
}

int SpiDevice::close()
{
	const Proxy proxy {*this};

	if (openCount_ == 0)	// device is not open anymore?
		return EBADF;

	if (openCount_ == 1)	// last close?
	{
		const auto ret = spiMaster_.close();
		if (ret != 0)
			return ret;
	}

	--openCount_;
	return 0;
}

std::pair<int, size_t> SpiDevice::executeTransaction(const SpiMasterOperationsRange operationsRange)
{
	const Proxy proxy {*this};
	SpiMasterProxy spiMasterProxy {proxy};

	{
		const auto ret = spiMasterProxy.configure(mode_, maxClockFrequency_, wordLength_, lsbFirst_, {});
		if (ret.first != 0)
			return {ret.first, {}};
	}

	const SpiDeviceSelectGuard spiDeviceSelectGuard {spiMasterProxy};

	return spiMasterProxy.executeTransaction(operationsRange);
}

int SpiDevice::open()
{
	const Proxy proxy {*this};

	if (openCount_ == std::numeric_limits<decltype(openCount_)>::max())	// device is already opened too many times?
		return EMFILE;

	if (openCount_ == 0)	// first open?
	{
		const auto ret = spiMaster_.open();
		if (ret != 0)
			return ret;
	}

	++openCount_;
	return 0;
}

}	// namespace devices

}	// namespace distortos
