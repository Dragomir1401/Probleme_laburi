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
    FILE *f = fopen("3-gigel.bin", "rb");
    int size;
    struct person v[10];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        fread(&size, sizeof(int), 1, f);
        v[i].name = malloc(size);
        fread(v[i].name, size, 1, f);
        fread(&v[i].age, sizeof(int), 1, f);
        printf("%s %d\n", v[i].name, v[i].age);
    }
    return 0;
}
