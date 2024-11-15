/******************************************************************************
 *
 * Module: GPT
 *
 * File Name: GPT.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - GPT Driver
 *
 * Author: Ahmed Adel 
 ******************************************************************************/
#include "GPT.h"
#include "gpt_Reg.h"
#include "tm4c123gh6pm_registers.h"
#if (GPT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != GPT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif


STATIC uint8 GPT_Status = GPT_NOT_INITIALIZED;
volatile uint32 * base_adderss_ptr = NULL_PTR ;
volatile Gpt_ConfigType * glo_ptr = NULL_PTR ;
volatile Gpt_ModeType mode_state = GPT_MODE_NORMAL ; /*indicat for normal mode*/
STATIC Gpt_DynamicConfigType Gpt_dynamicTimers[number_of_configur_channel]; /* to hold dynamic attributes */


/************************************************************************************
* Service Name: GPT_Init
* Service ID[hex]: 0x10
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the hardware timer module.
************************************************************************************/

void Gpt_Init( const Gpt_ConfigType* ConfigPtr )
{

 #if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID,
		     GPT_E_PARAM_CONFIG_ID);
	}
	else
#endif
        {
uint8 counter =0 ;
        for (counter=0;counter<number_of_configur_channel;counter++)
        {
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration num channel is valid number */
          if (ConfigPtr[counter].num > total_number_of_channel)
	{
		Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_SID,
		     GPT_E_PARAM_CHANNEL_SID);
	}
#endif 
        
        
 switch(ConfigPtr[counter].num)  
 {
 case 0 : base_adderss_ptr = (volatile uint32 *)GPT_timer0_16_32_base_regs ;
  break ;
 case 1 : base_adderss_ptr = (volatile uint32 *)GPT_timer1_16_32_base_regs ; 
 break:
 case 2 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_16_32_base_regs ; 
 break ; 
 case 3 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_16_32_base_regs ; 
 break ; 
 case 4 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_16_32_base_regs ; 
 break ; 
 case 5 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_16_32_base_regs ;
 break ; 
 case 6 : base_adderss_ptr =(volatile uint32 *) GPT_timer0_32_64_base_regs ;
 break ; 
case 7 : base_adderss_ptr =(volatile uint32 *) GPT_timer1_32_64_base_regs ;
 break ;  
 case 8 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_32_64_base_regs ;
 break ; 
 case 9 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_32_64_base_regs ;
 break ; 
 case 10 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_32_64_base_regs ;
 break ; 
 case 11 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_32_64_base_regs ;
 break ; 
  
}

                                  /*set the Qlock*/
if (ConfigPtr[counter].set_mode == GPT_MODE_NORMAL)
{

if      ((ConfigPtr[counter].num<=5 )&&(ConfigPtr[counter].num>=0) )
        {
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_16_32_General_Purpose_Timer_Ready) ,ConfigPtr[counter].num);
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time16_32_Sleep_Mode_Clock ) ,ConfigPtr[counter].num);
        delay = 
        }

else
{
 switch (ConfigPtr[counter].num)
 {
 case 6: 
   
  SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready ) ,0);
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,0);
 break;
 case 7: 
  SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready ) ,1);
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address +Time32_64 Sleep_Mode_Clock ) ,1);
   break;
 case 8: 
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready ) ,2);
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,2);
   break;
 case 9: 
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready ) ,3);
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,3);
   break;
  case 10: 
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready ) ,4);
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,4);
   break;
  case 11: 
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready ) ,5);
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,5);
   break;
 
 }

}
}
else if (ConfigPtr[counter].set_mode == GPT_MODE_SLEEP)
{
if      ((ConfigPtr[counter].num<=5 )&&(ConfigPtr[counter].num>=0) )
        {
       CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_16_32_General_Purpose_Timer_Ready) ,ConfigPtr[counter].num);
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time16_32_Sleep_Mode_Clock ) ,ConfigPtr[counter].num);
        
        }
