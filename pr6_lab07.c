#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 100

void sort_by_name(char **nume, char **prenume, char **varsta, int n);
void sort_by_surrname(char **nume, char **prenume, char **varsta, int n);
void sort_by_age(char **nume, char **prenume, char **varsta, int n);

int main(void)
{
    char s[NMAX], **nume, **prenume, **varsta;
    int n, opt;

    nume = malloc(sizeof(char *) * NMAX);
    prenume = malloc(sizeof(char *) * NMAX);
    varsta = malloc(sizeof(char *) * NMAX);

    scanf("%d%d\n", &n, &opt);

    for (int i = 0; i < n; i++){
        nume[i] = malloc(sizeof(char) * NMAX);
        scanf("%s", nume[i]);

        prenume[i] = malloc(sizeof(char) * NMAX);
        scanf("%s", prenume[i]);

        varsta[i] = malloc(sizeof(char) * NMAX);
        scanf("%s", varsta[i]);
    }

    if (opt == 1)
        sort_by_name(nume, prenume, varsta, n);
    if (opt == 2)
        sort_by_surrname(nume, prenume, varsta, n);
    if (!opt)
        sort_by_age(nume, prenume, varsta, n);


    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%s %s %s\n", nume[i], prenume[i], varsta[i]);
    }


    free(nume);
    free(prenume);
    free(varsta);
    return 0;
}
void sort_by_name(char **nume, char **prenume, char **varsta, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i+1; j < n; j++){
            if (strcmp(nume[i], nume[j]) > 0)
            {
                char *aux = malloc(sizeof(char) * NMAX);

                aux = nume[i];
                nume[i] = nume[j];
                nume[j] = aux;

                aux = prenume[i];
                prenume[i] = prenume[j];
                prenume[j] = aux;

                aux = varsta[i];
                varsta[i] = varsta[j];
                varsta[j] = aux;
            }
        }

}

void sort_by_surrname(char **nume, char **prenume, char **varsta, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i+1; j < n; j++){
            if (strcmp(prenume[i], prenume[j]) > 0)
            {
                char *aux = malloc(sizeof(char) * NMAX);

                aux = nume[i];
                nume[i] = nume[j];
                nume[j] = aux;

                aux = prenume[i];
                prenume[i] = prenume[j];
                prenume[j] = aux;

                aux = varsta[i];
                varsta[i] = varsta[j];
                varsta[j] = aux;
            }
        }

}

void sort_by_age(char **nume, char **prenume, char **varsta, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i+1; j < n; j++){
            if (strcmp(varsta[i], varsta[j]) > 0)
            {
                char *aux = malloc(sizeof(char) * NMAX);

                aux = nume[i];
                nume[i] = nume[j];
                nume[j] = aux;

                aux = prenume[i];
                prenume[i] = prenume[j];
                prenume[j] = aux;

                aux = varsta[i];
                varsta[i] = varsta[j];
                varsta[j] = aux;
            }
        }

}