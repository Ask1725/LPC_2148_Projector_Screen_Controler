//Embedded C Program for DC Motor Interfacing using LPC21487.
#include<lpc214x.h>
unsigned int i=0;
int main()
{
IO1DIR &=(0<<16)&(0<<17)&(0<<18); //Declaring Port Pins P1.16,P1.18,P1.17 as
input
IO0DIR|=(1<<5)|(1<<6); //Declaring Port Pins P0.5 and P0.6 as Output
while(1)
{
//Clockwise Rotation of DC Motor
if(!(IO1PIN & (1<<16)))
{
IO0SET=0x00000040;
for(i=0;i<5760000;i++);
IO0CLR=0x00000040;
}
//if(!(IO1PIN & (1<<18)))
//{
// IO0PIN=0x00000060;
//}
//Anticlockwise Rotation of DC Motor
if(!(IO1PIN & (1<<17)))
{
IO0SET=0x00000020;
for(i=0;i<5760000;i++);
IO0CLR=0x00000020;
}
}
}
