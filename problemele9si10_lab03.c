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
	int p = n*m;
	printf("CMMDC ESTE %d\n", gcd1(n, m));
	//printf("CMMDC ESTE %d\n", gcd2(n, m));
	printf("CMMMC ESTE %d\n", p/gcd2(n, m));
	return 0;
}