/**
 * @file TestKeypad.c
 * @author Mohamed Hassanin
 * @brief The test file for the Keypad module.
 * @version 0.1
 * @date 2021-03-19
 */
/*****************************************************************************
* Includes
******************************************************************************/
/// @cond NODOC
/* Include Unity */
#include <stdio.h>
#include "unity.h"
#include "Mock_dio.h"
/// @endcond

#include "keypad.h" /**< module under the test */
#include "keypad_cfg.h" /**< module under the test */
#include "circ_buffer.h" 

/******************************************************************************
* Variable Definitions
******************************************************************************/
static KeypadConfig_t * gConfig;

/*****************************************************************************/

void 
setUp(void)
{
  gConfig = Keypad_GetConfig();
  Keypad_Init(gConfig);
}

void 
tearDown(void)
{
}

/*****************************************************************************
* Test cases
******************************************************************************/

void
test_OneCharIsReadWhenASwitchIsPressed(void)
{
  
};

/*****************************End of File ************************************/

