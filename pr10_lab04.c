#include <stdio.h>
#define NMAX 100

void print_submatrix(int a[NMAX][NMAX], int x, int y, int p, int q)
{
    for(int i=x; i<=p; i++)
        {
        for(int j=y; j<=q; j++)
            printf("%d ", a[i][j]);
        printf("\n");
        }

}
int sum_submatrix(int a[NMAX][NMAX], int x, int y, int p, int q)
{   
    int sum = 0;
    for(int i=x; i<=p; i++)
        for(int j=y; j<=q; j++)
            sum += a[i][j];
    return sum;

}
void copy_submatrix(int a[NMAX][NMAX], int x, int y, int p, int q, int b[NMAX][NMAX])
{
    for(int i=x; i<=p; i++)
        for(int j=y; j<=q; j++)
            b[i][j]=a[i][j];
}
void print_max_submatrix(int a[NMAX][NMAX], int n)
{
    int max=0;
    int b[NMAX][NMAX], i1, i2, i3, i4;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=i; k<n; k++)
               for(int l=j; l<n; l++)
                    if(sum_submatrix(a, i, j, k, l) > max) 
                    {
                        max = sum_submatrix(a, i, j, k ,l);
                        copy_submatrix(a, i, j, k, l, b);
                        i1=i;
                        i2=j;
                        i3=k;
                        i4=l;
                    }
                    
    print_submatrix(b, i1, i2, i3, i4);


}
int main()
{
	int n, a[NMAX][NMAX];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
		  scanf("%d", &a[i][j]);
    printf("\n");
	print_max_submatrix(a, n);

    printf("\n");
	return 0;
		
}