else 
{
switch (ConfigPtr[counter].num)
 {
 case 6: 
   
  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready) ,0);
       SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,0);
 break;
 case 7: 
  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready) ,1);
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,1);
   break;
 case 8: 
   CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready) ,2);
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,2);
   break;
 case 9: 
   CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready) ,3);
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,3)
   break;
  case 10: 
   CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready) ,4);
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,4)
   break;
  case 11: 
   CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + timer_32_64_General_Purpose_Timer_Ready) ,5);
           SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + Time32_64 Sleep_Mode_Clock ) ,5);
   break;
 
 }

}

    
}

     /* disable the timer */      
  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMCTL_control_offset_reg),0)   ;   
/*disable the interrupt for timer A*/
  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMIMR_Interrupt_mask_offset_reg),0)   ; 
    /* clear the reload value */
*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAILR_Interval_Load_A_offset_reg ) = 0x00000000 ;
/* clear the current value of timer A */
*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAV_A_currnt_value_offset_reg ) = 0x00000000



  /*set the counting range (32 bit count) for the Timer A*/     
if      ((ConfigPtr[counter].num<=5 )&&(ConfigPtr[counter].num>=0) )
        {
        *(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMCFG_offset_reg) = 0x00000000; 
        
        }
 else if((ConfigPtr[counter].num<=11 )&&(ConfigPtr[counter].num>5))
        {
        *(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMCFG_offset_reg) = 0x00000004; 
        }
  else 
        {
        
        }
   /* set the reqiuer mode (one shot or continuous) for timer A */     
  if (ConfigPtr[counter].mode == GPT_CH_MODE_CONTINUOUS)      
  {
   *(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAMR_modeA_offset_reg)&= 0xFFFFFFFC ;
    *(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAMR_modeA_offset_reg)|= 0x00000002 ;
  }   
        
  else 
  {
  
  *(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAMR_modeA_offset_reg)&= 0xFFFFFFFC;
    *(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAMR_modeA_offset_reg)|= 0x00000001 ;
  }
        
/*set the count up mode */
  SET_BIT(*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAMR_modeA_offset_reg),4)   ;     
    
  /*Update the GPTMTAR and GPTMTAV registers with the value
in the GPTMTAILR register on the next cycle. Also update the 
 GPTMTAPS and GPTMTAPV registers with the value in the GPTMTAPR register on the next cycle.*/
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAMR_modeA_offset_reg),8)   ;     

    /*disable the interrupt for timer A*/
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMIMR_Interrupt_mask_offset_reg ),0)   ;    
    /*set the mode (normal , sleep)*/
    mode_state = ConfigPtr[counter].set_mode ;
    /* init for systick timer */
    if (ConfigPtr[counter].mode == 12)
    {
       /* Configure the SysTick Control Register 
     disable systik*/
    SYSTICK_CTRL_REG    = 0x0;   
    SYSTICK_CURRENT_REG = 0;                         /* Clear the Current Register value */
    }
     

        /* store dynamic attributes */
    Gpt_dynamicTimers[i].channel_num = i;
        Gpt_dynamicTimers[i].interrupt_state = Interrupt_Disabled;
        Gpt_dynamicTimers[i].wakeup_state = Interrupt_Disabled;
        Gpt_dynamicTimers[i].state = Initialized;

       }
      GPT_Status = GPT_INITIALIZED     ;    
       glo_ptr = ConfigPtr ;
  } 
          
}



/************************************************************************************
* Service Name: GPT_DeInit
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): none
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Deinitializes all hardware timer channels
************************************************************************************/

#if (GPT_DEINIT_API == STD_ON)
void Gpt_DeInit( void ) 
{

#if (DIO_DEV_ERROR_DETECT == STD_ON)

if ( GPT_Status == GPT_NOT_INITIALIZED )
{
Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_DeInit_SID,
		     GPT_E_UNINIT );

}

