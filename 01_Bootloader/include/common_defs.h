/******************************************************************************
 * @file      common_defs.h
 * @author    Paul Contis
 * @date      2026-03-08
 * @brief     Public API for the module
 * @details   Describe the architectural role and usage of this module.
 * @note      Target: ATtiny1616 | Clock: 20MHz
 * @copyright (c) 2026 DIY for Geeks. All rights reserved.
 ******************************************************************************/

#ifndef COMMON_DEFS_H
#define COMMON_DEFS_H

/* --- Standard Includes --- */
#include <stdint.h>
#include <stdbool.h>

/*----------------------------------------------------------------------------*
 * PUBLIC CONSTANTS & MACROS
 *----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*
 * PUBLIC TYPEDEFS & STRUCTURES
 *----------------------------------------------------------------------------*/
/* --- The Manifest (The Passport) --- */
/* This structure MUST be at the very top of every game (.bin file) */
typedef struct {
    uint32_t magic;          // Must be 0x544F4F42 ("BOOT")
	uint8_t  game_id;
    uint16_t version;        // Version of the game (e.g., 0x0102 = v1.2)
    uint16_t app_size;       // Total size of game binary in bytes
    //uint16_t crc_checksum;   // CRC-16 of the ENTIRE app (for final check)
    uint8_t  reserved[6];    // Space for future keys/signatures
} AppHeader_t;

/*----------------------------------------------------------------------------*
 * PUBLIC FUNCTION PROTOTYPES
 *----------------------------------------------------------------------------*/


#endif /* COMMON_DEFS_H */

