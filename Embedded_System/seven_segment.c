#include <8052.h>
 
void delay(void);
 
void main(void)
{
    unsigned char i;
    unsigned char a[] = {192, 249, 164, 176, 153, 146, 130, 248, 128, 152};
    P2 = 0x00;

    while(1)
    {
         for (i = 0; i <=9 ; ++i)
         {
             P2 = a[i];
             delay();
         }
    }
}
 
void delay(void)
{
    int i,j;
    for(i=0;i<0xff;i++)
         for(j=0;j<0xff;j++);
}
#include <8052.h>


