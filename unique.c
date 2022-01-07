#include <stdio.h>
int main()
{
	int n, v[101], f[2021];
	scanf("%d", &n);

	for(int i=0; i<=2021; i++)
		f[i]=0;

	for(int i=1; i<=n; i++)
		{
		scanf("%d", &v[i]);
		f[v[i]]++;
		}

	for(int i=1; i<=n; i++)	
		if(f[v[i]]) 
			{
			printf("%d ", v[i]);
			f[v[i]]=0;
			}

	printf("\n");

	return 0;
}