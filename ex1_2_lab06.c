#include <stdio.h>
#include <stdlib.h>

void read_vect(int *nptr, int **vptr)
{   
    int my_n, *v;
    scanf("%d", &my_n);

    v = malloc(my_n * sizeof(int));
    if (v == NULL){
        *vptr = NULL;
        return;
    }

    for (int i = 0; i < my_n; i++)
        scanf("%d", &v[i]);

    *nptr = my_n;
    *vptr = v;
}

void print_vect(int n, int *v)
{   
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int *v, n;
    read_vect(&n, &v);
    print_vect(n, v);
    free(v);
    return 0;
}