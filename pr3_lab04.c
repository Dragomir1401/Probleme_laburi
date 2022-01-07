#include <stdio.h>
#define NMAX 100
void read_array(int v[], int n)
{
	for(int i=0; i<n; i++)
		scanf("%d", &v[i]);

}
void print_array(int v[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");

}
void sort_array(int v[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(v[i] > v[j])
			{
				v[i]=v[i]^v[j];
				v[j]=v[i]^v[j];
				v[i]=v[i]^v[j];

			}

}
//sortare prin selectie to do
int main()
{
	int n, v[NMAX];
	scanf("%d", &n);

	read_array(v, n);

	sort_array(v, n);

	print_array(v, n);
	return 0;
}