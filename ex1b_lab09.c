#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    FILE *f = fopen("1-gen.bin", "wb");
    if (f == NULL){
        printf("Cannot open file.");
        exit(-1);
    }
    char s[30];
    int varsta;
    scanf("%s", s);
    scanf("%d", &varsta);

    int lenght = strlen(s) + 1;
    fwrite(&lenght, sizeof(int), 1, f);
    fwrite(s, sizeof(char), strlen(s) + 1, f);
    fwrite(&varsta, sizeof(int), 1, f);
    
    fclose(f);
    return 0;

}