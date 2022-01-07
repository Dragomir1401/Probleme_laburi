#include <stdio.h>
#include <stdlib.h>
void free_matrix(int n, int **a)
{
    for (int i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
}
int **alloc_matrix(int n, int m)
{   
    int **a = malloc(n * sizeof(int *));
    if (a == NULL){
        return NULL;
    }

    for (int i = 0; i < n; i++){
        a[i] = malloc(m * sizeof(int));
        if (a[i] == NULL){
            free_matrix(i, a);
            return NULL;
        }
    }

    return a;
}

void read_matrix(int n, int m, int **a)
{
    for(int i=0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

}

void print_matrix(int n, int m, int **a)
{
    for(int i=0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

}

int main()
{
    int n, m, **a;
    scanf("%d%d", &n, &m);
    a = alloc_matrix(n, m);

    if (a == NULL)
        return -1;

    read_matrix(n, m, a);
    print_matrix(n, m, a);
    free_matrix(n, a);
    
    return 0;
}
