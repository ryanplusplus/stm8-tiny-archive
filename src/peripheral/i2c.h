/*!
 * @file
 * @brief
 */

#ifndef i2c_h
#define i2c_h

#include "stm8s.h"
#include "stm8s_itc.h"
#include "hal/i_tiny_async_i2c.h"

#ifdef I2C

i_tiny_async_i2c_t* i2c_init(void);

void i2c_isr(void) __interrupt(ITC_IRQ_I2C);

#endif

#endif
