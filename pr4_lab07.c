#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NMAX 100
int count_occurences(char *s, char *word)
{
int nr = 0;
char *p;

p = strtok(s, " \t\n.;,?!");
while(p){
    if (!strcmp(p, word))
        nr++;
    p = strtok(NULL, " \t\n.;,?!");
}

return nr;
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
int nr = count_occurences(s, word);

printf("%d\n", nr);
return 0;
}