/******************************************************************************
 * @file      fuses.c
 * @author    Paul Contis
 * @date      2026-03-08
 * @brief     Implementation of the module logic
 * @details   Detailed logic and hardware interaction notes.
 * @note      Target: ATtiny1616
 * @copyright (c) 2026 DIY for Geeks. All rights reserved.
 ******************************************************************************/

/*----------------------------------------------------------------------------*
 * MODULE HEADER
 *----------------------------------------------------------------------------*/
//#include "fuses.h"
/*----------------------------------------------------------------------------*
 * PRIVATE INCLUDES
 *----------------------------------------------------------------------------*/
#include <avr/io.h>      
#include <avr/fuse.h>    
#include "config.h"
/*----------------------------------------------------------------------------*
 * PRIVATE CONSTANTS & MACROS
 *----------------------------------------------------------------------------*/
/* Configuration for Secure Bootloader */
FUSES = {
    //.WDTCFG = FUSE_WDP_8MS_gc,      // Watchdog: Useful for forcing reset if NFC fails ?TBD
    //.BODCFG = FUSE_ACTIVE_ENABLED_gc | FUSE_LVL_BODLEVEL0_gc, // Brown-out: Protects Flash
    //.OSCCFG = FUSE_FREQSEL_20MHZ_gc, // Set internal oscillator to 20MHz for Ed25519 ? TBD
    
    /* --- Partitioning Logic --- */
    .BOOTEND = BOOTEND_VALUE,                // 4KB Bootloader (16 * 256 bytes)
    .APPEND  = APPEND_VALUE               // Metadata starts at last 512 bytes (62 * 256)
    
    // SECURITY: Leave this commented out until your final submission!
    // .LOCKBIT = FUSE_LB_RWLOCK_gc, // Prevents reading or writing via UPDI
};

/*----------------------------------------------------------------------------*
 * PRIVATE TYPEDEFS & STRUCTURES
 *----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*
 * PRIVATE VARIABLES (STATIC DATA)
 *----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*
 * PRIVATE FUNCTION PROTOTYPES (STATIC)
 *----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*
 * PUBLIC FUNCTION IMPLEMENTATIONS
 *----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*
 * PRIVATE FUNCTION IMPLEMENTATIONS
 *----------------------------------------------------------------------------*/





