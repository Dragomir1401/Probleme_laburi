#include <stdio.h>
int main()
{
	int n, m1 = 0, m2 = 0, p1=1, p2=1, step=0, c;
	scanf("%d", &n);
	
	while (n)
	{
		c = n % 10;
		n /= 10;

		if (! (step % 2))  { 

							m1 = c * p1 + m1;
							p1 *= 10;

							}
					else
						  	{ 

							m2 = c * p2 + m2;
							p2 *= 10;

							}

	step++;

	}
	if (step % 2)  printf("%d\n", m2);
				else  printf("%d\n", m1);
	return 0;
}
//6 9 5 6 4 3 2 3 2
//9 6 3 3