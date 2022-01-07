#include <stdio.h>
#include <stdint.h>
int is_odd(int n)
{
    return n & 1;
}

int pow2(int n)
{
    return 1 << n;
}

int flip_bits(int n)
{
    return ~n;
}

void print_bits(uint32_t n)
{
    for (int i = 31; i >= 0; i--)
    {
        if (n & (1 << i))
        { // n & (00000...1 << i)
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");
}

int is_pow_of_2(unsigned x)
{
    return ((x != 0) && (x & (x - 1) == 0));
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", is_odd(n));
    printf("2 ^ %d = %d\n", n, pow2(n));
    printf("%d\n", flip_bits(n));
    uint32_t x;
    scanf("%u", &x);
    print_bits(x);
    unsigned t;
    scanf("%u", &t);
    printf("%d\n", is_pow_of_2(t));
    return 0;
}