#include <stdio.h>
#define NMAX 100
void multiply_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX]);
void read_matrix(int n, int m, int a[NMAX][NMAX]);
void print_matrix(int n, int m, int a[NMAX][NMAX]);

int main()
{
	int a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX], n, m ,p;
	scanf("%d%d%d", &n, &m, &p);

	read_matrix(n, m, a);
	read_matrix(m, p, b);
	printf("\n");

	multiply_matrix(n, m, p, a, b, c);
	print_matrix(n, p, c);
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
	for(int i=0; i<n; i++)
		for(int j=0; j<p; j++)
			c[i][j]=0;

	for(int i=0; i<n; i++)
		for(int j=0; j<p; j++)
			for(int k=0; k<m; k++)
				c[i][j]+= a[i][k] * b[k][j];

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
