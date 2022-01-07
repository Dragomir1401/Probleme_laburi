#include <stdio.h>
int main()
{
    FILE *f = fopen("2-gen.bin", "r");
    int v[101], n = 0, x;
    while (fread(&x, sizeof(int), 1, f))
    {
        ++n;
    }

    printf("%d\n", n);

    fseek(f, 0, SEEK_SET);

    while (fread(&x, sizeof(int), 1, f))
    {
        printf("%d ", x);
    }
    printf("\n");
    fclose(f);
    return 0;
}