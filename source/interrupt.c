
#include <LPC21xx.h>
#include "Interrupt_defines.h"
#include "lcd_defines.h"
#include "lcd.h"
#include "KPM.h"
#include "delay.h" 
#include "rtc.h"
#include "buzzer.h"
#include "interrupt.h"
//External RTC variables
extern s32 hour,min,sec,date,month,year,day;
// Medicine timings
s32 m1_h,m1_m,m2_h,m2_m,m3_h,m3_m; 
// Flags for interrupt handling
volatile int flag0=0;
volatile int flag1=0;
// External Interrupt 0 ISR (Menu trigger)
void EINT0_ISR(void) __irq
{
	menu(); // Call menu function
	EXTINT=1<<0; // Clear interrupt flag
  VICVectAddr=0; // End of interrupt
}
// External Interrupt 1 ISR (Medicine taken confirmation)
void EINT1_ISR(void) __irq
{
	flag1=1;// Set flag to indicate medicine taken
	CmdLCD(0x01);// Clear LCD
  buzzer_off();// Stop buzzer
  CmdLCD(0x80);	
  StrLCD("MEDICINE TAKEN");// Display message
  CmdLCD(0xC0);
	StrLCD("SUCCESSFULLY");
	delay_s(3);
	CmdLCD(0x01);
	buzzer_off();
	EXTINT=1<<1; // Clear interrupt flag
	VICVectAddr=0;// End interrupt
}	
// Interrupt initialization
void interrupt_init(void)
{
        PINSEL0&=((u32)~3<<2)|((u32)~3<<6);// Clear bits for EINT pins
        PINSEL0|=EINT0_INPUT_PIN|EINT1_INPUT_PIN; // Configure pins as interrupts
        VICIntEnable=(1<<EINT0_VIC_CHNO)|(1<<EINT1_VIC_CHNO); // Enable interrupts
        VICVectCntl0=(1<<5)|EINT0_VIC_CHNO;// Enable slot 0 for EINT0
        VICVectAddr0=(u32 )EINT0_ISR; // Assign ISR
        VICVectCntl1=(1<<5)|EINT1_VIC_CHNO; // Enable slot 1 for EINT1
        VICVectAddr1=(u32 )EINT1_ISR;
        EXTMODE=((1<<1)|(1<<0));// Edge-triggered interrupts
}
// Main menu function
void menu()
{
  u8 Op;
  while(1)
  {
  INPUT1:         CmdLCD(0x01);
                  CmdLCD(0x80);
                  StrLCD("1.RTC 3.EXIT");
                  CmdLCD(0xC0);
                  StrLCD("2.MED ");
                  Op=KeyScan();
                  switch(Op)
                  {
                  case '1':editRTC();
                  break;
                  case '2':medicineTimeEdit();
                  break;
                  case '3':CmdLCD(0x01); // Exit menu
                  return;
                  default: CmdLCD(0x01);
                           CmdLCD(0x80);
                           StrLCD("ERROR"); // Invalid input
                           delay_s(1);
                           goto INPUT1;
                  }
    }
}
// RTC editing menu
void editRTC()
{
        u8 editOp;
        while(1)
        {
         INPUT:CmdLCD(0x01);
               CmdLCD(0x80);
               StrLCD("1.H 2.M 3.S 4.DA");
               CmdLCD(0xC0);
               StrLCD("5.M 6.Y 7.DY 8.EX");                     
               editOp=KeyScan();
               switch(editOp)
               {
               case '1':editHour(&hour);
               break;
               case '2':editMin(&min);
               break;
               case '3':editSec(&sec);
               break;
               case '4':editDate(&date);
               break;
               case '5':editMonth(&month);
               break;
               case '6':editYear(&year);
               break;
               case '7':editDay(&day);
               break;
							 case '8':CmdLCD(0x01);
               return;
               default:CmdLCD(0x01);                
                       CmdLCD(0x80);
                       StrLCD("ERROR");
                       delay_s(1);
                       goto INPUT;
               }
    }
}
void editHour(s32 *hour)
{
        u32 h;
	      CmdLCD(0x01);
	      CmdLCD(0x80);
				StrLCD("ENTER HOUR");
				CmdLCD(0xC0);
	      h=ReadNum();// Read number
	      *hour=h;	      
				if(*hour>23) // Validation
				{
					CmdLCD(0x01);
					StrLCD("INVALID HOUR");
					delay_s(1);
					editHour(hour);// Retry
					return;
				}
	      HOUR=*hour; // Update RTC register
	      delay_s(1);
	      CmdLCD(0x01);
}
void editMin(s32 *min)
{
	      u32 m;
				CmdLCD(0x01);
	      CmdLCD(0x80);
				StrLCD("ENTER MIN");
				CmdLCD(0xC0);
	      m=ReadNum();
	      *min=m;
				if(*min>59)
				{
					CmdLCD(0x01);
					StrLCD("INVALID MIN");
					delay_s(1);
					editMin(min);
					return;
				}
	      MIN=*min;
	      delay_s(1);
	      CmdLCD(0x01);
	}
