#include <stdio.h>
void swap_ptr(int *p, int *q)
{
    int aux;
    aux = *p;
    *p = *q;
    *q = aux;

}
int main(void)
{
    int *p = 0x1232c2, *q = 0x45652f6;
    swap_ptr(&p, &q);
    printf("%p\t%p\n", p, q);
    return 0;
}