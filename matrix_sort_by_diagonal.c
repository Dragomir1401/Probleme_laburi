#include <stdio.h>
#define MAX_SIZE 100
void read_matrix(int matrix[MAX_SIZE][MAX_SIZE], int *n, int *m)
{
    scanf("%d%d", n, m);
    for (int i = 0; i < *n; i++)
        for(int j = 0; j < *m; j++)
            scanf("%d", &matrix[i][j]);

}

void print_matrix(int matrix[MAX_SIZE][MAX_SIZE], int *n, int *m)
{
    for (int i = 0; i < *n; i++){
        for(int j = 0; j < *m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void swap_lines(int matrix[][MAX_SIZE], int m, int a, int b)
{
    for (int j=0; j < m; j++) 
        swap(&matrix[a][j], &matrix[b][j]);     

}
void sort_by_diagonal(int matrix[MAX_SIZE][MAX_SIZE], int n, int m)
{
    for (int i=0; i < n-1; i++)
        for (int j=i+1; j < n; j++)
            if(matrix[i][i] > matrix[j][j])    
                swap_lines(matrix, m, i ,j);   
}
int main()
{
    int matrix[MAX_SIZE][MAX_SIZE], n, m;
    read_matrix(matrix, &n, &m);
    sort_by_diagonal(matrix, n, m);
    printf("\n");
    print_matrix(matrix, &n, &m);
    printf("\n");
    int *p;
    p = &matrix[2][2];
    *p = 134;
    printf("%d\t%d\n", *p, matrix[2][2]);
    printf("%p\t%p\n", p, &matrix[2][2]);
    return 0;

}