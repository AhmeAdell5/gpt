/******************************************************************************
 *
 * Module: gpt
 *
 * File Name: gpt_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - GPT Driver Registers
 *
 * Author: Ahmed Adel 
 ******************************************************************************/
#ifndef gpt_reg_h
#define gpt_reg_h

#include "std_types.h"

/* Gpt Base addresses registers */

#define GPT_timer0_16_32_base_regs         0x40030000
#define GPT_timer1_16_32_base_regs          0x40031000
#define GPT_timer2_16_32_base_regs          0x40032000
#define GPT_timer3_16_32_base_regs         0x40033000
#define GPT_timer4_16_32_base_regs          0x40034000
#define GPT_timer5_16_32_base_regs          0x40035000
#define GPT_timer0_32_64_base_regs          0x40036000
#define GPT_timer1_32_64_base_regs          0x40037000
#define GPT_timer1_32_64_base_regs          0x4003C000
#define GPT_timer1_32_64_base_regs          0x4003D000
#define GPT_timer1_32_64_base_regs          0x4003E000
#define GPT_timer1_32_64_base_regs          0x4003F000
#define System_Control_base_address    (volatile uint32 *)0x400FE000
/* Gpt offset addresses registers */


#define GPT_GPTMCFG_offset_reg                                  0x000
#define GPT_GPTMTAMR_modeA_offset_reg                           0x004
#define GPT_GPTMTBMR_modeB_offset_reg                           0x008
#define GPT_GPTMCTL_control_offset_reg                          0x00C
#define GPT_GPTMIMR_Interrupt_mask_offset_reg                   0x018
#define GPT_GPTMRIS_Raw_Interrupt_Status_offset_reg             0x01C
#define GPT_GPTMMIS_Masked_Interrupt_Status_offset_reg          0x020
#define GPT_GPTMICR_Interrupt_Clear_offset_reg                  0x024
#define GPT_GPTMTAILR_Interval_Load_A_offset_reg                0x028
#define GPT_GPTMTBILR_Interval_Load_B_offset_reg                0x02C
#define GPT_GPTMTAMATCHR_A_Match_offset_reg                     0x030
#define GPT_GPTMTBMATCHR_B_Match_offset_reg                     0x034
#define GPT_GPTMTAPR_A_Prescale_offset_reg                      0x038
#define GPT_GPTMTBPR_B_Prescale_offset_reg                      0x03C
#define GPT_GPTMTAR_A_currnt_offset_reg                         0x048
#define GPT_GPTMTBR_B_currnt_offset_reg                         0x04C
#define GPT_GPTMTAV_A_currnt_value_offset_reg                   0x050
#define GPT_GPTMTBV_B_currnt_value_offset_reg                   0x054  
#define GPT_GPTMTAPV_A_Prescale_value_offset_reg                0x064  
#define GPT_GPTMTBPV_B_Prescale_value_offset_reg                0x068  
#define General_Purpose_Timer_Software_Reset_SRTIMER1_16_32_Bit  0x504
#define  General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit 0x55C
#define Time32_64_Sleep_Mode_Clock      0x75C
#define Time16_32_Sleep_Mode_Clock      0x704         
#define timer_16_32_General_Purpose_Timer_Ready    0x604
#define timer_32_64_General_Purpose_Timer_Ready    0x65C
#endif
