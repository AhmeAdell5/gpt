/******************************************************************************
 *
 * Module: GPT
 *
 * File Name: GPT_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - GPT Driver
 *
 * Author: Ahmed Adel 
 ******************************************************************************/
#define GPT_PBCFG_SW_MAJOR_VERSION              (1U)
#define GPT_PBCFG_SW_MINOR_VERSION              (0U)
#define GPT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define GPT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define GPT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define GPT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

#include "GPT.h"

/* AUTOSAR Version checking between GPT_PBcfg.c and GPT.h files */
#if ((GPT_PBCFG_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION)\
 ||  (GPT_PBCFG_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION)\
 ||  (GPT_PBCFG_AR_RELEASE_PATCH_VERSION != GPT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between GPT_PBcfg.c and GPT.h files */
#if ((GPT_PBCFG_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION)\
 ||  (GPT_PBCFG_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION)\
 ||  (GPT_PBCFG_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with GPT_Init API */
   const Gpt_ConfigType cofig_timer[number_of_configur_channel]={0,0,0};

void (*g_SysTick_Call_Back_Ptr)(void) = NULL_PTR;