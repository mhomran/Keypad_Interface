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
#include "dio.h"
/**********************************************************************
* Definitions
**********************************************************************/
#define KEYPAD_RCV_BUFF_SIZE 30

#define KEYPAD_LONGEST_ROW 3 /**< the longest row among all keypads */
#define KEYPAD_LONGEST_COL 3 /**< the longest column among all keypads */

//TODO: add more keypad size as possible
#define KEYPAD_3_X_3 9 /**< number of switches in 3x3 keypad */

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

/**
 * @brief The keypad configuration structure
 */
typedef struct 
{
  Keypad_t Keypad;
  
  SW_t Cols[KEYPAD_LONGEST_ROW];
  const uint8_t ColsSize;
  
  DioChannel_t Rows[KEYPAD_LONGEST_COL];
  const uint8_t RowsSize;
} KeypadConfig_t;
/******************************************************************************
* Function Prototypes
******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

extern KeypadConfig_t* const Keypad_GetConfig(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* KEYPAD_CFG_H */
/***************************** END OF FILE ***********************************/
