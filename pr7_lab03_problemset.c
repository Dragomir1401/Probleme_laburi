#include <stdio.h>
int is_prime(unsigned int n)
{
	if(n==2) return 1;
	if(!(n%2)) return 0; 
	for (int d=3; d*d<=n; d+=2)
		if(!(n%d)) return 0;
	return 1;

}
 
void print_closest_prime(unsigned int n)
{
	if (!(is_prime(n)))
	for(unsigned int i=1;i>0;i++)
		{
		if((is_prime(n+i)) && (is_prime(n-i))) {printf("%d\n%d\n", n+i, n-i); 
											break;
											}
		if(is_prime(n+i)) {printf("%d\n", n+i);
							 break;
								}
		if(is_prime(n-i)) {printf("%d\n", n-i);
							 break;
							}
		}
	
}

int main()
{
	int n;
	n=1;
	//print_closest_prime(9);
	while(n>0)
	{
		scanf("%d", &n);
		//printf("%d\n", n);
		if (n>0) 
			print_closest_prime(n);

	}
	return 0;
}





