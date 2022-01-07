#include <stdio.h>
int is_prime(unsigned int n)
{
	printf("%d\n", n);
	if(n==2) return 1;
	if(!(n%2)) return 0; 
	for (int d=3; d*d<=n; d+=2)
		if(!(n%d)) return 0;
	return 1;

}
int main(){

	int n, ok;
	scanf("%d", &n);
	ok = is_prime(n);
	printf("%d\n",ok);
	return 0;

}