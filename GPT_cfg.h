
/******************************************************************************
 *
 * Module: GPT
 *
 * File Name: GPT_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - GPT Driver
 *
 * Author: Ahmed Adel
 ******************************************************************************/
#ifndef GPT_cfg_h
#define GPT_cfg_h 

/*
 * Module Version 1.0.0
 */
#define GPT_CFG_SW_MAJOR_VERSION              (1U)
#define GPT_CFG_SW_MINOR_VERSION              (0U)
#define GPT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define GPT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define GPT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define GPT_CFG_AR_RELEASE_PATCH_VERSION     (3U)


/*  Pre-compile option for Enables/Disables development error detection */
#define GPT_DEV_ERROR_DETECT                 (STD_ON)


/*  Pre-compile option for Enables/Disables wakeup source reporting */
#define GPT_REPORT_WAKEUP_SOURCE             (STD_OFF) 


/*  Pre-compile option for Enables wakeup capability of MCU for a channel */
#define GPT_ENABLE_WAKEUP                    (STD_OFF) 

/* Channel Id of the GPT channelThis value will be assigned to the symbolic name derived of the GptChannelConfiguration container short name
for   timer0 16/32 --> 0
      timer1 16/32 --> 1
      timer2 16/32 --> 2
      timer3 16/32 --> 3
      timer4 16/32 --> 4
      timer5 16/32 --> 5
      timer0 32/64 --> 6
      timer1 32/64 --> 7
      timer2 32/64 --> 8
      timer3 32/64 --> 9
      timer4 32/64 --> 10
      timer5 32/64 --> 11
      sistck_timer 32/64 --> 12       */
#define GPT_timer_0_CHANNEL_ID                      (0U)

#define total_number_of_channel                      12
/*Specifies the behaviour of the timer channel after the target time is reached*/
#define GPT_CHANNEL_MODE                          (Gpt_Mode)0

/* Specifies the tick frequency of the timer channel in Hz */
#define Gpt_Channel_Tick_Frequency                (Gpt_ValueType)15999999
 #define clocks_per_tick           15999 

#define number_of_configur_channel                           1
/* Maximum value in ticks, the timer channel is able to count.With the next tick, the timer rolls over to zero*/
#define Gpt_Channel_Tick_Value_Max                 4294967296
#define GPT_DEINIT_API                          (STD_ON) 

#define GPT_ENABLE_DISABLE_NOTIFICATION_API     (STD_ON) 

#define GPT_TIME_ELAPSED_API                    (STD_ON) 

#define GPT_TIME_REMAINING_API                  (STD_ON) 

#define GPT_VERSION_INFO_API                    (STD_ON) 

#define GPT_WAKEUP_FUNCTIONALITY_API            (STD_OFF)

#define GPT_NOT_INITIALIZED                       0
#define GPT_INITIALIZED                           1
   
#endif
