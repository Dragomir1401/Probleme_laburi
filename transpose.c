#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define NMAX 100

// functia printeaza transpusa matricei a la stdout
// a are n linii; linia i are m[i] elemente
// functia printeaza mai intai dimensiunile, apoi matricea, conform indicatiilor din enunt
void transpose_matrix_varlen(int n, int m[NMAX], int a[NMAX][NMAX])
{   
    printf("%d", n);
    int b[NMAX][NMAX], k, v[NMAX][NMAX], dim[NMAX], l=-1, copie[NMAX];

    for (int j = 0; j <= n; ++j)
        {
        k=0;
        for (int i = 0; i < n; ++i) 
                v[j][k++]=a[i][j];
        dim[j]=k;
        }

    printf("\n");
    for (int i = 0; i <= n; ++i)
        copie[i]=dim[i];

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < dim[i]; ++j)
        {   
            if (!v[i][j]) {
                            copie[i]--;
                            continue;
                            }
        }
    }
    
    for(int i=0; i <= n; ++i)
        printf("%d ", copie[i]);
    
    printf("\n");

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j < dim[i]; ++j)
        {   
            if (!v[i][j]) continue;
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    
    int m[NMAX];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m[i]);
    }
    
    int a[NMAX][NMAX];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m[i]; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    
    transpose_matrix_varlen(n, m, a);

    return 0;
}

/*
5
3 2 5 1 4
10 20 30
1 2
1 2 3 4 5
100
9 9 9 9
*/