#endif
uint8 counter2 = 0;
for (counter2=0;counter2<number_of_configur_channel;counter2++  )
{
 /* deinit the timer module if timer0,1,2,3,4,5 (16/32)b  */
  if ((glo_ptr[counter2].num >= 0) && (glo_ptr[counter2].num <= 5))
 {
 
 SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_16_32_Bit) , glo_ptr[counter2].num); 
 CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + SGeneral_Purpose_Timer_Software_Reset_SRTIMER1_16_32_Bit) , glo_ptr[counter2].num);
 }
 switch (glo_ptr[counter2].num)
 {
 case 6: 
   
  SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,0);
    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,0);
 break;
 case 7: 
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,1);
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,1);
   break;
 case 8: 
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) 2);
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,2);
   break;
 case 9: 
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,3);
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,3);
   break;
  case 10: 
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,4);
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,4);
   break;
  case 11: 
   SET_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,5);
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)System_Control_base_address + General_Purpose_Timer_Software_Reset_SRTIMER1_32_64_Bit) ,5);
   break;
 
 }
  Gpt_dynamicTimers[i].channel_num = i;
 Gpt_dynamicTimers[i].interrupt_state = Interrupt_Disabled;
        Gpt_dynamicTimers[i].state = Initialized;

}

}
#endif


/************************************************************************************
* Service Name:Gpt_StartTimer
* Service ID[hex]: 0x05
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Channel
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Starts a timer channel
************************************************************************************/


void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value )
{

#if ((DIO_DEV_ERROR_DETECT == STD_ON))

  if ( GPT_Status == GPT_NOT_INITIALIZED )
{
Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_StartTimer_SID,
		     GPT_E_UNINIT_SID );

}
 if (Channel >total_number_of_channel )
 {
 Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_StartTimer_SID,
		     GPT_E_PARAM_CHANNEL_SID );
 
 }
 
 if (Value == 0)
 {
 
 Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_StartTimer_SID,
		     GPT_E_PARAM_VALUE_SID );
 
 }

#endif 
 switch(Channel)  
 {
 case 0 : base_adderss_ptr = (volatile uint32 *)GPT_timer0_16_32_base_regs ;
  break ;
 case 1 : base_adderss_ptr = (volatile uint32 *)GPT_timer1_16_32_base_regs ; 
 break:
 case 2 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_16_32_base_regs ; 
 break ; 
 case 3 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_16_32_base_regs ; 
 break ; 
 case 4 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_16_32_base_regs ; 
 break ; 
 case 5 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_16_32_base_regs ;
 break ; 
 case 6 : base_adderss_ptr =(volatile uint32 *) GPT_timer0_32_64_base_regs ;
 break ; 
case 7 : base_adderss_ptr =(volatile uint32 *) GPT_timer1_32_64_base_regs ;
 break ;  
 case 8 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_32_64_base_regs ;
 break ; 
 case 9 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_32_64_base_regs ;
 break ; 
 case 10 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_32_64_base_regs ;
 break ; 
 case 11 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_32_64_base_regs ;
 break ; 
  
} /****************************************************************** Warning in case of 64-32 you must access poth A and B **************/
if(Channel<12)
{
 /*set prescale*/
*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAPR_A_Prescale_offset_reg = glo_ptr[Channel].prescale
/*set the value to the timer to start the counting*/
*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMTAILR_Interval_Load_A_offset_reg =  Value ; /* Set the Reload value to count n miliseconds */
  /*start the counting by enable the timer */                     

 SET_BIT(*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMCTL_control_offset_reg),0) ;
 

    Gpt_dynamicTimers[Channel].state = Running;
}
if (Channel == 12)
{
  SYSTICK_RELOAD_REG  =  Value-1  ;    /* Set the Reload value to count n miliseconds */
  /* Enable the SysTick Timer (ENABLE = 1)
     * Choose the clock source to be System Clock (CLK_SRC = 1) */
        /* Set the Reload value to count n miliseconds */
  
  SYSTICK_CTRL_REG   |= 0x05; 


    Gpt_dynamicTimers[Channel].state = Running;

}
}


