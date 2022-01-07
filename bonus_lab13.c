#include <stdio.h>

int get_lsb(int n);
int get_msb(int n);
int swap_bits(unsigned int n);

int multiply(int a, int b)
{
    int pos = 0;
    int res = 0;
    while (b != 0)
    {
        if ((b & 1) == 1)
        {
            res += a << pos;
        }
        b >>= 1;
        pos++;
    }

    return res;
}

int division(int num1, int num2)
{
    int temp = 1, result = 0;

    while (num2 <= num1)
    {
        num2 <<= 1;
        temp <<= 1;
    }
    while (temp > 1)
    {
        num2 >>= 1;
        temp >>= 1;
        if (num1 >= num2)
        {
            num1 -= num2;
            result += temp;
        }
    }
    return result;
}

int modulo(int num1, int num2)
{
    int temp = 1, result = 0;

    while (num2 <= num1)
    {
        num2 <<= 1;
        temp <<= 1;
    }
    while (temp > 1)
    {
        num2 >>= 1;
        temp >>= 1;
        if (num1 >= num2)
        {
            num1 -= num2;
            result += temp;
        }
    }
    return num1;
}

int main()
{
    /**
	 * 5 * 3
	 *   101 * 011
	 * -----------
	 * 00101 +
	 * 01010 +
	 * 00000 +
	 * 01111
	 */
    unsigned int n;
    scanf("%d", &n);

    printf("%d with bits swapped is %d\n", n, swap_bits(n));

    printf("3 * 5 = %d\n", multiply(15, 4));

    printf("21 * 5 = %d\n", division(21, 5));

    printf("21 * 5 = %d\n", modulo(21, 5));

    printf("16 lsb %d\n", get_lsb(16));

    printf("56 lsb %d\n", get_msb(56));
}

int get_lsb(int n)
{
    int pos = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            return 1 << pos;
        }
        pos++;
        n >>= 1;
    }
    return 0;
}

int get_msb(int n)
{
    int pos = 31;
    int nr = 1 << 31;

    while (n != 0)
    {
        if (nr & n)
        {
            return 1 << pos;
        }
        pos--;
        nr >>= 1;
    }
    return 0;
}

int swap_bits(unsigned int n)
{
    unsigned int pos = 0, nr = 0, a, b;
    while (n)
    {
        a = n & 1;
        b = (n >> 1) & 1;
        nr += (a << (pos + 1)) + (b << pos);
        pos += 2;
        n >>= 2;
        //printf("%d %d\n", a, b);
    }
    return nr;
}