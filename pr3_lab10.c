#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 31

struct person
{
    char *name;
    int age;
};

int main()
{
    FILE *f = fopen("3-gigel.bin", "wb");
    struct person v[10], v1[10];
    char line[100];
    int n, size, size1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", line);
        v[i].name = strdup(line);
        scanf("%d", &v[i].age);
        size = strlen(v[i].name) + 1;
        fwrite(&size, sizeof(int), 1, f);
        fwrite(v[i].name, size, 1, f);
        fwrite(&v[i].age, sizeof(int), 1, f);
    }

    for (int i = 0; i < n; i++)
    {
        free(v[i].name);
    }

    fclose(f);
    return 0;
}