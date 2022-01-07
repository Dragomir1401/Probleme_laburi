#include <stdio.h>
int main()
{
    FILE *f = fopen("2-gen.txt", "r");
    int v[101], n = 0, x;
    while (fscanf(f, "%d", &x) != EOF)
    {
        ++n;
    }

    printf("%d\n", n);

    fseek(f, 0, SEEK_SET);

    while (fscanf(f, "%d", &x) != EOF)
    {
        printf("%d ", x);
    }
    printf("\n");
    fclose(f);
    return 0;
}