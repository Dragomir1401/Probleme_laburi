#include <stdio.h>
#define NMAX 100
void multiply_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX]);
void read_matrix(int n, int m, int a[NMAX][NMAX]);
void print_matrix(int n, int m, int a[NMAX][NMAX]);
void power_matrix(int n, int a[NMAX][NMAX], int k, int b[NMAX][NMAX])
{
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			b[i][j] = a[i][j];

	for(int i=1; i<k; i++)
		multiply_matrix(n, n, n, a, b, a);

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			b[i][j] = a[i][j];

}
int main()
{
	int a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX], n, k;
	scanf("%d%d", &n, &k);

	read_matrix(n, n, a);

	power_matrix(n, a, k, b);
	print_matrix(n, n, b);
	return 0;
}

void read_matrix(int n, int m, int a[NMAX][NMAX])
{
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &a[i][j]);

}
void print_matrix(int n, int m, int a[NMAX][NMAX])
{
	for(int i=0; i<n; i++)
		{
		for(int j=0; j<m; j++)
			printf("%d ", a[i][j]);
		printf("\n");
		}

}
void multiply_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX])
{
	int d[NMAX][NMAX];

	for(int i=0; i<n; i++)
		for(int j=0; j<p; j++)
			d[i][j]=0;

	for(int i=0; i<n; i++)
		for(int j=0; j<p; j++)
			for(int k=0; k<m; k++)
				d[i][j]+= a[i][k] * b[k][j];

	for(int i=0; i<n; i++)
		for(int j=0; j<p; j++)
			c[i][j]=d[i][j];

}

/*
4 4 3
0 1 1 1
1 1 1 1
0 10 0 0
0 10 0 0
-1 10 1 
-2 20 2 
-3 30 3 
-4 40 4 
*/
