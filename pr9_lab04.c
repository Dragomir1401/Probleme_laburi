#include <stdio.h>
#define NMAX 100

void diagonal_function(int n, int m, int a[NMAX][NMAX], int col)
{
    int pivot = a[0][col];
    for(int i=0; i<n; i++)
    {
        if(i+col>=n)
            printf("%d ", a[i][i+col]);
        a[i][i+col] = 0;
    }
    printf("\n");

    printf("%d ", pivot);
    for(int i=1; i<n; i++)
    {
        if(col>0) 
        {
            printf("%d ", a[i][--col]);
            a[i][col]=0;
        }

    }

}
int main()
{
	int n, a[NMAX][NMAX], col, m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
		  scanf("%d", &a[i][j]);
	scanf("%d", &col);

	diagonal_function(n, m, a, col);

    printf("\n");
    for(int i=0; i<n; i++)
        {
        for(int j=0; j<m; j++)
          printf("%d ", a[i][j]);
        printf("\n");
        }

    printf("\n");
	return 0;
		
}