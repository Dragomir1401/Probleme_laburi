#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//21 13 8 5 3 2 1 1
void fibo_print(long n, int contor) {

    long v[5000], x, y, z, i = 1;

    v[0] = 1;
    v[1] = 1;
    while (v[i] <= n){
        x = v[i-1];
        y = v[i];
        v[++i] = x + y;
    }

    for (int j = i - 1; j >= 0; j--)
        if (n - v[j] >= 0){
            n = n - v[j];
            printf("%d", 1);
        }
        else 
            printf("%d", 0);

    if (!contor) 
        printf("\n");
    
}

int main(void) {
  int n, ok = 0;
  long x;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%ld", &x);
    if (i == n - 1)
        ok = 1;
    fibo_print(x, ok);
  }
  
  return 0;
}
//377 233 144 89 55 34 21 13 8 5 3 2 1 1
//1 + 3 + 55 + 144