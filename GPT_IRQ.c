/******************************************************************************
 *
 * Module: GPT
 *
 * File Name: GPT_IRQ.c
 *
 * Description: source file for Isr TM4C123GH6PM Microcontroller - GPT Driver
 *
 * Author: Ahmed Adel
 ******************************************************************************/


#include "GPT.h"

void SysTick_Handler(void)
{
    /* Check if the Timer0_setCallBack is already called */
    if(g_SysTick_Call_Back_Ptr != NULL_PTR)
    {
        (*g_SysTick_Call_Back_Ptr)(); /* call the function in the scheduler using call-back concept */
    }
    /* No need to clear the trigger flag (COUNT) bit ... it cleared automatically by the HW */
}