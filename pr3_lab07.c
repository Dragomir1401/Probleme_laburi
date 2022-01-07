#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NMAX 100

int main(void)
{
char *s, *p;

s = malloc(sizeof(char) * NMAX);
fgets(s, NMAX, stdin);
if (strstr(s, "\n"))
    *strstr(s, "\n") = '\0';

int nr = 0;

p = strtok(s, " \t\n.;,?!");
while(p){
    puts(p);
    int ok = 1;
    for(int i = 0; i < strlen(p) - 1; i++)
        if(!isalpha(p[i]))
            ok = 0;
    if (ok)
        nr++;
    p = strtok(NULL, " \t\n.;,?!");
}

printf("%d\n", nr);
return 0;
}