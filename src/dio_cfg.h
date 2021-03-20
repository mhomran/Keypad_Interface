/** 
 * @file dio_cfg.h
 * @author Mohamed Hassanin
 * @brief This module contains interface definitions for the
 * Dio configuration. This is the header file for the definition of the
 * interface for retrieving the digital input/output configuration table.
 * @version 0.1
 * @date 2021-01-12
*/
#ifndef DIO_CFG_H_
#define DIO_CFG_H_
/**********************************************************************
* Preprocessor Constants
**********************************************************************/
/**
* Defines the number of pins on each processor port.
*/
#define DIO_CHANNELS_PER_PORT 8U
/**
* Defines the number of ports on the processor.
*/
#define DIO_NUMBER_OF_PORTS 4U
/**********************************************************************
* Typedefs
**********************************************************************/
/**
* Defines the possible states for a digital output pin.
*/
typedef enum
{
	DIO_STATE_LOW, /**< Defines digital state ground */
	DIO_STATE_HIGH, /**< Defines digital state power */
	DIO_STATE_MAX /**< the maximum number of states */
}DioState_t;

/**
 * Defines the possible directions of the pin
 */
typedef enum 
{
	DIO_DIR_INPUT, 
	DIO_DIR_OUTPUT
}DioDirection_t;

/**
* Defines an enumerated list of all the channels (pins) on the MCU
* device. The last element is used to specify the maximum number of
* enumerated labels.
*/
typedef enum
{
	/* TODO: Populate this list based on available MCU pins */
	PORTA_0,
	PORTA_1,
	PORTA_2,
	PORTA_3,
	PORTA_4,
	PORTA_5,
	DIO_CHANNEL_MAX
}DioChannel_t;

/**
* Defines the digital input/output configuration table’s elements that are used
* by Dio_Init to configure the Dio peripheral.
*/
typedef struct
{
	DioChannel_t Channel; /**< The I/O pin */
	DioDirection_t Direction; /**< OUTPUT or INPUT */
	DioState_t Data; /**< HIGH or LOW */
}DioConfig_t;

/**********************************************************************
* Function Prototypes
**********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

const DioConfig_t* Dio_ConfigGet(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* DIO_CFG_H_*/
/************************* END OF FILE ********************************/
