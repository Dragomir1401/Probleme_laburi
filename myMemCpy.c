#include <stdio.h>
void myMemCpy(void *dest, const void *src, int num)
{
    char *csrc = (char *)src;
    char *cdst = (char *)dest;

    for(int i=0; i<num; i++)
        cdst[i] = csrc[i];

}
int main()
{
    int a =123;
    int b;
    myMemCpy(&b, &a, sizeof(a));
    printf("%d\n", b);

    int src[10] = {1, 2, 3};
    int dst[10];
    myMemCpy(dst, src, sizeof(src));
    for (int i=0; i < sizeof(src)/sizeof(int); i++)
        printf("%d ", dst[i]);
    printf("\n");

    int n;
    double src1[10], dst1[10];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%lf", &src1[i]);
    myMemCpy(dst1, src1, n * sizeof(double));
    for(int i=0; i<n; i++)
        printf("%.3lf ", dst1[i]);
    printf("\n");
    
    return 0;
}