#include <stdio.h>
int nr_cifre(int n)
{		
	if (n==0) return 0;
	return 1 + nr_cifre(n/10);

}

int main(){

	int n;
	scanf("%d", &n);
	//scanf("%d", &k);
	printf("%d\n", nr_cifre(n));
	return 0;
}
