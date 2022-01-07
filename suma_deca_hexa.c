#include <stdio.h>
#include <math.h>
int main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	printf("\n");
	printf("%d\n",a+b);
	printf("%x\n",a+b);
	printf("\n");
	int max=(a+b+fabs(a-b))/2;
	int min=(a+b-fabs(a-b))/2;
	printf("%d\n%d\n",min,max);
	printf("\n");
	a>b ? (max=a, min=b):(min=a, max=b);
	printf("%d\n%d\n",min,max);
	return 0;

}