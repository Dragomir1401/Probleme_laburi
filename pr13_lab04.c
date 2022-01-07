#include <stdio.h>
#define NMAX 100
void swap_matrix_rows(int n, int m, int a[NMAX][NMAX], int row_index1, int row_index2);
void swap_matrix_cols(int n, int m, int a[NMAX][NMAX], int col_index1, int col_index2);
void print_matrix(int n, int m, int a[NMAX][NMAX])
{
	for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        	printf("%d ", a[i][j]);
        printf("\n");
    }

}
void read_matrix(int n, int m, int a[NMAX][NMAX])
{
	for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        	scanf("%d", &a[i][j]);

}
int main()
{
	int a[NMAX][NMAX], n, m;
	scanf("%d%d", &n, &m);
	read_matrix(n, m, a);
    swap_matrix_rows(n, m, a, 0, 1);
    swap_matrix_cols(n, m, a, 0, 1);
    printf("\n");
    print_matrix(n, m, a);
	return 0;
}

void swap_matrix_rows(int n, int m, int a[NMAX][NMAX], int row_index1, int row_index2)
{
    for(int j=0; j<m; j++)
    {
    	int aux = a[row_index1][j];
    	a[row_index1][j] = a[row_index2][j];
    	a[row_index2][j] = aux;
    }
}
void swap_matrix_cols(int n, int m, int a[NMAX][NMAX], int col_index1, int col_index2)
{
    for(int i=0; i<n; i++)
    {
    	a[i][col_index1] = a[i][col_index1] ^ a[i][col_index2];
    	a[i][col_index2] = a[i][col_index1] ^ a[i][col_index2];
    	a[i][col_index1] = a[i][col_index1] ^ a[i][col_index2];
    }

}
