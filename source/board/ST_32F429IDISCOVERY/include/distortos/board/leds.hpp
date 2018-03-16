/**
 * \file
 * \brief Declaration of leds for ST,32F429IDISCOVERY
 *
 * \author Copyright (C) 2014-2018 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \warning
 * Automatically generated file - do not edit!
 */

#ifndef SOURCE_BOARD_ST_32F429IDISCOVERY_INCLUDE_DISTORTOS_BOARD_LEDS_HPP_
#define SOURCE_BOARD_ST_32F429IDISCOVERY_INCLUDE_DISTORTOS_BOARD_LEDS_HPP_

#include "distortos/distortosConfiguration.h"

#include <cstddef>

#ifdef CONFIG_BOARD_LEDS_LD3_ENABLE
#define DISTORTOS_BOARD_LEDS_LD3_ENABLED	1
#else	// !def CONFIG_BOARD_LEDS_LD3_ENABLE
#define DISTORTOS_BOARD_LEDS_LD3_ENABLED	0
#endif	// !def CONFIG_BOARD_LEDS_LD3_ENABLE

#ifdef CONFIG_BOARD_LEDS_LD4_ENABLE
#define DISTORTOS_BOARD_LEDS_LD4_ENABLED	1
#else	// !def CONFIG_BOARD_LEDS_LD4_ENABLE
#define DISTORTOS_BOARD_LEDS_LD4_ENABLED	0
#endif	// !def CONFIG_BOARD_LEDS_LD4_ENABLE

/// count of leds on the board
#define DISTORTOS_BOARD_LEDS_COUNT	(DISTORTOS_BOARD_LEDS_LD3_ENABLED + \
		DISTORTOS_BOARD_LEDS_LD4_ENABLED)

#if defined(CONFIG_BOARD_LEDS_ENABLE) && DISTORTOS_BOARD_LEDS_COUNT != 0

namespace distortos
{

namespace chip
{

class ChipOutputPin;

}	// namespace chip

namespace board
{

/// count of leds on the board
constexpr size_t ledsCount {DISTORTOS_BOARD_LEDS_COUNT};

/*---------------------------------------------------------------------------------------------------------------------+
| indexes of leds
+---------------------------------------------------------------------------------------------------------------------*/

enum
{
#ifdef CONFIG_BOARD_LEDS_LD3_ENABLE
		/// index of ld3 (green) from leds
		ledsLd3Index,
#endif	// def CONFIG_BOARD_LEDS_LD3_ENABLE
#ifdef CONFIG_BOARD_LEDS_LD4_ENABLE
		/// index of ld4 (red) from leds
		ledsLd4Index,
#endif	// def CONFIG_BOARD_LEDS_LD4_ENABLE
};

/*---------------------------------------------------------------------------------------------------------------------+
| alternative indexes of leds
+---------------------------------------------------------------------------------------------------------------------*/

#ifdef CONFIG_BOARD_LEDS_LD3_ENABLE

/// alternative index of ld3 (green) from leds
constexpr size_t ledsGreenIndex {ledsLd3Index};

#endif	// def CONFIG_BOARD_LEDS_LD3_ENABLE

#ifdef CONFIG_BOARD_LEDS_LD4_ENABLE

/// alternative index of ld4 (red) from leds
constexpr size_t ledsRedIndex {ledsLd4Index};

#endif	// def CONFIG_BOARD_LEDS_LD4_ENABLE

/*---------------------------------------------------------------------------------------------------------------------+
| indexed access to leds objects
+---------------------------------------------------------------------------------------------------------------------*/

/// array with all leds objects
extern chip::ChipOutputPin leds[ledsCount];

}	// namespace board

}	// namespace distortos

#endif	// defined(CONFIG_BOARD_LEDS_ENABLE) && DISTORTOS_BOARD_LEDS_COUNT != 0

#endif	// SOURCE_BOARD_ST_32F429IDISCOVERY_INCLUDE_DISTORTOS_BOARD_LEDS_HPP_
