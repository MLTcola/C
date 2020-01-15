#include <stdio.h>
void main()
{
	float y,x;
    	for(y = 1.5; y > -1.5; y -= 0.1)
     {
     	
	     for (x = -1.5f; x < 1.5f; x += 0.05f)
	     	{
	     float z = x * x + y * y - 1;
	     float f = z * z * z - x * x * y * y * y;
	     putchar(f <= 0.0f ? "@@@@@@@@@"[(int)(f * -8.0f)] : ' ');
	        }
     	 putchar('\n');
    }
}
