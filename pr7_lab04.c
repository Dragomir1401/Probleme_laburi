#include <stdio.h>
#define NMAX 100
int diff_array(int n, int v[NMAX], int m, int w[NMAX], int diff[NMAX])
{	
	int d=-1;
	for(int i=0; i<n; i++)
	{
		int gasit = 0;
		for(int j=0; j<m; j++)
			if(v[i] == w[j])
				{
				gasit=1;
				break;
				}
		if(!gasit) 
			diff[++d] = v[i];
			
	}
	return d;
}

int main()
{
	int n, v[NMAX], m, w[NMAX], diff[NMAX], d;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d",	&v[i]);
	scanf("%d", &m);
	for(int i=0; i<m; i++)
		scanf("%d",	&w[i]);

	d = diff_array(n, v, m, w, diff);
	for(int i=0; i<=d; i++)
		printf("%d ", diff[i]);

	printf("\n");

	d = diff_array(m, w, n, v, diff);
	for(int i=0; i<=d; i++)
		printf("%d ", diff[i]);

	printf("\n");
	return 0;
		
}