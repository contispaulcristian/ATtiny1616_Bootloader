#ifndef CONFIG_H
#define CONFIG_H

/* --- Bootloader Memory Map --- */
/* The ATtiny1616 has 16KB of total flash. */
/* First 2KB (0x0800 bytes) reserved for this bootloader. */
#define APP_START_ADDR    0x0800U     
#define FLASH_PAGE_SIZE   64U         

/* --- NFC & Transfer Settings --- */
#define CHUNK_SIZE        256U       /* Size of ST25DV FTM SRAM Mailbox Buffer (exactly 4 flash pages) */
#define ST25DV_I2C_ADDR   /*TBD*/       /* 7-bit I2C address of the ST25DV (adjust if needed) */
#define FTM_MAILBOX_REG   0x2008U    /* ST25DV Mailbox register base address */

/* --- Hardware Pins --- */



#endif /* CONFIG_H */