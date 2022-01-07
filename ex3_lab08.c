#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    char *nume;
    char grupa[6];
    double medie;
};

void read_struct(struct student *v)
{
    v->nume = malloc(30 * sizeof(char));
    if (v->nume == NULL){
        printf("NU S-A PUTUT ALOCA MEMORIE.");
        exit(-1);
    }
    scanf("%s%s%lf", v->nume, v->grupa, &v->medie);
}
void print_struct(struct student *v)
{
    printf("%s\t%s\t%.4lf\n", v->nume, v->grupa, v->medie);
    free(v->nume);
}

struct student *copy_struct(struct student *v)
{
    struct student *result = malloc(sizeof(struct student));
    if (result == NULL){
        printf("NU S-A PUTUT ALOCA MEMORIE.");
        exit(-1);
    }

    result->nume = malloc(30 * sizeof(char));
    if (result->nume == NULL){
        printf("NU S-A PUTUT ALOCA MEMORIE.");
        exit(-1);
    }
    result->medie = v->medie;
    strcpy(result->nume, v->nume);
    strcpy(result->grupa, v->grupa);
    return result;
}

int main()
{
struct student *struct1 = malloc(sizeof(struct student));
if (struct1 == NULL){
        printf("NU S-A PUTUT ALOCA MEMORIE.");
        exit(-1);
    }

read_struct(struct1);

struct student *struct2 = malloc(sizeof(struct student));
if (struct2 == NULL){
        printf("NU S-A PUTUT ALOCA MEMORIE.");
        exit(-1);
    }

struct2 = copy_struct(struct1);
strcpy(struct2->nume, "Florin");

print_struct(struct1);
print_struct(struct2);
free(struct1);
free(struct2);

return 0;
}