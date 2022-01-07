#include <stdio.h>
int main()
{
    FILE *f = fopen("2-gen.bin", "wb");
    int v[101], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        fwrite(&v[i], sizeof(int), 1, f);
    }
    
    fclose(f);
    return 0;
}