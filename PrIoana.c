#include <stdio.h>
#define NMAX 100
#define NM 10

void construire_v_cf(int n, int array[NM])
{
    while (n != 0) {
        array[n % 10]++;
        n /= 10;
    }
}

int n_descrescator(int n, int v_cf[NM])
{
    int i;
    int n_d = 0;
    construire_v_cf(n, v_cf);
    for (i = 9; i >= 0; i--)
        if (v_cf[i] != 0)
            while (v_cf[i] != 0) {
                n_d = n_d * 10 + i;
                v_cf[i]--;
            }
    for (i = 0; i < 10; i++) {
        v_cf[i] = 0;
    }
    return n_d;
}

int n_crescator(int n, int v1_cf[NM])
{
    int i;
    int n_c = 0;
    construire_v_cf(n, v1_cf);

    for (i = 0; i < 10; i++)
        if (v1_cf[i] != 0)
            while (v1_cf[i] != 0) {
                n_c = n_c * 10 + i;
                v1_cf[i]--;
            }
     for (i = 0; i < 10; i++) {
        v1_cf[i] = 0;
    }
    return n_c;
}

int main(void)
{
    int i = 0, j, ok = 0, v_cf[NM] = {0}, x[NMAX], N, v1_cf[NM] = {0}, poz_final, poz_initial;
    scanf("%d", &N);
    while (!ok) {
        x[i] = n_descrescator(N, v_cf) - n_crescator(N, v1_cf);
        N = x[i];
        for (j = 0; j < i; j++){
            if (x[j] == x[i]){
                poz_initial = j;
                poz_final = i;
                ok = 1;
            }
        }
        i++;
    }
    
    printf("%d\n", poz_initial);
    for (j = poz_initial; j < poz_final; j++)
        printf("%d ", x[j]);
    return 0;
}