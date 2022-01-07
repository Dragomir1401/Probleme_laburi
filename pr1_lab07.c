#include <stdio.h>
#include <string.h>
#define NMAX 1000
void is_palindrome(char *s)
{
    int ok = 1;
    for (int i = 0, j = strlen(s) - 2; i < strlen(s) / 2 && j > strlen(s) / 2; i++, j--)
        {
            if (s[i] == ' ') 
                i++;
            if (s[j] == ' ') 
                j--;
            printf("%c %c\n", s[i], s[j]);
            if (s[i] != s[j]){
                ok = 0;
                break;
            }
        }
    if (ok)
        printf("PALINDROME\n");
    else 
        printf("NOT PALINDROME\n");
}
int main(void)
{
    char s[NMAX];
    fgets(s, NMAX, stdin);
    is_palindrome(s);
    return 0;
}