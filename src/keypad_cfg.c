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
#include "SW_cfg.h"

/**********************************************************************
* Module Variable Definitions
**********************************************************************/
static KeypadConfig_t KeypadConfig[KEYPAD_MAX] = {
  {
    .Keypad = KEYPAD_0, 
    .Switches = 
    {
      SW_0, SW_1, SW_2,
      SW_2, SW_3, SW_4,
      SW_5, SW_6, SW_7
    }
  }
};

/**********************************************************************
* Function Definitions
**********************************************************************/
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
