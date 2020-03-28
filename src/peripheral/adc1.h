/*!
 * @file
 * @brief
 */

#ifndef adc1_h
#define adc1_h

#include "stm8s.h"
#include "i_tiny_adc_group.h"

#ifdef ADC1

i_tiny_adc_group_t* adc1_init(void);

#endif

#endif
