/*
 * map.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Windows 11
 */


#include "STD_TYPES.h"
#include "map.h"

sint32 Map(sint32 InputMin,sint32 InputMax,sint32 OutputMin,sint32 OutputMax,sint32 InputValue)
{

    return (((OutputMax - OutputMin) * (InputValue - InputMin)) / (InputMax - InputMin)) + OutputMin ;
}