/************************************************************************************
* Service Name:Gpt_stop_Timer
* Service ID[hex]: 0x06
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Channel
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* stop a timer channel
************************************************************************************/

void Gpt_StopTimer( Gpt_ChannelType Channel )
{

#if ((DIO_DEV_ERROR_DETECT == STD_ON))

  if ( GPT_Status == GPT_NOT_INITIALIZED )
{
Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_Gpt_StopTimer_SID,
		     GPT_E_UNINIT_SID );

}
 if (Channel >total_number_of_channel )
 {
 Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_Gpt_StopTimer_SID,
		     GPT_E_PARAM_CHANNEL_SID );
 
 }

#endif
 
 switch(Channel)  
 {
 case 0 : base_adderss_ptr = (volatile uint32 *)GPT_timer0_16_32_base_regs ;
  break ;
 case 1 : base_adderss_ptr = (volatile uint32 *)GPT_timer1_16_32_base_regs ; 
 break:
 case 2 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_16_32_base_regs ; 
 break ; 
 case 3 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_16_32_base_regs ; 
 break ; 
 case 4 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_16_32_base_regs ; 
 break ; 
 case 5 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_16_32_base_regs ;
 break ; 
 case 6 : base_adderss_ptr =(volatile uint32 *) GPT_timer0_32_64_base_regs ;
 break ; 
case 7 : base_adderss_ptr =(volatile uint32 *) GPT_timer1_32_64_base_regs ;
 break ;  
 case 8 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_32_64_base_regs ;
 break ; 
 case 9 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_32_64_base_regs ;
 break ; 
 case 10 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_32_64_base_regs ;
 break ; 
 case 11 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_32_64_base_regs ;
 break ; 
  
}
                      /*disable the timer */
CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMCTL_control_offset_reg),0)   ;
Gpt_dynamicTimers[Channel].state = Stopped;
if (Channel == 12)
{
SYSTICK_CTRL_REG    = 0;    /* Disable the SysTick Timer by Clear the ENABLE Bit */
Gpt_dynamicTimers[Channel].state = Stopped; 
}

}

                      
 /************************************************************************************
* Service Name:Gpt_EnableNotification
* Service ID[hex]: 0x07
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Channel
Numeric identifier of the GPT channe
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Enables the interrupt notification for a channel (relevant in normal mode)
************************************************************************************/                     
#if (GPT_ENABLE_DISABLE_NOTIFICATION_AP == STD_ON)
                      
 void Gpt_EnableNotification( Gpt_ChannelType Channel )
    {
    #if ((DIO_DEV_ERROR_DETECT == STD_ON))

  if ( GPT_Status == GPT_NOT_INITIALIZED )
{
Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_EnableNotification_SID,
		     GPT_E_UNINIT_SID );

}
 if (Channel > total_number_of_channel )
 {
 Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_EnableNotification_SID,
		     GPT_E_PARAM_CHANNEL_SID );
 
 }
uint8 i =0;
for (i=0;i<<number_of_configur_channel;i++)
{
  if(glo_ptr[i].num != Channel )
  {
   Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_EnableNotification_SID,
		     GPT_E_PARAM_CHANNEL_SID ); 
  
  
  }
}
 
