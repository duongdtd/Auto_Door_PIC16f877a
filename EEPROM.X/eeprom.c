#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#define _XTAL_FREQ 16000000
//LCD
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7
//KEYPAD
#define RowA  RC4
#define RowB  RC5
#define RowC  RC6
#define RowD  RC7
#define C1   RB0
#define C2   RB1
#define C3   RB2
#define C4   RB3
#define D0   RD0
#define D1   RD1
//PORT&TRIS KEYPAD
#define Keypad_PORT   PORTB
#define Keypad_PORT_Dir  TRISB  
uint32_t Fpwm = 2000;           
uint8_t ps = 4;  
#include <xc.h>
#include "lcd.h"
#include "eeprom.h"
#include "keypad.h"
#include "moto.h"
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
unsigned char pass[]={};
int counter = 0 ;
int trangthai=0;
int tt=0;
int counter1=0;
void nguoi();
void main(void) {
    init_PWM();
    set_Tpwm();
    INTEDG = 1;                                 
    GIE = 1; 
     TRISD = 0x03;
     PORTD   = 0;
     TRISA=0x00;
     PORTA=0x00;
     Lcd_Init();
     Lcd_Set_Cursor(1,1);                  
     Lcd_Write_String("WELLCOME");
     Lcd_Set_Cursor(2,1);
     Lcd_Write_String("");
     char Key = 'n'; 
     int down=3;
     int check1=0;
     int check2=1;
     int check3=0;
     int check5=0;
     int check6=0;
     InitKeypad();   

 while(1)
 { 
//CHECK KEY
  char check4=EEPROM_Read(1);
  Key = GetKey(); 
  if(Key=='p')
  {
      RBIE=1;
      Lcd_Clear();
      Lcd_Set_Cursor(1,1);                  
      Lcd_Write_String("OPEN");
  }
  if(Key=='m')
  {
     RBIE=0;
     Lcd_Clear();
     Lcd_Set_Cursor(1,1);                  
     Lcd_Write_String("CLOSE DOOR");
     __delay_ms(2500);
     Lcd_Clear();
     Lcd_Set_Cursor(1,1);                  
     Lcd_Write_String("WELLCOME");
     Lcd_Set_Cursor(2,1);
     Lcd_Write_String("");
     check3=0;
     check5=0;
     check1=0;
     check2=1;
     counter=0;
  }
 if((Key=='1'||Key=='2'||Key=='3'||Key=='4'||Key=='5'||Key=='6'||Key=='7'||Key=='8'||Key=='9'||Key=='0')&&check2==0)
 {
     if(check6==1)
     {
        Lcd_Write_Char('*');
     }
     else
     {
         Lcd_Write_Char(Key);
     }
 }
 if(Key=='*'&&check4=='1'&&check3==0&&check5==0)
 {   check3=1;
     Lcd_Clear();
     Lcd_Set_Cursor(1,1);                  
     Lcd_Write_String("PASSWORD");
     Lcd_Set_Cursor(1,10);   
     Lcd_Write_String("DOWN: 3");
     Lcd_Set_Cursor(2,1);
     Lcd_Write_String("");
     check2=0;
     check6=1;
 }
  if(Key=='*'&&check4!='1'&&check3==0&&check5==0)
 {          check5=1;
            counter=0;
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("C: CHOSE PASSWORD");
            Lcd_Set_Cursor(2,1);
            check2=0;
           
     
 } if(Key=='C'&&check4!='1'&&check3==0&&check5==1)
 {          down=3;
            check3=1;
            char down1=down+'0';
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);  
            Lcd_Write_String("COMPLETE");
            Lcd_Set_Cursor(2,1);  
            Lcd_Write_String("WELLCOME HOME");
            __delay_ms(2500);
            int c2=counter;
            char c1=c2+'0';
            EEPROM_Write(0,c1);
            EEPROM_Write(1,'1');
            for(int i=0;i<counter;i++)
            {
                char x=pass[i];
                EEPROM_Write(i+2,x);
            }
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);                  
            Lcd_Write_String("PASSWORD");
            Lcd_Set_Cursor(1,10);
            Lcd_Write_String("DOWN :");
            Lcd_Set_Cursor(1,16);   
            Lcd_Write_Char(down1);
            Lcd_Set_Cursor(2,1);
            Lcd_Write_String("");
            check1=0;
            counter=0;
            check2=0;
            check6=1;

 }
 if(Key=='1'&&check2==0)
 {
     pass[counter]='1';counter++;
 }
 if(Key=='2'&&check2==0)
 {
     pass[counter]='2';counter++;
 }
 if(Key=='3'&&check2==0)
 {
     pass[counter]='3';counter++;
 }
 if(Key=='4'&&check2==0)
 {
     pass[counter]='4';counter++;
 }
  if(Key=='5'&&check2==0)
 {
     pass[counter]='5';counter++;
 }
  if(Key=='6'&&check2==0)
 {
     pass[counter]='6';counter++;
 }
  if(Key=='7'&&check2==0)
 {
     pass[counter]='7';counter++;
 }
  if(Key=='8'&&check2==0)
 {
     pass[counter]='8';counter++;
 }
  if(Key=='9'&&check2==0)
 {
     pass[counter]='9';counter++;
 }

  if(Key=='D'&&check2==0&&check1==0&&check3==1)
 {          counter=0;
            char down1=down +'0';
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);  
            Lcd_Write_String("PASSWORD");
            Lcd_Set_Cursor(1,10);
            Lcd_Write_String("DOWN :");
            Lcd_Set_Cursor(1,16);
            Lcd_Write_Char(down1);
            Lcd_Set_Cursor(2,1);
            Lcd_Write_String("");
 }
   if(Key=='D'&&check2==0&&check1==0&&check3==0&&check5==1)
 {          counter=0;
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("C: CHOSE PASSWORD");
            Lcd_Set_Cursor(2,1);
            check2=0;
            check5=1;
 }
   if(Key=='D'&&check2==0&&check1==1&&check3==1)
 {          counter=0;
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("NEW PASSWORD");
            Lcd_Set_Cursor(2,1);
            check2=0;
 }
