#include <stdio.h>
#define MAX 100000

int multiply(int res[], int res_size) {
int carry = 0;

for (int i = 0; i < res_size; i++) {
    int prod = res[i] * 2 + carry;
    
    res[i] = prod % 10;
    carry = prod / 10;
}

while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
}
return res_size;
}
 
void power(int n)
{
 
if(n == 0 ){
    printf("%d", 1);
    return;
}
 
int res[MAX];
int res_size = 0;
int temp = 2;
 
while (temp != 0) {
    res[res_size++] = temp % 10;
    temp = temp / 10;
}
 
for (int i = 2; i <= n; i++)
    res_size = multiply(res, res_size);
 
for (int i = res_size - 1; i >= 0; i--)
    printf("%d", res[i]);
}
 
int main() 
{
int n;
scanf("%d", &n);
power(n);
return 0;
}