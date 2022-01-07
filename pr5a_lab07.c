#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NMAX 100
void print_all_char_occurences(char *s, char c)
{
for(int i = 0; i < strlen(s) - 1; i++)
    if(c == s[i])
        printf("%d\t", i);
}
int main(void)
{
char *s;
char c;

s = malloc(sizeof(char) * NMAX);
fgets(s, NMAX, stdin);
if (strstr(s, "\n"))
    *strstr(s, "\n") = '\0';
scanf("%c", &c);


print_all_char_occurences(s, c);

return 0;
}