/**
 * @file keypad.h
 * @author Mohamed Hassanin
 * @brief Keypad interface pattern that is commonly used in 
 * embedded systems projects
 * @version 0.1
 * @date 2021-03-18
 */

#ifndef KEYPAD_H
#define KEYPAD_H
/******************************************************************************
* Includes
******************************************************************************/
#include <inttypes.h>
#include "keypad_cfg.h" 

/******************************************************************************
* Function Prototypes
******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

extern void Keypad_Init(KeypadConfig_t * const Config);
extern void Keypad_Update(void);
extern uint8_t Keypad_GetState(Keypad_t Keypad, uint8_t* Data, uint8_t DataSize);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* KEYPAD_H */
/***************************** END OF FILE ***********************************/
