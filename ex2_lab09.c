#include <stdio.h>
int main()
{
    FILE *f = fopen("2-gen.txt", "w");
    int v[101], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        fprintf(f, "%d ", v[i]);
    }
    
    fclose(f);
    return 0;
}