/******************************************************************************
 * @file      st25_ftm.h
 * @author    Paul Contis
 * @date      2026-03-08
 * @brief     Public API for the module
 * @details   Describe the architectural role and usage of this module.
 * @note      Target: ATtiny1616 | Clock: 20MHz
 * @copyright (c) 2026 DIY for Geeks. All rights reserved.
 ******************************************************************************/

#ifndef ST25_FTM_H
#define ST25_FTM_H

/* --- Standard Includes --- */
#include <stdint.h>
#include <stdbool.h>

/*----------------------------------------------------------------------------*
 * PUBLIC CONSTANTS & MACROS
 *----------------------------------------------------------------------------*/
// Simplified ST25FTM for ATtiny1616
#define FTM_CONTROL_BYTE_IDX    0
#define FTM_SEQUENCE_BYTE_IDX   1
#define FTM_PAYLOAD_START_IDX   2
#define FTM_PAYLOAD_LEN         252 // (256 - 2 header - 2 CRC)


/*----------------------------------------------------------------------------*
 * PUBLIC TYPEDEFS & STRUCTURES
 *----------------------------------------------------------------------------*/
typedef enum {
    FTM_STATE_IDLE,
    FTM_STATE_TRANSFERRING,
    FTM_STATE_VERIFYING,
    FTM_STATE_COMPLETE
} ftm_state_t;


/*----------------------------------------------------------------------------*
 * PUBLIC FUNCTION PROTOTYPES
 *----------------------------------------------------------------------------*/


#endif /* ST25_FTM_H */

