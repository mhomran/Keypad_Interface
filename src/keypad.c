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
#include "SW.h"
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
static SWState_t LastState[KEYPAD_MAX][KEYPAD_LONGEST_COL];

/**
 * @brief The keypad characters
 * //TODO: add the characters of your keypad set.
 */
static const uint8_t KeypadSet[KEYPAD_3_X_3] =
{
  '0', '1', '2',
  '3', '4', '5',
  '6', '7', '8'
};
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

  uint8_t Col;
  uint8_t Keypad;

  gConfig = Config;

  for(Keypad = 0; Keypad < KEYPAD_MAX; Keypad++)
    {
      KeypadBuff[Keypad] = CircBuff_Create(KeypadData[Keypad],
       KEYPAD_RCV_BUFF_SIZE);

      //the initial state of columns switches is released
      for(Col = 0; Col < gConfig[Keypad].ColsSize; Col++)
        {
          LastState[Keypad][Col] = SW_RELEASED;
        }
    }
}

/***************************** END OF FILE ***********************************/