#endif   
    
   switch(Channel)  
 {
 case 0 : base_adderss_ptr = (volatile uint32 *)GPT_timer0_16_32_base_regs ;
  break ;
 case 1 : base_adderss_ptr = (volatile uint32 *)GPT_timer1_16_32_base_regs ; 
 break:
 case 2 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_16_32_base_regs ; 
 break ; 
 case 3 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_16_32_base_regs ; 
 break ; 
 case 4 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_16_32_base_regs ; 
 break ; 
 case 5 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_16_32_base_regs ;
 break ; 
 case 6 : base_adderss_ptr =(volatile uint32 *) GPT_timer0_32_64_base_regs ;
 break ; 
case 7 : base_adderss_ptr =(volatile uint32 *) GPT_timer1_32_64_base_regs ;
 break ;  
 case 8 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_32_64_base_regs ;
 break ; 
 case 9 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_32_64_base_regs ;
 break ; 
 case 10 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_32_64_base_regs ;
 break ; 
 case 11 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_32_64_base_regs ;
 break ; 
  
} 
  SET_BIT(*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMIMR_Interrupt_mask_offset_reg),0) ; 
    Gpt_dynamicTimers[Channel].interrupt_state = Interrupt_Enabled;

    if (Channel == 12)
{
SYSTICK_CTRL_REG   |= 0x02;
/* Assign priority level 3 to the SysTick Interrupt */
NVIC_SYSTEM_PRI3_REG =  (NVIC_SYSTEM_PRI3_REG & SYSTICK_PRIORITY_MASK) | (SYSTICK_INTERRUPT_PRIORITY << SYSTICK_PRIORITY_BITS_POS);
Gpt_dynamicTimers[Channel].interrupt_state = Interrupt_Enabled;

}


    }
#endif                     
                      
                      
/************************************************************************************
* Service Name:Gpt_DisableNotification
* Service ID[hex]: 0x08
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Channel
Numeric identifier of the GPT channe
* Parameters (inout): None
* Parameters (out): None
* Return value: None
Disables the interrupt notification for a channel (relevant in normal mode).**/
                      
#if (GPT_ENABLE_DISABLE_NOTIFICATION_AP == STD_ON)
void Gpt_DisableNotification( Gpt_ChannelType Channel )
{
void Gpt_EnableNotification( Gpt_ChannelType Channel )
    {
    #if ((DIO_DEV_ERROR_DETECT == STD_ON))

  if ( GPT_Status == GPT_NOT_INITIALIZED )
{
Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_DisableNotification_SID,
		     GPT_E_UNINIT_SID );

}
 if (Channel > total_number_of_channel )
 {
 Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_DisableNotification_SID,
		     GPT_E_PARAM_CHANNEL_SID );
 
 }
uint8 i =0;
for (i=0;i<<number_of_configur_channel;i++)
{
  if(glo_ptr[i].num != Channel )
  {
   Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_DisableNotification_SID,
		     GPT_E_PARAM_CHANNEL_SID ); 
  
  
  }
}
#endif 

  switch(Channel)  
 {
 case 0 : base_adderss_ptr = (volatile uint32 *)GPT_timer0_16_32_base_regs ;
  break ;
 case 1 : base_adderss_ptr = (volatile uint32 *)GPT_timer1_16_32_base_regs ; 
 break:
 case 2 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_16_32_base_regs ; 
 break ; 
 case 3 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_16_32_base_regs ; 
 break ; 
 case 4 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_16_32_base_regs ; 
 break ; 
 case 5 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_16_32_base_regs ;
 break ; 
 case 6 : base_adderss_ptr =(volatile uint32 *) GPT_timer0_32_64_base_regs ;
 break ; 
case 7 : base_adderss_ptr =(volatile uint32 *) GPT_timer1_32_64_base_regs ;
 break ;  
 case 8 : base_adderss_ptr = (volatile uint32 *)GPT_timer2_32_64_base_regs ;
 break ; 
 case 9 : base_adderss_ptr = (volatile uint32 *)GPT_timer3_32_64_base_regs ;
 break ; 
 case 10 : base_adderss_ptr = (volatile uint32 *)GPT_timer4_32_64_base_regs ;
 break ; 
 case 11 : base_adderss_ptr = (volatile uint32 *)GPT_timer5_32_64_base_regs ;
 break ; 
  
} 
 CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)base_adderss_ptr +GPT_GPTMIMR_Interrupt_mask_offset_reg),0) ; 
    Gpt_dynamicTimers[Channel].interrupt_state = Interrupt_Disabled;
    if (Channel == 12)
{
  /*disable notifications */
CLEAR_BIT(SYSTICK_CTRL_REG ,1)
Gpt_dynamicTimers[Channel].interrupt_state = Interrupt_Disabled;
}


}
#endif                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      
                      




