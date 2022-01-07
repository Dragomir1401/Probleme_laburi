#include <stdio.h>
#include <stdlib.h>
void free_matrix_varlen(int n, int **a)
{
    for (int i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
}
int **alloc_matrix_varlen(int n, int m[])
{   
    int **a = malloc(n * sizeof(int *));
    if (a == NULL){
        return NULL;
    }

    for (int i = 0; i < n; i++){
        a[i] = malloc(m[i] * sizeof(int));
        if (a[i] == NULL){
            free_matrix_varlen(i, a);
            return NULL;
        }
    }

    return a;
}

void read_matrix(int n, int m[], int **a)
{
    int contor = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m[i]; j++)
            a[i][j] = contor++;

}

void print_matrix(int n, int m[], int **a)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m[i]; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

}

int main()
{
    int n, m[100], **a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &m[i]);
    }
    a = alloc_matrix_varlen(n, m);

    if (a == NULL)
        return -1;

    read_matrix(n, m, a);
    print_matrix(n, m, a);
    free_matrix_varlen(n, a);
    
    return 0;
}
