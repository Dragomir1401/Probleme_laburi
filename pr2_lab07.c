#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 100
void sort_strings(int n, char **v);
int main(void)
{
    char s[NMAX], **v;
    int n;
    v = malloc(sizeof(char *) * NMAX);
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++){
        v[i] = malloc(sizeof(char) * NMAX);
        fgets(v[i], NMAX, stdin);
        if (strstr(v[i], "\n"))
            *strstr(v[i], "\n") = '\0';
    }

    sort_strings(n, v);
    printf("\n");
    for (int i = 0; i < n; i++)
        puts(v[i]);
    return 0;
}
void sort_strings(int n, char **v)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i+1; j < n; j++){
            if (strlen(v[i]) > strlen(v[j]))
            {
                char *aux = malloc(sizeof(char) * NMAX);
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
            else 
                if (strlen(v[i]) == strlen(v[j]) && strcmp(v[i], v[j]))
                {
                    char *aux = malloc(sizeof(char) * NMAX);
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
                    

        }

}