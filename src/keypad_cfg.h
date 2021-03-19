/**
 * @file keypad_cfg.h
 * @author Mohamed Hassanin
 * @brief Keypad interface pattern that is commonly used in 
 * embedded systems projects
 * @version 0.1
 * @date 2021-03-18
 */

#ifndef KEYPAD_CFG_H
#define KEYPAD_CFG_H
/**********************************************************************
* Includes
**********************************************************************/
#include "circ_buffer.h"
#include "SW.h"
/**********************************************************************
* Definitions
**********************************************************************/
#define KEYPAD_RCV_BUFF_SIZE 30

#define KEYPAD_WIDTH_X_HEIGHT 9
/**********************************************************************
* Typedefs
**********************************************************************/
/**
 * @brief an enumerated 
 */
typedef enum
{
  KEYPAD_0,
  KEYPAD_MAX
} Keypad_t;

typedef struct 
{
  Keypad_t Keypad;
  SW_t Switches[KEYPAD_WIDTH_X_HEIGHT];
} KeypadConfig_t;
/**********************************************************************
* Function Prototypes
**********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

extern KeypadConfig_t* const Keypad_GetConfig(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* KEYPAD_CFG_H */
/***************************** END OF FILE ***********************************/
