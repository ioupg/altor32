#ifndef __MEM_MAP_H__
#define __MEM_MAP_H__

//-----------------------------------------------------------------
// Defines:
//-----------------------------------------------------------------
#define INT_BASE			0x00000000
#define INT_APP_BASE        0x00002000
#define EXT_BASE			0x10000000
#define IO_BASE				0x20000000

//-----------------------------------------------------------------
// Macros:
//-----------------------------------------------------------------
#define REG8				(volatile unsigned char*)
#define REG16				(volatile unsigned short*)
#define REG32				(volatile unsigned int*)

//-----------------------------------------------------------------
// I/O:
//-----------------------------------------------------------------

// General
#define CORE_ID				(*(REG32 (IO_BASE + 0x0)))

// Basic Peripherals
#define UART_USR			(*(REG32 (IO_BASE + 0x4)))
#define UART_UDR			(*(REG32 (IO_BASE + 0x8)))
#define TIMER_VAL			(*(REG32 (IO_BASE + 0x10)))
#define IRQ_MASK_SET		(*(REG32 (IO_BASE + 0x14)))
#define IRQ_MASK_STATUS		(*(REG32 (IO_BASE + 0x14)))
#define IRQ_MASK_CLR		(*(REG32 (IO_BASE + 0x18)))
#define IRQ_STATUS			(*(REG32 (IO_BASE + 0x1C)))
	#define IRQ_SYSTICK			(0)
	#define IRQ_UART_RX_AVAIL   (1)
	#define IRQ_SW			    (2)
	#define IRQ_PIT				(6)
	#define EXT_INT_OFFSET		(8)

// [Optional] Watchdog
#define WATCHDOG_CTRL		(*(REG32 (IO_BASE + 0x20)))
	#define WATCHDOG_EXPIRED	(16)

#define SYS_CLK_COUNT		(*(REG32 (IO_BASE + 0x60)))

// SPI Configuration PROM
#define SPI_PROM_CTRL		(*(REG32 (IO_BASE + 0x70)))
    #define SPI_PROM_CS			(1 << 0)
#define SPI_PROM_STAT		(*(REG32 (IO_BASE + 0x70)))
	#define SPI_PROM_BUSY		(1 << 0)
#define SPI_PROM_DATA		(*(REG32 (IO_BASE + 0x74)))

#endif 
