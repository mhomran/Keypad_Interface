/** 
 * @file dio.h
 * @author Mohamed Hassanin
 * @brief The interface definition for the dio.
 * This is the header file for the definition of the interface for a digital
 * input/output peripheral on a standard microcontroller.
 * @version 0.1
 * @date 2021-01-12
*/
#ifndef DIO_EXT_H_
#define DIO_EXT_H_
/**********************************************************************
* Includes
**********************************************************************/
#include <inttypes.h>
#include "dio_cfg.h" /**< For dio configuration */
/**********************************************************************
* Function Prototypes
**********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

extern void Dio_Init(const DioConfig_t * const Config);

extern DioState_t Dio_ChannelRead(DioChannel_t Channel);
extern void Dio_ChannelWrite(DioChannel_t Channel, DioState_t State);

extern void Dio_SetChannelDirection(DioChannel_t Channel, DioDirection_t Direction);

extern void Dio_RegisterWrite(uint8_t volatile * const Address, uint8_t Value);
extern const volatile uint8_t Dio_RegisterRead(const volatile uint8_t * const Address);


#ifdef __cplusplus
} // extern "C"
#endif

#endif /* DIO_H_*/
/*************** END OF FILE ********************************/
