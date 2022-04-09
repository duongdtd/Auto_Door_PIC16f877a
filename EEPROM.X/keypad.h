//TRIS&PORT KEYPAD
void InitKeypad(void)
{
 Keypad_PORT     = 0x00; 
 Keypad_PORT_Dir = 0xFF; 
 TRISC=0x00;
 PORTC=0x00;
 OPTION_REG &= 0x7F;
}
//SCAN KEYPAD
char READ_SWITCHES(void) 
{ 
 RowA = 0; RowB = 1; RowC = 1; RowD = 1;  

 if (C1 == 0) { __delay_ms(250); while (C1==0); return 'D'; }
 if (C2 == 0) { __delay_ms(250); while (C2==0); return '#'; }
 if (C3 == 0) { __delay_ms(250); while (C3==0); return '0'; }
 if (C4 == 0) { __delay_ms(250); while (C4==0); return '*'; }
 if (D1 == 0) { __delay_ms(250); while (D1==0); return 'p'; }
 if (D0 == 0) { __delay_ms(250); while (D0==0); return 'm'; }
 RowA = 1; RowB = 0; RowC = 1; RowD = 1;  

 if (C1 == 0) { __delay_ms(250); while (C1==0); return 'C'; }
 if (C2 == 0) { __delay_ms(250); while (C2==0); return '9'; }
 if (C3 == 0) { __delay_ms(250); while (C3==0); return '8'; }
 if (C4 == 0) { __delay_ms(250); while (C4==0); return '7'; }
 if (D1 == 0) { __delay_ms(250); while (D1==0); return 'p'; }
 if (D0 == 0) { __delay_ms(250); while (D0==0); return 'm'; }
 RowA = 1; RowB = 1; RowC = 0; RowD = 1;  

 if (C1 == 0) { __delay_ms(250); while (C1==0); return 'B'; }
 if (C2 == 0) { __delay_ms(250); while (C2==0); return '6'; }
 if (C3 == 0) { __delay_ms(250); while (C3==0); return '5'; }
 if (C4 == 0) { __delay_ms(250); while (C4==0); return '4'; }
 if (D1 == 0) { __delay_ms(250); while (D1==0); return 'p'; }
 if (D0 == 0) { __delay_ms(250); while (D0==0); return 'm'; }
 RowA = 1; RowB = 1; RowC = 1; RowD = 0;  

 if (C1 == 0) { __delay_ms(250); while (C1==0); return 'A'; }
 if (C2 == 0) { __delay_ms(250); while (C2==0); return '3'; }
 if (C3 == 0) { __delay_ms(250); while (C3==0); return '2'; }
 if (C4 == 0) { __delay_ms(250); while (C4==0); return '1'; }
 if (D1 == 0) { __delay_ms(250); while (D1==0); return 'p'; }
 if (D0 == 0) { __delay_ms(250); while (D0==0); return 'm'; }
 return 'n';           
}
//RETURN KEY
char GetKey(void)             
{
 char key = 'n';              
 while(key=='n')              
  key = READ_SWITCHES();   
 return key;                  
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

