
void init_PWM(){
    // Configure the CCP1 module for PWM operation
    CCP1M2 = 1;
    CCP1M3 = 1;
    // Set CCP1 pin as output
    TRISC2 = 0;
}

void set_Tpwm(){
    // Set the Timer2 prescaler value and enable Timer2
    switch(ps){
        case 1: {T2CKPS0 = 0;   T2CKPS1 = 0;    break;}
        case 4: {T2CKPS0 = 1;   T2CKPS1 = 0;    break;}
        case 16: T2CKPS1 = 0;   
    }
    // Note: Timer2 is automatically cleared by hardware if TMR2 == PR2
    TMR2ON = 1;
    // Set the PWM period 
    PR2 = ((float)(_XTAL_FREQ/Fpwm))/(4*ps)-1;
    // --------[Warning: Check if PR2 value fits in 8-bit register (0-255)]---------]
}

uint16_t DC_cal(uint16_t DC){
    return ((float)_XTAL_FREQ/(float)Fpwm)*((float)DC/(float)100)/ps;
}

void setPWM_DutyCycle(uint16_t DC){
    // Write to CCP1CON<5:4>
    CCP1Y = DC & (1<<0);
    CCP1X = DC & (1<<1);
    // Write to CCPR1L register
    CCPR1L = DC >> 2;
}
 
void Dong()
{
            RC1=1;
            RC0=0;
            setPWM_DutyCycle(DC_cal(100));
}
void Mo()
{
            RC1=0;
            RC0=1;
            setPWM_DutyCycle(DC_cal(100));
}
void Dung()
{
    RC1=0;
    RC0=0;
}/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