void editSec(s32 *sec)
{
				u32 s;
				CmdLCD(0x01);
	      CmdLCD(0x80);
				StrLCD("ENTER SEC");
				CmdLCD(0xC0);
        s=ReadNum();
	      *sec=s;
				if(*sec>59)
				{
					CmdLCD(0x01);
					StrLCD("INVALID SEC");
					delay_s(1);
					editSec(sec);
					return;
				}
				SEC=*sec;
	      delay_s(1);
	      CmdLCD(0x01);
}
void editDate(s32 *date)
{
	      u32 d;
	      CmdLCD(0x01);
	      CmdLCD(0x80);
	      StrLCD("ENTER DATE");
	      CmdLCD(0xC0);
	      d=ReadNum();
	      *date=d;
				if(*date>31)
				{
					CmdLCD(0x01);
					StrLCD("INVALID DATE");
					delay_s(1);
					editDate(date);
					return;
				}
	      DOM=*date;
	      delay_s(1);
	      CmdLCD(0x01);
}
void editMonth(s32 *month)
{
	         u32 m;
					 CmdLCD(0x01);
	         CmdLCD(0x80);
			     StrLCD("ENTER MONTH");
			     CmdLCD(0xC0);
	         m=ReadNum();
	         *month=m;
		 		   if(*month>12)
				   {
					   CmdLCD(0x01);
					   StrLCD("INVALID MONTH");
					   delay_s(1);
					   editMonth(month);
					   return;
				   }
			      MONTH=*month;
	          delay_s(1);
	          CmdLCD(0x01);
}
void editYear(s32 *year)
{
	      u32 y;
	      CmdLCD(0x01);
	      CmdLCD(0x80);
	      StrLCD("ENTER YEAR");
	      CmdLCD(0xC0);
	      y=ReadNum();
	      *year=y;
	      if(*year>4096)
				{
					CmdLCD(0x01);
					StrLCD("INVALID YEAR");
					delay_s(1);
					editYear(year);
					return;
				}
	        YEAR=*year;
	        delay_s(1);
	        CmdLCD(0x01);
}
void editDay(s32 *day)
{
          u32 dy;
          CmdLCD(0x01);
          CmdLCD(0x80);
          StrLCD("ENTER DAY ");
          CmdLCD(0xC0);
	        dy=ReadNum();
	        *day=dy;
          if(*day>7)
          {
               CmdLCD(0x01);
               StrLCD("INVALID DAY");
               delay_s(1);
               editDay(day);
               return;
          }
           DOW=*day;
           delay_s(1);
           CmdLCD(0x01);
}

