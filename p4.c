#include <stdio.h>
#define NMAX 10
void multiply_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX])
{
    for(int i = 0;i < m; i ++)
        for(int j = 0;j < p; j ++) {
            c[i][j]=0;

            for(int k = 0; k < n; k ++)
                c[i][j] += a[i][k] * b[k][j];
            }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < p; j ++)
            printf("%d ", c[i][j]); 
        printf("\n");
    }
}

int main()
{
    int n, m, p;
    int a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX];
    scanf("%d%d%d", &n, &m, &p);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            scanf("%d", &a[i][j]);

    for(int i = 0; i < m; i ++)
        for(int j = 0; j < p; j ++)
            scanf("%d", &b[i][j]);    

    multiply_matrix(n, m, p, a, b, c); 

    return 0;
}