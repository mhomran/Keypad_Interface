/**
 * @file SW_cfg.h
 * @author Mohamed Hassanin Mohamed
 * @brief A configuration file for the switches
 * @version 0.1
 * @date 2021-02-25
 */
#ifndef SW_CFG_H
#define SW_CFG_H
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
#define SW_PRESSED_LEVEL DIO_STATE_LOW
#define SW_RELEASED_LEVEL DIO_STATE_HIGH
/**********************************************************************
* Includes
**********************************************************************/
#include <inttypes.h>
#include "dio_cfg.h"
/**********************************************************************
* Typedefs
**********************************************************************/
/**
* Defines an enumerated list of all normal swithes in the project
*/
typedef enum {
  SW_MY_SW,
  SW_OPEN_VALVE,
  MAX_SW_NUM
} SW_t;

/**
 * @brief The state of the switches.
 */
typedef enum {
  SW_PREPRESSED, /**< The switch is about to be pressed*/
  SW_PRESSED, /**< The switch is pressed */
  SW_PRERELEASED, /**< The switch is about to be released*/
  SW_RELEASED, /**< The switch is released */
  MAX_SW_STATE /**< Number of states */
} SWState_t;
/**
 * @brief Switch structure
 */
typedef struct {
  SWState_t State; /**< The switch state */
  DioChannel_t Channel; /**< the physical channel that the switch is connected to */
} SWConfig_t;
/**********************************************************************
* functions prototypes
**********************************************************************/
extern SWConfig_t *const SW_GetConfig(void);

#endif
/************************* END OF FILE ********************************/
