#include <stdio.h>
void descompunere(int n);
int suma_div(int n);
int main()
{
	int n;
	scanf("%d", &n);
	descompunere(n);
	printf("%d este suma divizorilor lui %d.\n", suma_div(n), n);
	return 0;
}

void descompunere(int n)
{
	int d=2, p, copie=n, first=0;;
	printf("%d = ", n);
	while(n!=1)
	{
		if(!(n%d))
		{	
			first++;	
			p=0;
			while(!(n%d)) 
			{
				n/=d;
				p++;
			}

			if (first==1) printf("%d ^ %d", d, p);
			else printf(" + %d ^ %d", d, p);
		}
	d++;
	}
	printf("\n");
}

int suma_div(int n)
{
	int suma=0;
	for (int d=2;d<=n/2;d++)
		if(!(n%d)) suma+=d;
	return suma;
}