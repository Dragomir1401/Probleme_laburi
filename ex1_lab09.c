#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f = fopen("1-gen.txt", "w+");
    if (f == NULL)
    {
        printf("Cannot open file.");
        exit(-1);
    }
    char s[30], s1[30];
    int varsta, varsta1;
    scanf("%s", s);
    scanf("%d", &varsta);

    fprintf(f, "%s %d\n", s, varsta);

    fscanf(f, "%s", s1);

    fscanf(f, "%d", &varsta1);

    printf("saved_name = %s\nsaved_age = %d\n", s1, varsta1);

    fclose(f);
    return 0;
}