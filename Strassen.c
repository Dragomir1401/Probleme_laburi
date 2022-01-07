#include <stdio.h>
#include <stdlib.h>
void free_matrix_global(int **p, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(p[i]);
    }
    free(p);
}

void free_matrix_local(int n, int **a)
{
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
}

int **load_memory(int n, int m)
{
    int **a = malloc(n * sizeof(int *));
    if (a == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = malloc(m * sizeof(int));
        if (a[i] == NULL)
        {
            free_matrix_local(i, a);
            return NULL;
        }
    }

    return a;
}

int **add(int **M1, int **M2, int n)
{
    int **temp = load_memory(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] + M2[i][j];
    return temp;
}

int **subtract(int **M1, int **M2, int n)
{
    int **temp = load_memory(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = M1[i][j] - M2[i][j];
    return temp;
}

int **strassenMultiply(int **A, int **B, int n)
{
    if (n == 1)
    {
        int **C = load_memory(1, 1);
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    int **C = load_memory(n, n);
    int k = n / 2;
    int **A11 = load_memory(k, k);
    int **A12 = load_memory(k, k);
    int **A21 = load_memory(k, k);
    int **A22 = load_memory(k, k);
    int **B11 = load_memory(k, k);
    int **B12 = load_memory(k, k);
    int **B21 = load_memory(k, k);
    int **B22 = load_memory(k, k);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][k + j];
            A21[i][j] = A[k + i][j];
            A22[i][j] = A[k + i][k + j];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][k + j];
            B21[i][j] = B[k + i][j];
            B22[i][j] = B[k + i][k + j];
        }
    int **to_free1 = subtract(B12, B22, k);
    int **to_free2 = add(A11, A12, k);
    int **to_free3 = add(A21, A22, k);
    int **to_free4 = subtract(B21, B11, k);
    int **to_free5 = add(A11, A22, k);
    int **to_free6 = add(B11, B22, k);
    int **to_free7 = subtract(A12, A22, k);
    int **to_free8 = add(B21, B22, k);
    int **to_free9 = subtract(A11, A21, k);
    int **to_free10 = add(B11, B12, k);

    int **P1 = strassenMultiply(A11, to_free1, k);
    int **P2 = strassenMultiply(to_free2, B22, k);
    int **P3 = strassenMultiply(to_free3, B11, k);
    int **P4 = strassenMultiply(A22, to_free4, k);
    int **P5 = strassenMultiply(to_free5, to_free6, k);
    int **P6 = strassenMultiply(to_free7, to_free8, k);
    int **P7 = strassenMultiply(to_free9, to_free10, k);

    free_matrix_global(to_free1, k);
    free_matrix_global(to_free2, k);
    free_matrix_global(to_free3, k);
    free_matrix_global(to_free4, k);
    free_matrix_global(to_free5, k);
    free_matrix_global(to_free6, k);
    free_matrix_global(to_free7, k);
    free_matrix_global(to_free8, k);
    free_matrix_global(to_free9, k);
    free_matrix_global(to_free10, k);

    int **to_free11 = add(P5, P4, k);
    int **to_free12 = add(to_free11, P6, k);
    int **to_free13 = add(P5, P1, k);
    int **to_free14 = subtract(to_free13, P3, k);

    int **C11 = subtract(to_free12, P2, k);
    int **C12 = add(P1, P2, k);
    int **C21 = add(P3, P4, k);
    int **C22 = subtract(to_free14, P7, k);

    free_matrix_global(to_free11, k);
    free_matrix_global(to_free12, k);    
    free_matrix_global(to_free13, k);     
    free_matrix_global(to_free14, k); 

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[k + i][j] = C21[i][j];
            C[k + i][k + j] = C22[i][j];
        }

    free_matrix_global(A11, k);
    free_matrix_global(A12, k);
    free_matrix_global(A21, k);
    free_matrix_global(A22, k);
    free_matrix_global(B11, k);
    free_matrix_global(B12, k);
    free_matrix_global(B21, k);
    free_matrix_global(B22, k);
    free_matrix_global(P1, k);
    free_matrix_global(P2, k);
    free_matrix_global(P3, k);
    free_matrix_global(P4, k);
    free_matrix_global(P5, k);
    free_matrix_global(P6, k);
    free_matrix_global(P7, k);
    free_matrix_global(C11, k);
    free_matrix_global(C12, k);
    free_matrix_global(C21, k);
    free_matrix_global(C22, k);

    return C;
}

void read_matrix(int **a, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

void print_matrix(int **a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int n, **A, **B, **C;
    scanf("%d", &n);
    A = load_memory(n, n);
    B = load_memory(n, n);
    read_matrix(A, n, n);
    read_matrix(B, n, n);
    C = strassenMultiply(A, B, n);
    print_matrix(C, n, n);
    free_matrix_global(A, n);
    free_matrix_global(B, n);
    free_matrix_global(C, n);
    return 0;
}
