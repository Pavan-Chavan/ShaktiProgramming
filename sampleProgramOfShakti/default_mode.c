/***************************************************************************
* Project                               : shakti devt board
* Name of the file                      : xadc_default.c
* Brief Description of file             : Demonstrates the usage of onchip xadc.
* Name of Author                        : Sathya Narayanan
* Email ID                              : sathya281@gmail.com

 Copyright (C) 2020  IIT Madras. All rights reserved.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.

***************************************************************************/
/**
@file xadc_default.c
@brief  write data to flash by xadc
@detail Contains driver codes to read and write flash using SPI interface.
*/

#include <stdint.h>
#include "xadc_driver.h"
#include "uart.h"

/** 
 * @fn int main()
 * @brief Calls the xadc apis to read temperature and onchip voltage.
 * @return none
 */
void main()
{
	while(1)
	{
		uint32_t value = xadc_read_data(0x41200);

		printf("value = %f\n", xadc_onchip_temp(value));

		value = xadc_read_data(0x41204);
		printf("value = %f\n", xadc_onchip_voltage(value));
	}
}
