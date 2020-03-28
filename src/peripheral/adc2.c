/*!
 * @file
 * @brief
 */

#include "stm8s_clk.h"
#include "adc2.h"

#ifdef ADC2

static i_tiny_adc_group_t self;

static tiny_adc_counts_t read(i_tiny_adc_group_t* _self, tiny_adc_channel_t channel) {
  (void)_self;

  // Select the specified channel and clear EOC
  ADC2->CSR = channel;

  // Start the conversion
  ADC2->CR1 |= ADC2_CR1_ADON;

  // Wait for the conversion to complete
  while(!(ADC2->CSR & ADC2_CSR_EOC)) {
  }

  // Read DRL first and shift 6 to normalize from 10-bit to 16-bit
  tiny_adc_counts_t result = ADC2->DRL << 6;
  // Read DRH second and shift 8 + 6 to normalize
  result += ADC2->DRH << 14;
  return result;
}

static const i_tiny_adc_group_api_t api = { read };

i_tiny_adc_group_t* adc2_init(void) {
  // Un-gate clock for ADC2
  CLK->PCKENR2 |= (1 << (CLK_PERIPHERAL_ADC & 0xF));

  // Right-align the result
  ADC2->CR2 = ADC2_CR2_ALIGN;

  // Power on the peripheral
  ADC2->CR1 = ADC2_CR1_ADON;

  self.api = &api;

  return &self;
}

#endif
