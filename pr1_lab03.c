#include <stdio.h>
int power(int n, int k)
{	
	if (k==0) return 1;
	return n * power(n, k-1);

}

int main(){

	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	printf("%d\n", power(n, k));
	return 0;
}
