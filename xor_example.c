#include <stdio.h>
char *binbin(int n);
int main()
{
 int a,x,r;
 a = 73;
 x = 170;
 printf(" %s %3dn",binbin(a),a);
 printf("^ %s %3dn",binbin(x),x);
 r = a ^ x;
 printf("= %s %3dn",binbin(r),r);
 return(0);
}
char *binbin(int n)
{
 static char bin[9];
 int x;
 for(x=0;x<8;x++)
 {
 bin[x] = n & 0x80 ? '1' : '0';
 n <<= 1;
 }
 bin[x] = '';
 return(bin);
}