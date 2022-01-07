#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    char *nume;
    char grupa[6];
    double medie;
};
void ord_alpha(struct student *v, int n)
{
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if(strcmp(v[i].nume, v[j].nume))
        {
            char *aux;
            strcmp(aux, v[i].nume);
            strcmp(v[i].nume, v[j].nume);
            strcmp(v[j].nume, aux);
        }
}
void read_struct(struct student *v, int n)
{
    for (int i = 0; i < n; i++){
        v[i].nume = malloc(30 * sizeof(char));
        if (v[i].nume == NULL){
            printf("NU S-A PUTUT ALOCA MEMORIE.");
            exit(-1);
        }
        scanf("%s%s%lf", v[i].nume, v[i].grupa, &v[i].medie);
    }
    
}
void print_struct(struct student *v, int n)
{
    for (int i = 0; i < n; i++){
        printf("%s\t%s\t%.4lf\n", v[i].nume, v[i].grupa, v[i].medie);
        free(v[i].nume);
    }
}


int main()
{
int n;
scanf("%d", &n);

struct student *v = malloc(n * sizeof(struct student));
if (v == NULL){
        printf("NU S-A PUTUT ALOCA MEMORIE.");
        exit(-1);
    }

read_struct(v, n);
ord_alpha(v, n);
print_struct(v, n);
free(v);
return 0;
}