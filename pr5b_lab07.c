#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NMAX 100
void print_all_str_occurences(char *s, char *word)
{
char *p;
int k = 0;

p = strtok(s, " \t\n.;,?!_");
while(p){
    if (!strcmp(p, word))
        printf("%d\t", k);
    k += strlen(p) + 1;
    p = strtok(NULL, " \t\n.;,?!_");
}   
printf("\n");
}
int main(void)
{
char *s, *word;

s = malloc(sizeof(char) * NMAX);
word = malloc(sizeof(char) * NMAX);
fgets(s, NMAX, stdin);
if (strstr(s, "\n"))
    *strstr(s, "\n") = '\0';
fgets(word, NMAX, stdin);
if (strstr(word, "\n"))
    *strstr(word, "\n") = '\0';

print_all_str_occurences(s, word);

return 0;
}