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
int main()
{
	int n, v[NMAX];
	scanf("%d", &n);
	read_array(v,n);
	print_array(v,n);
	return 0;
}