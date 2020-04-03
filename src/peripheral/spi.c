/*!
 * @file
 * @brief
 */

#include "stm8s_clk.h"
#include "spi.h"

#ifdef SPI

enum {
  mode_write,
  mode_read
};
typedef uint8_t mode_t;

static struct {
  i_tiny_spi_t interface;

  mode_t mode;
  void* context;

  union {
    tiny_spi_write_callback_t write;
    tiny_spi_read_callback_t read;
  } callback;
} self;

void spi_isr(void) __interrupt(ITC_IRQ_SPI) {
  // Disable RX, TX interrupts
  SPI->ICR = 0;

  if(self.mode == mode_write) {
    self.callback.write(self.context);
  }
  else if(self.mode = mode_read) {
    self.callback.read(self.context, SPI->DR);
  }
}

static void write(i_tiny_spi_t* _self, uint8_t byte, tiny_spi_write_callback_t callback, void* context) {
  (void)_self;

  self.mode = mode_write;
  self.callback.write = callback;
  self.context = context;

  // Enable TX interrupt
  SPI->ICR = SPI_ICR_TXEI;

  // Write byte
  SPI->DR = byte;
}

static void read(i_tiny_spi_t* _self, tiny_spi_read_callback_t callback, void* context) {
  (void)_self;

  self.mode = mode_read;
  self.callback.read = callback;
  self.context = context;

  // Enable RX interrupt
  SPI->ICR = SPI_ICR_RXEI;

  // Write garbage byte to clock in result
  SPI->DR = 0;
}

static const i_tiny_spi_api_t api = { write, read };

i_tiny_spi_t* spi_init(uint8_t cpol, uint8_t cpha, bool msb_first, spi_baud_t baud) {
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
