#include <stdio.h>
int gcd1(int n, int m)
{	
	while(n!=m)
	if(n>m)
		n=n-m;
	else 
		m=m-n;
	return n;
}
int gcd2(int n, int m)
{
	while(m)
	{
		int r = n % m;
		n=m;
		m=r;
	}
	return n;
}
int main()
{
	int n,m;
	scanf("%d", &n);
	scanf("%d", &m);
	printf("%d\n", gcd1(n, m));
	printf("%d\n", gcd2(n, m));
	return 0;
}