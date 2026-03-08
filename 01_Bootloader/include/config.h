/******************************************************************************
 * @file      config.h
 * @author    Paul Contis
 * @date      2026-03-08
 * @brief     Public API for the module
 * @details   Describe the architectural role and usage of this module.
 * @note      Target: ATtiny1616 | Clock: 20MHz
 * @copyright (c) 2026 DIY for Geeks. All rights reserved.
 ******************************************************************************/

#ifndef CONFIG_H
#define CONFIG_H

/* --- Standard Includes --- */
#include <stdint.h>
#include <stdbool.h>

/*----------------------------------------------------------------------------*
 * PUBLIC CONSTANTS & MACROS
 *----------------------------------------------------------------------------*/
/* --- Clock Management --- */
#ifndef F_CPU
#define F_CPU                  20000000UL  /* The "Truth" the compiler uses */
#endif
#define CLK_PRESCALER_DIV6     0x05        /* Value for 3.3MHz (20/6) */
#define CLK_PRESCALER_OFF      0x00        /* Value for 20MHz (20/1) */

/* --- Bootloader Memory Map --- */
/* ATtiny1616: 16KB Flash starting at 0x8000 */
/* First 4KB (0x1000 bytes) reserved for this bootloader. */
#define BOOTLOADER_SIZE_BYTES  4096U    
#define APP_START_ADDR         0x9000U  /* Unified Address for Jump */
#define BOOTEND_VALUE          (BOOTLOADER_SIZE_BYTES / 256) /* 0x10U - (4096 / 256) = 16 blocks */ 
#define APPEND_VALUE           0x38U    /* (14336 / 256) = 56 blocks */

#define FLASH_PAGE_SIZE        128U     /* Hardware page size for ATtiny1616 */

/* --- NFC & Transfer Settings --- */
#define CHUNK_SIZE             256U     /* ST25DV FTM Buffer = 2 Flash Pages */
#define ST25DV_ADDR_SYS        0x57U    /* I2C Address for Mailbox/Registers */
#define ST25DV_ADDR_USER       0x53U    /* I2C Address for User EEPROM */

/* --- Hardware Pins (Change based on your PCB) --- */
#define PIN_GPO                PIN2_bm  /* Example: PA2 for GPO interrupt */
#define PORT_GPO               PORTA    

/* --- Security Definitions --- */
//#define PUBLIC_KEY_SIZE        32U      /* Ed25519 Public Key length */
//#define SIGNATURE_SIZE         64U      /* Ed25519 Signature length */


/*----------------------------------------------------------------------------*
 * PUBLIC TYPEDEFS & STRUCTURES
 *----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*
 * PUBLIC FUNCTION PROTOTYPES
 *----------------------------------------------------------------------------*/





#endif /* CONFIG_H */