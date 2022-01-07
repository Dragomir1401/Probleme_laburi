#include <stdio.h>
#define NMAX 100

int binary_search(int n, int v[NMAX], int x)
{	
	int lo=1, hi=n+1;
	while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(x<=v[mid])
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    
    if(v[lo]==x)
        return lo-1;
    else
        return -1;
 
 
}
int main()
{
	int n, v[NMAX], x;
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		scanf("%d",	&v[i]);
	scanf("%d", &x);

	int pos=binary_search(n, v, x);
	printf("%d\n", pos);
	return 0;
		
}