//CHANGE PASSWORD
 if(Key=='A'&&check1==1)
 {          counter=0;
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("NEW PASSWORD");
            Lcd_Set_Cursor(2,1);
            check2=0;
            check6=0;
         
  }
//RETURN 
 if(Key=='B'&&check1==1)
  {  RBIE=0;
     Lcd_Clear();
     Lcd_Set_Cursor(1,1);                  
     Lcd_Write_String("CLOSE DOOR");
     __delay_ms(2500);
     Lcd_Clear();
     Lcd_Set_Cursor(1,1);                  
     Lcd_Write_String("WELLCOME");
     Lcd_Set_Cursor(2,1);
     Lcd_Write_String("");
     check3=0;
     check5=0;
     check1=0;
     check2=1;
     counter=0;
  }
//COMPLETE CHANGE PASSWORD
 if(Key=='C'&&check1==1&&check2==0)
  {         down=3;
            char down1=down+'0';
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);  
            Lcd_Write_String("COMPLETE");
            __delay_ms(2500);
            int c2=counter;
            char c1=c2+'0';
            EEPROM_Write(0,c1);
            EEPROM_Write(1,'1');
            for(int i=0;i<counter;i++)
            {
                char x=pass[i];
                EEPROM_Write(i+2,x);
            }
            Lcd_Clear();
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);                  
            Lcd_Write_String("WELLCOME");
            check3=0;
            check5=0;
            check2=1;
            check1=0;
            counter=0;
            
  }
//CHECK PASSWORD
 if(Key=='#'&&check2==0&&check1==0&&check3==1)
  {
        int check=0;
        char x=EEPROM_Read(0);
        int x2=x-'0';
        if(counter==x2)
       {
           if(counter==x2)
       {
           for(uint8_t i=2;i<=counter+1;i++)
           {
               char data=EEPROM_Read(i);
               if(pass[i-2]!=data)
               {
                   check++;
               }
           }
       }
       }
       else
       {
           check=1;
       }
        //CORRECT
       if(check==0)
       {    RBIE=1;
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);                  
            Lcd_Write_String("OPEN");
            __delay_ms(2500);
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_String("A THAY PASSWORD ");
            Lcd_Set_Cursor(2,1);
            Lcd_Write_String("B KHOA CUA");
            check1=1;
            check2=1;
       }
        //INCORRECT
       else
       {   RBIE=0; 
           down--;
            counter=0;
            char down1=down+'0';
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);                  
            Lcd_Write_String("NOT OPEN");
            __delay_ms(2500);
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);  
            Lcd_Write_String("PASSWORD");
            Lcd_Set_Cursor(1,10);
            Lcd_Write_String("DOWN :");
            Lcd_Set_Cursor(1,16);
            Lcd_Write_Char(down1);
            Lcd_Set_Cursor(2,1);
            Lcd_Write_String("");
            if(down==0)
            {
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);                  
            Lcd_Write_String("ERROR    ERROR");
            Lcd_Set_Cursor(2,1);                  
            Lcd_Write_String("ERROR    ERROR");
            check2=1;
            }
       } 
  }
}
}
void __interrupt() ISR(void){
    if(RBIF==1)
    { 
        if(RB4==1&&RB5==1&&RB6==1&&RB7==1)
        {
            
                if(trangthai==1 && tt==2)
        {
            counter1++;
            trangthai=0;
            tt=0;
        }
                else if(trangthai==2 && tt==2)
        {
            counter1--;
            trangthai=0;
            tt=0;
        }
            nguoi();
            Dong();
            __delay_ms(750);
            Dung();
        }
        else if(RB5==1&&RB6==0&&RB7==0)
        {   nguoi();
            trangthai=1;
            Mo();
            __delay_ms(750);
            Dung();
        }else if(RB5==0&&RB6==0&&RB7==1)
        {   nguoi();
            trangthai=2;
            Mo();
            __delay_ms(750);
            Dung(); 
        }
        else if(RB5==0&&RB6==0&&RB7==0)
        {   nguoi();
            Mo();
            __delay_ms(750);
            Dung();
            
        } else if(RB7==1 && RB5==0 && RB6==1)
        {
            if(trangthai==1){tt=2;}
            else if(trangthai==2){tt=1;}
            nguoi();
        }
        else if(RB7==0 && RB6==1 && RB5==1)
        {
            if(trangthai==1){tt=1;}
            else if(trangthai==2){tt=2;}
            nguoi();
        }
            RBIF=0;
    }
    else
    {
        Dung();
        RBIF=0;
        nguoi();
    }
}
void nguoi()
{
  if(counter1>0){RA0=1;}
  else{RA0=0;}
}