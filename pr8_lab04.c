#include <stdio.h>
#define NMAX 100

int binary_search(int n, int v[NMAX], int x)
{   
    int lo = 0, hi = n;   

    while(lo < hi)
    {
        int mid=(lo+hi)/2;
        if(v[mid] >= x)
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
   
    return lo;
 
}
int main()
{
	int n, v[NMAX], x, y;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d",	&v[i]);
	scanf("%d%d", &x, &y);

	int left = binary_search(n, v, x);
    int right = binary_search(n, v, y);

    for(int i = left; i<=right; i++)
        printf("%d ", v[i]);
    printf("\n");
	return 0;
		
}