 /******************************************************************************
 *
 * Module: GPT
 *
 * File Name: GPT_Types.h
 *
 * Description: the types of GPT module
 *
 * Author: Ahmed Adel
 *
 *******************************************************************************/
#ifndef GPT_types_h
#define GPT_types_h


#include "std_types.h"


/* Numeric ID of a GPT channel.*/
typedef uint8 Gpt_ChannelType ;

/* Type for reading and setting the timer values (in number of ticks)*/
typedef uint32 Gpt_ValueType ;

/* Allows the selection of different timers modes*/
typedef enum
{
GPT_CH_MODE_CONTINUOUS,GPT_CH_MODE_ONESHOT
}Gpt_Mode;


/* Allows the selection of different power modes*/
typedef enum
{
GPT_MODE_NORMAL,GPT_MODE_SLEEP
}Gpt_ModeType;


/* This is the type of the data structure including the configuration set required for initializing the GPT timer unit*/
typedef struct 
{
Gpt_ChannelType num ;
Gpt_ModeType set_mode ;
Gpt_Mode mode;
 uint32 priscal ;
}Gpt_ConfigType;

/* Enum for Timer channel state */
typedef enum{
  Initialized, Running, Stopped, Expired
}Gpt_ChannelState;

/* Enum for Interrupt state: enabled/disabled */
typedef enum{
  Interrupt_Disabled, Interrupt_Enabled
}Gpt_InterruptState;
/* Type-definition for dynamic attributes of timers
  - State
  - Interrupt notification (enabled/disabled)
  - Channel Wakeup (enabled/disabled)
*/

typedef struct
{
  Gpt_ChannelType channel_num ;
  Gpt_ChannelState state;
  Gpt_InterruptState interrupt_state;
  Gpt_InterruptState wakeup_state;

}Gpt_DynamicConfigType;

#endif
