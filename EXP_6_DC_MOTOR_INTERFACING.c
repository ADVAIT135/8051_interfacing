/*Name : ADVAIT GURUNATH CHAVAN, PRN : 4119008, SEM : 6, T.E. ELECTRONICS
ESRTOS LAB, ELL603, EXP : 6- DC MOTOR INTERFACING WITH 8051*/
#include<reg51.h>
sbit incr = P3^2;   	//Speed Increment Switch
sbit dcr = P3^3; 		//Speed Decrement Switch
main ()
{
	unsigned char i = 0x80;		// i has the initial speed value = half speed = 80H
	P3 = 0xff;								// Configure P3 to acccept switches
	while (1)
	{
		if(!incr)								// if increment is pressed
		{
			while (!incr);					// wait till key is released
				if (i>10)							// if speed is more than minimum
				{
					i = i - 10;					// Increase the DC motor speed , by decreasing the count
				}
		}											// end of if
		if(!dcr)							// If decrement is pressed
			{
				while (!dcr); 		//wait till key is released
				if (i < 0xf0)     // if speed is less than maximum
				{
					i = i + 0xf0;			// Decrease the DC motor speed, by increasing the count
				}
			}										// end of if
		P0 = i; 							// Output the value to port P0 for speed control
		}											// end of while
}													// end of main
					