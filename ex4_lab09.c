#include <stdio.h>
int return_size(char nume[30])
{
    FILE *f = fopen(nume, "r");
    char c;
    int size = 0;
    while (fscanf(f, "%c", &c) != EOF)
    {
        size++;
    }
    return size;
}
int main()
{
    char nume[20];
    scanf("%s", nume);
    printf("a.out has %d bytes", return_size(nume));
    return 0;
}