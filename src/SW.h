/**
 * @file SW.h
 * @author Mohamed Hassanin Mohamed
 * @brief A switch module to interface with switches.
 * @version 0.1
 * @date 2021-02-21
 */
#ifndef SW_H_
#define SW_H_
/**********************************************************************
* Includes
**********************************************************************/
/// @cond NODOC
#include <inttypes.h>
/// @endcond
#include "SW_cfg.h"
/**********************************************************************
* Function Prototypes
**********************************************************************/
extern void SW_Init(const SWConfig_t * const Config);
extern SWState_t SW_GetState(SW_t Index);
extern void SW_SetState(SW_t Index, SWState_t State);
extern void SW_Update(void);

#endif /* end SW_H_ */
/************************* END OF FILE ********************************/
