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
    FILE *f = fopen("2-gigel.bin", "wb");
    int lungime;
    struct person p1, p2;

    p1.name = malloc(NAME_LEN * sizeof(char));
    p2.name = malloc(NAME_LEN * sizeof(char));

    memset(p1.name, 0, NAME_LEN);
    p1.age = 0;
    scanf("%s%d", p1.name, &p1.age);

    int lenght = strlen(p1.name) + 1;

    fwrite(&lenght, sizeof(int), 1, f);
    fwrite(p1.name, sizeof(char), lenght, f);
    fwrite(&p1.age, sizeof(int), 1, f);

    fclose(f);
    f = fopen("2-gigel.bin", "rb");

    fread(&lungime, sizeof(int), 1, f);
    fread(p2.name, sizeof(char), lenght, f);
    fread(&p2.age, sizeof(int), 1, f);

    printf("%s %d\n", p2.name, p2.age);

    free(p1.name);
    free(p2.name);
    fclose(f);
    return 0;
}
