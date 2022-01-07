#include <stdio.h>

int power(int n, int k);
int nr_cifre(int n);
int invers(int n);
int palindrom(int n);
int next_palindrom(int n)
{
	if (palindrom(n)) return n;
	return next_palindrom(n+1);

}

int main(){

	int n,p;
	scanf("%d", &n);
	p=next_palindrom(n);
	printf("%d\n",p);
	return 0;

}

int nr_cifre(int n)
{		
	if (n==0) return 0;
	return 1 + nr_cifre(n/10);

}

int power(int n, int k)
{	
	if (k==0) return 1;
	return n * power(n, k-1);

}

int invers(int n)
{
	if (n==0) return 0;
	return (n%10) * power(10, nr_cifre(n)-1) + invers(n/10);
}

int palindrom(int n)
{
   if (n==invers(n)) return 1;
   return 0;
}