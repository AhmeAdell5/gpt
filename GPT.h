/******************************************************************************
 *
 * Module: GPT
 *
 * File Name: GPT.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - GPT Driver
 *
 * Author: Ahmed Adel
 ******************************************************************************
#ifndef GPT_h
#define GPT_h

/* Id for the company in the AUTOSAR */
 
#define GPT_VENDOR_ID    (999U)

/* Dio Module Id */
#define GPT_MODULE_ID    (100U)

/* Dio Instance Id */
#define GPT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define GPT_SW_MAJOR_VERSION           (1U)
#define GPT_SW_MINOR_VERSION           (0U)
#define GPT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define GPT_AR_RELEASE_MAJOR_VERSION   (4U)
#define GPT_AR_RELEASE_MINOR_VERSION   (0U)
#define GPT_AR_RELEASE_PATCH_VERSION   (3U)
/*
 * Macros for Dio Status
 */
#define GPT_INITIALIZED                (1U)
#define GPT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and GPT Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != GPT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* GPT Pre-Compile Configuration Header file */
#include "GPT_cfg.h"

/* AUTOSAR Version checking between GPT_Cfg.h and GPT.h files */
#if ((GPT_CFG_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION)\
 ||  (GPT_CFG_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION)\
 ||  (GPT_CFG_AR_RELEASE_PATCH_VERSION != GPT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of GPT_Cfg.h does not match the expected version"
#endif

/* Software Version checking between GPT_Cfg.h and GPT.h files */
#if ((GPT_CFG_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION)\
 ||  (GPT_CFG_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION)\
 ||  (GPT_CFG_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION))
  #error "The SW version of GPT_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"


/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Gpt_Get Version Info */
#define  Gpt_GetVersionInfo_SID         0x00

/* Service ID for Gpt_Init  */
#define Gpt_Init_SID                        0x01

/* Service ID for Gpt_DeInit  */
#define Gpt_DeInit_SID                          0x02

/* Service ID for Gpt_GetTimeElapsed  */
#define Gpt_GetTimeElapsed_SID                  0x03

/* Service ID for Gpt_GetTimeRemaining  */
#define Gpt_GetTimeRemaining_SID                0x04

/* Service ID for Gpt_StartTimer  */
#define Gpt_StartTimer_SID                      0x05

/* Service ID for Gpt_StopTimer  */
#define Gpt_Gpt_StopTimer_SID                   0x06

/* Service ID for Gpt_EnableNotification  */
#define Gpt_EnableNotification_SID              0x07

/* Service ID for Gpt_DisableNotification  */
#define Gpt_DisableNotification_SID             0x08

/* Service ID for Gpt_SetMode  */
#define Gpt_SetMode_SID                         0x09

/* Service ID for Gpt_DisableWakeup  */
#define Gpt_DisableWakeup_SID                   0x0a

/* Service ID for Gpt_EnableWakeup  */
#define Gpt_EnableWakeup_SID                    0x0b

/* Service ID for Gpt_CheckWakeup  */
#define Gpt_CheckWakeup_SID                     0x0c

/* Service ID for Gpt_CheckWakeup  */
#define Gpt_CheckWakeup_SID                     0x0d

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/*API service called without module initialization*/
#define GPT_E_UNINIT_SID  0x0A

/*API service called when timer channel is still busy (running)*/
#define GPT_E_BUSY_SID  0x0B

/*API service for initialization called when already initialized*/
#define GPT_E_ALREADY_INITIALIZED_SID  0x0D

/*API parameter checking: invalid channel*/
#define GPT_E_PARAM_CHANNEL_SID  0x14

/*API parameter checking: invalid value*/
#define GPT_E_PARAM_VALUE_SID  0x15

/*API parameter checking: invalid value*/
#define GPT_E_PARAM_POINTER  0x16

/*API parameter checking: invalid mode*/
#define GPT_E_PARAM_MODE  0x1F


/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
 */
#define GPT_E_UNINIT                   (uint8)0xF0


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


/* Function for Get Version Info API */
void Gpt_GetVersionInfo( Std_VersionInfoType* VersionInfoPtr ) ;

/* Function for Gpt_Init API */
void Gpt_Init( const Gpt_ConfigType* ConfigPtr );

/* Function for Gpt_DeInit API */
void Gpt_DeInit( void ) ;

/* Function for Gpt_GetTime Elapsed API */
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel );

Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel );

void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );

void Gpt_StopTimer( Gpt_ChannelType Channel ) ;

void Gpt_EnableNotification( Gpt_ChannelType Channel ) ;

void Gpt_DisableNotification( Gpt_ChannelType Channel );

void Gpt_SetMode( Gpt_ModeType Mode );

void Gpt_DisableWakeup( Gpt_ChannelType Channel );

void Gpt_EnableWakeup( Gpt_ChannelType Channel );

void Gpt_CheckWakeup( EcuM_WakeupSourceType WakeupSource );

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern  const Gpt_ConfigType cofig_timer[number_of_configur_channel] ;

extern void (*g_SysTick_Call_Back_Ptr)(void) ;





#endif