/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#include "serial.h"

/** serial_configure_baud_rate:
 *  Sets the seed of the data being sent. The default speed of a serial
 *  port is 115200 bits/sec. The argument is a divisor of that number,
 *  hence the resulting speed becomes (115200 / divisor) bits/sec.
 *
 *  @param com        The COM port to configure
 *  @param divisor    The divisor
 */

void serial_configure_baud_rate(uint16 com, uint16 divisor)
{
  uint8 lcr;

  lcr = inb(SERIAL_LINE_CMD_PORT(com));

  outb(SERIAL_LINE_CMD_PORT(com), lcr | SERIAL_LINE_ENABLE_DLAB);
  outb(SERIAL_DATA_PORT(com), divisor & 0x00ff);
  outb(SERIAL_DATA_PORT(com + 1), (divisor >> 8) & 0x00ff);

  outb(SERIAL_LINE_CMD_PORT(com), lcr);
}

/** serial_configure_line:
 *  Configures the line fo the given port. The port is set to have
 *  a data length of 8 bits, no parity, stop bit and break control
 *  disabled
 *
 *  @param com        The serial port to configure
 */

void serial_configure_line(uint16 com)
{
  /*
   * Value:   | 0 | 0 | 0 0 0 | 0 | 1 1 | = 0x03
   */
   outb(SERIAL_LINE_CMD_PORT(com), 0x03);
}

/** serial_is_line_buf_empty:
 *  Checks if the transmission buffer is empty (i.e., data can be
 *  transmitted).
 *
 *  @param com        The serial port for checking status
 */

uint serial_is_line_buf_empty(uint16 com)
{
  return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x02;
}

/** serial_init:
 *  Intializes SERIAL_COM1_BASE
 */
void serial_init(void)
{
  serial_configure_baud_rate(SERIAL_COM1_BASE, 3);
  serial_configure_line(SERIAL_COM1_BASE);
}

/** serial_write:
 *  Writes data to the port : SERIAL_COM1_BASE
 *
 *  @param buf        The buffer containing the data
 *  @param len        The length of the buffer
 */

void serial_write(const char * buf, uint64 len)
{
  for (uint64 i = 0; i < len; i++)
  {
    while (serial_is_line_buf_empty(SERIAL_COM1_BASE))
      continue;

    outb(SERIAL_DATA_PORT(SERIAL_COM1_BASE), buf[i]);
  }
}
