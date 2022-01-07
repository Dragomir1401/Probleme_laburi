#include <stdio.h>
#include <math.h>

int main()
{
	int a ,b;

	for (a = -50; a <= 50; a++)
		for (b = -50; b <= 50; b++)
			for (int i = -50; i <= 50; i++)
				if (a * a * a + b * b *b + i * i * i ==0)				
				{

				printf("%d %d %d\n", a, b, i);
				//if((a != b || b != i))  printf("%d %d %d\n", -a, -b, i);

				}


	return 0;
}