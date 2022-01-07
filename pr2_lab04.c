#include <stdio.h>
#define NMAX 100
void read_array(int v[], int n)
{
	for(int i=0; i<n; i++)
		scanf("%d", &v[i]);

}
void print_array(int v[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");

}
int sum_array(int v[], int n)
{
	int sum=0;
	for(int i=0; i<n; i++)
		sum+=v[i];

	return sum;
}
int min_array(int v[], int n)
{
	int min=v[0];
	for(int i=1; i<n; i++)
		if(v[i]<min) min=v[i];

	return min;
}
int posmax_array(int v[], int n)
{
	int max=v[0], pos;
	for(int i=1; i<n; i++)
		if(v[i]>max) 
			{
			max=v[i];
			pos=i;
			}

	return pos;
}
double avg_array(int v[], int n)
{
	double avg= (double)sum_array(v, n) / n;
	return avg;
}
int find_array(int v[], int n, int x)
{
	int pos=-1;
	for(int i=0; i<n; i++)
		{
		if(v[i]==x)
			{
			pos=i;
			return pos;
			}
		}
	return pos;
}
int main()
{
	int n, v[NMAX], sum, min, posmax, pos;
	double avg;
	scanf("%d", &n);
	read_array(v,n);
	printf("\n");
	
	sum=sum_array(v,n);
	printf("%d\n", sum);
	printf("\n");

	min=min_array(v,n);
	printf("%d\n", min);
	printf("\n");

	posmax=posmax_array(v,n);
	printf("%d\n", posmax);
	printf("\n");

	avg=avg_array(v, n);
	printf("%.2lf\n", avg);
	printf("\n");

	pos=find_array(v, n, 2321);
	printf("%d\n", pos);
	printf("\n");
	return 0;
}