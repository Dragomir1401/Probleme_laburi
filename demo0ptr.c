#include <stdio.h>

void read_array(int v[100], int *n)
{
    scanf("%d", n);
    for (int i=0; i<*n; i++)
       scanf("%d", &v[i]);

}
void print_adresses(int v[100], int n)
{
    for(int i=0; i<n; i++)
        printf("%d\t%p\n", v[i], &v[i]);

}
int main(void)
{
    int *a = 0x68;
    int *b = a;
    ++a;
    printf("%p\n", a);
    int v[100], n;
    read_array(v, &n);
    print_adresses(v, n);
    return 0;

}
