#include <stdio.h>
int main(void)
{
	float c1,c2;
	scanf("%f",&c1);
	scanf("%f",&c2);
	//printf("Ecuatia are o infinitate de solutii");
	if(c1==0)
		{if (c2==0) printf("Ecuatia are o infinitate de solutii\n");
			else if(c2!=0) printf("Ecuatia nu are solutii\n");
		}
		else
			{if(c2==0) printf("Ecuatia are solutia 0\n");
				else printf("%f\n",-c2/c1);
			}
	return 0;
}