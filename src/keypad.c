/**
 * @file keypad.c
 * @author Mohamed Hassanin
 * @brief Keypad interface pattern that is commonly used in 
 * embedded systems projects 
 * @version 0.1
 * @date 2021-03-19
 */
/******************************************************************************
* Includes
******************************************************************************/
#include <inttypes.h>
#include "keypad.h"
#include "circ_buffer.h" 
/******************************************************************************
* Module Variable Definitions
******************************************************************************/

/**
 * @brief A pointer to the configuration table.
 */
static KeypadConfig_t * gConfig; 

/**
 * brief the keypad receive data buffers
 */
static uint8_t KeypadData[KEYPAD_MAX][KEYPAD_RCV_BUFF_SIZE];

/**
 * brief the keypad receive buffers structures
 */
static CircBuff_t KeypadBuff[KEYPAD_MAX];

/**
 * @brief an array to hold the last state of the keypad switches
 */
static SWState_t LastState[KEYPAD_MAX][KEYPAD_WIDTH_X_HEIGHT];

/******************************************************************************
* Function : Keypad_Init()
*//**
* \b Description: Initialization function for the Keypad module<br/>
* \b PRE-CONDITION: Configuration table is populated<br/>
* @param Config a pointer to the configuration table of the keypads.
* @return void 
******************************************************************************/
extern void 
Keypad_Init(KeypadConfig_t* const Config)
{
  if(Config == 0x0)
    {
      //TODO: choose your error handling method
      return;
    }

  gConfig = Config;

  for(uint8_t i = 0; i < KEYPAD_MAX; i++)
    {
      KeypadBuff[i] = CircBuff_Create(KeypadData[i], KEYPAD_RCV_BUFF_SIZE);

      //make sure the initial state is released
      for(uint8_t sw = 0; sw < KEYPAD_WIDTH_X_HEIGHT; sw++)
        {
          LastState[i][sw] = SW_RELEASED;
        }
    }
}


/***************************** END OF FILE ***********************************/