void medicineTimeEdit()
{
        u8 sel;
        while(1)
        {
LABEL:  CmdLCD(0x01);
				CmdLCD(0x80);
        StrLCD("1.M1 ");
        StrLCD("2.M2");
        CmdLCD(0xC0);
        StrLCD("3.M3 ");
        StrLCD("4.EXIT");
        sel=KeyScan();
        switch(sel)
        {
                case '1':editM1_time();
                         break;
                case '2':editM2_time();
                         break;
                case '3':editM3_time();
                         break;
					      case '4':CmdLCD(0x01);
									       return;
                default:CmdLCD(0x01);
									      CmdLCD(0x80);
                        StrLCD("ERROR");
                        delay_s(1);
					              goto LABEL;
				}
      }
}
void editM1_time()
{
	      u8 x[3],y[3];
	      u32 i;
	      CmdLCD(0x01);
        CmdLCD(0x80);
				StrLCD("M1:");
        StrLCD("ENTER HOUR");
				CmdLCD(0xC0);
	      for(i=0;i<2;i++)
				{
	        x[i]=KeyScan();
					delay_ms(10);
					CharLCD(x[i]);
				}		
				m1_h=atoi(x);
				delay_ms(100);
	      CmdLCD(0x01);
        CmdLCD(0x80);
        StrLCD("ENTER MIN");
				CmdLCD(0xC0);
	      for(i=0;i<2;i++)
				{
	        y[i]=KeyScan();
					delay_ms(10);
					CharLCD(y[i]);
				}
         m1_m=atoi(y);
	       delay_ms(100);
				 CmdLCD(0x01);
}
void editM2_time()
{
	      u32 i;
	      u8 x[3],y[3];
	      CmdLCD(0x01);
        CmdLCD(0x80);
      	StrLCD("M2:");
        StrLCD("ENTER HOUR");
				CmdLCD(0xC0);
	      for(i=0;i<2;i++)
				{
	        x[i]=KeyScan();
				  delay_ms(10);
					CharLCD(x[i]);
				}
         m2_h=atoi(x);
				 delay_ms(100);
	       CmdLCD(0x01);
         CmdLCD(0x80);
         StrLCD("ENTER MIN");
				 CmdLCD(0xC0);
				for(i=0;i<2;i++)
				{
	        y[i]=KeyScan();
				  delay_ms(10);
					CharLCD(y[i]);
				}
          m2_m=atoi(y);
          delay_ms(100);
          CmdLCD(0x01);
}
void editM3_time()
{
	       u8 x[3],y[3];
	       u32 i;
         CmdLCD(0x80);
	       StrLCD("M3:");
         StrLCD("ENTER HOUR");
				 CmdLCD(0xC0);
	       for(i=0;i<2;i++)
				 {
	         x[i]=KeyScan();
				   delay_ms(10);
				 	 CharLCD(x[i]);
				 }
           m3_h=atoi(x);
				   delay_ms(100);
           CmdLCD(0x01);
           CmdLCD(0x80);
           StrLCD("ENTER MIN");
				   CmdLCD(0xC0);
	       for(i=0;i<2;i++)
			  	{
	          y[i]=KeyScan();
				    delay_ms(10);
					  CharLCD(y[i]);
				  }
            m3_m=atoi(y);
				    delay_ms(100);
            CmdLCD(0x01);
}
// Convert ASCII string to integer
u32 atoi(u8* n)
{
	u32 res=0;
	while(*n)
	{
		res=(res*10)+(*n-48);// Convert ASCII to digit
		n++;
	}
	return res;
}
// Check medicine time
void check_med(void)
{
   if(((m1_h==hour)&&(m1_m==min)&&(SEC==0)))// Time match
    {
			int i=0;
      buzzer_on();// Start buzzer
      CmdLCD(0x01);
      StrLCD("TAKE MEDICINE ");
      for(i=0;i<600;i++)
			{
				delay_ms(100);
        if(flag1==1) // If user pressed interrupt button
				{
					break;
				}
			}
      CmdLCD(0x01);
      flag1=0;      // Reset flag               
      buzzer_off(); // Stop buzzer
    }
	}
