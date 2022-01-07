#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 31

struct __attribute__((__packed__)) person
{
    char name[NAME_LEN];
    int age;
};

int main()
{
    FILE *f = fopen("1-gigel.bin", "wb");
    struct person p1, p2;
    memset(p1.name, 0, NAME_LEN);
    p1.age = 0;
    scanf("%s%d", p1.name, &p1.age);

    fwrite(&p1, sizeof(p1), 1, f);

    fclose(f);
    f = fopen("1-gigel.bin", "rb");

    fread(&p2, sizeof(p1), 1, f);

    printf("%s %d\n", p2.name, p2.age);

    fclose(f);
    return 0;
}