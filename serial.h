/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#ifndef _TINIX_SERIAL_H_
#define _TINIX_SERIAL_H_

#include "types.h"
#include "x86.h"

/*
 * I/O ports
 * -------------------------------------------------------------------
 * All the I/O ports are calculated relative to the data port. This is
 * because all serial ports (COM1, COM2, COM3, COM4) have their ports
 * in the same order, but they start at different values.
 */

#define SERIAL_COM1_BASE                  0x3F8

#define SERIAL_DATA_PORT(base)            (base)
#define SERIAL_FIFO_CMD_PORT(base)        ((base) + 2)
#define SERIAL_LINE_CMD_PORT(base)        ((base) + 3)
#define SERIAL_MODEM_CMD_PORT(base)       ((base) + 4)
#define SERIAL_LINE_STATUS_PORT(base)     ((base) + 5)

/*
 * I/O port command
 * ---------------------------------------------------------------
 * Tells the serial port to expect first the highest 8 bits on the
 * data port, then the lowest 8 bits will follow.
 */

#define SERIAL_LINE_ENABLE_DLAB           0x80

void serial_configure_baud_rate(ushort com, ushort divisor);
void serial_configure_line(uint16 com);
uint serial_is_line_buf_empty(uint16 com);
void serial_init(void);
void serial_write(const char * buf, uint64 len);

#endif /* _TINIX_SERIAL_H_ */
