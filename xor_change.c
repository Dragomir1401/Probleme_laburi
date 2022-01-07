#include <stdio.h>
int main()
{
	int x,y,z,timp;
	scanf("%d",&x);
	scanf("%d",&y);
	scanf("%d",&z);
	scanf("%d",&timp);
	x=x^y;
	y=x^y;
	x=x^y;	
	printf("\n");
	printf("%d\n%d\n",x,y);
	printf("\n");
	x=x+y;
	y=x-y;
	x=x-y;
	printf("\n");
	printf("%d\n%d\n",x,y);
	printf("\n");
	if(y>=x&&y<=z&&x<z) printf("Y apartine intervalului [x,z}");
					else printf("Y nu apartine intervalului [x,z}");

	printf("\n");
	if(!timp%(3600*24)) printf("%d zile \n",timp/(3600*24));
		else if  (timp>(3600*24))   printf("%d zile %d ore %d minute %d secunde\n",timp/(3600*24),((timp%(3600*24))/3600),(((timp%(3600*24))%3600)/60),(((timp%(3600*24))%3600)%60));
	return 0;
}