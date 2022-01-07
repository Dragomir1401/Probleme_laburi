#include <stdio.h>
#define MAX_SIZE 100
void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
void selection_sort(int array[MAX_SIZE], int n)
{
    for (int i=0; i < n-1; i++)
    {
        int min_index = i;
        for (int j=i+1; j<n; j++)
            if(array[j] > array[min_index])
             min_index = j;
        swap(&array[min_index], &array[i]);
    }

}
void insertion_sort(int array[MAX_SIZE], int n)
{
    for (int i=1; i<n; i++)
    {
        int key = array[i];
        int j = i-1;
        while (j>=0 && array[j] > key)
        {
            array[j+1] = array[j];
            j = j -1;
        }
        array[j+1] = key;
    }

}
void read_array(int v[MAX_SIZE], int *n)
{
    scanf("%d", n);
    for (int i=0; i<*n; i++)
       scanf("%d", &v[i]);

}

void print_array(int v[MAX_SIZE], int *n)
{
    for (int i=0; i<*n; i++)
        printf("%d ", v[i]);
    printf("\n");

}
int main()
{
    int v[MAX_SIZE], n;
    read_array(v, &n);
    insertion_sort(v, n);
    print_array(v, &n);
    return 0;
}
