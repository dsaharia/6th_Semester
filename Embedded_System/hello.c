#include <8052.h>
 
void delay(void);
 
void main(void)
{
    while(1)
    {
         P2 = 0x04; // Turn ON all LED's connected to Port1
         delay();
         P2 = 0x03; // Turn OFF all LED's connected to Port1
         delay();
    }
}
 
void delay(void)
{
    int i,j;
    for(i=0;i<0xff;i++)
         for(j=0;j<0xff;j++);
}
