/*!
 * @file
 * @brief
 */

#include "stm8s_clk.h"
#include "spi.h"

#ifdef SPI

static struct {
  i_tiny_async_spi_t interface;
  void* context;
  tiny_async_spi_callback_t callback;
} self;

void spi_isr(void) __interrupt(ITC_IRQ_SPI) {
  // Disable interrupts
  SPI->ICR = 0;

  self.callback(self.context, SPI->DR);
}

static void transfer(i_tiny_async_spi_t* _self, uint8_t byte, tiny_async_spi_callback_t callback, void* context) {
  (void)_self;

  self.callback = callback;
  self.context = context;

  // Enable RX interrupt
  SPI->ICR = SPI_ICR_RXEI;

  // Write byte
  SPI->DR = byte;
}

static const i_tiny_async_spi_api_t api = { transfer };

i_tiny_async_spi_t* spi_init(uint8_t cpol, uint8_t cpha, bool msb_first, spi_baud_t baud) {
  // Un-gate clock for SPI
  CLK->PCKENR1 |= (1 << CLK_PERIPHERAL_SPI);

  // Enable peripheral in master mode
  SPI->CR1 = SPI_CR1_SPE | SPI_CR1_MSTR | (baud << 3);

  if(!msb_first) {
    SPI->CR1 |= SPI_CR1_LSBFIRST;
  }

  if(cpol) {
    SPI->CR1 |= SPI_CR1_CPOL;
  }

  if(cpha) {
    SPI->CR1 |= SPI_CR1_CPHA;
  }

  self.interface.api = &api;

  return &self.interface;
}

#endif
