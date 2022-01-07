//Dragomir Andrei 312CA
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int suma_cifrelor(int n)
{   
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main() {
    int n, x, y,z, copy;
    scanf("%d", &n);
    x=0;
    y=1;
    if(n>30) return 0;
    if(n==0)
        {
         printf("%d", x);
         return 0;
        }
    if(n==1)
    {
        printf("%d", y);
        return 0;
    }
    if(n==2)
    {
        printf("%d", x+y);
        return 0;
    }
    for(int i=2; i<=n; i++)
        {    
            z=suma_cifrelor(x) + suma_cifrelor(y);
            copy=y;
            y=z;
            x=copy;

        }
     printf("%d", z);  
          
    return 0;
}