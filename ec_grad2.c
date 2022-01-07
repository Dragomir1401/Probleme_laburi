#include <stdio.h>
#include <math.h>
int main(void)
{
	float c1,c2,c3,d;
	scanf("%f",&c1);
	scanf("%f",&c2);
	scanf("%f",&c3);
	if(c1==0)
	{
	if(c2==0)
		{if (c3==0) printf("Ecuatia are o infinitate de solutii\n");
			else if(c2!=0) printf("Ecuatia nu are solutii\n");
		}
		else
			{if(c3==0) printf("Ecuatia are solutia 0\n");
				else printf("%f\n",-c3/c2);
			}
	}
	 else 
	 {
	 	d=c2*c2-4*c1*c3;
	 	if (d<0)
	 		{
	 			d=sqrt(-d);  
	 			printf("%f + %f*i\n %f %s %f*i\n",-c2/(2*c1),d/(2*c1),-c2/(2*c1),(-d/(2*c1)>0) ? ("+"):("-"),(-d/(2*c1)>0) ? (-d/(2*c1)):(d/(2*c1)));

	 		}
	 		else 
	 			{	d=sqrt(d);
	 				printf("%f\n%f\n",(-c2+d)/(2*c1),(-c2-d)/(2*c1));

	 			}
	 }
	return 0;
}