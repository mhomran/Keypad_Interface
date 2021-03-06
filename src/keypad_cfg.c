/**
 * @file keypad_cfg.c
 * @author Mohamed Hassanin
 * @brief Keypad interface pattern that is commonly used in 
 * embedded systems projects
 * @version 0.1
 * @date 2021-03-19
 */

/******************************************************************************
* Includes
******************************************************************************/
#include "keypad_cfg.h"
#include "dio_cfg.h"

/******************************************************************************
* Module Variable Definitions
******************************************************************************/
static KeypadConfig_t KeypadConfig[KEYPAD_MAX] = {
  {
    .Keypad = KEYPAD_0, 
    
    .Cols = 
    {
      PORTA_0, PORTA_1, PORTA_2
    },
    .ColsSize = 3,

    .Rows = 
    {
      PORTA_3, PORTA_4, PORTA_5
    },
    .RowsSize = 3
  }
};

/******************************************************************************
* Function Definitions
******************************************************************************/
/**
 * @brief return the configuration structure holding the 
 * configuration table of the module
 */
KeypadConfig_t* const
Keypad_GetConfig(void)
{
  return KeypadConfig;
}
/***************************** END OF FILE ***********************************/
