/* Clasic o multime de numere, poate fi reprezentata ca un vector de valori.
Pentru fiecare valoare din set as folosi cate sizeof(int) octeti. 
Dacă știu care este NMAX (cel mai mare numar din set), pot sa transform o multime intr-un vector de frecvență.
v[x] == 1, daca numarul X exista in SET
v[x] == 0, daca numarul NU exista in SET
unsingned char v[NMAX]
Memorie utilizată NMAX octeti
Optimizare: in fiecare octet (element al unui vector unsigned char) putem reprezenta 8 valori de 0/1.
unsigned char v[ceil(NMAX/8)]
*/

#include <stdio.h>

#define SET_SIZE 100 // aceasta este o macrodefiniție (momentan o putem privi ca pe O CONSTANTA CARE ARE VALOAREA 100
typedef unsigned char SET[SET_SIZE];
// unsinged char[SET_SIZE] === SET

int is_in_set(SET s, int n)
{
    // Ma uit la al n % 8 bit din octetul i / 8
    return s[n / 8] & (1 << (n % 8));
}

void adauga_in_set(SET s, int n)
{
    // orice | 1 = 1

    s[n / 8] = s[n / 8] | (1 << (n % 8));
}

// Sa afiseze numerele din SET
void print_set(SET s)
{
    // Știu că toate numerele sunt cuprinse în intervalul [0, 8*SET_SIZE)
    // verific pentru fiecare numar din interval, daca exista in set

    for (int nr = 0; nr < 8 * SET_SIZE; nr++)
    {
        if (is_in_set(s, nr))
        {
            printf("%d ", nr);
        }
    }
    printf("\n");
}

void delete_from_set(SET s, unsigned int n)
{
    s[n / 8] = 0;
}
void initilizare_set(SET s)
{ // s = multime vida
    for (int i = 0; i < SET_SIZE; i++)
    { // pentru fiecare octet din set
        s[i] = 0;
    }
}

void delete_all_from_set(SET s)
{
    initilizare_set(s);
}

int card_set(SET s)
{
    int nr = 0;
    for (int i = 0; i < SET_SIZE; i++)
        if (s[i])
            nr++;
    return nr;
}

int is_empty_set(SET s)
{
    int ok = 0;
    for (int i = 0; i < SET_SIZE; i++)
        if (s[i])
            ok = 1;
    return ok;
}
int main()
{
    SET a; // unsigned char a[SET_SIZE];

    initilizare_set(a);

    adauga_in_set(a, 12);
    adauga_in_set(a, 64);
    adauga_in_set(a, 21);
    adauga_in_set(a, 12);
    delete_from_set(a, 21);
    adauga_in_set(a, 21);
    printf("card is %d\n", card_set(a));
    if (is_empty_set(a))
        printf("Set is not empty\n");
    else
        printf("Set is empty\n");
    print_set(a);
    printf("%d\n", is_in_set(a, 64));
    delete_all_from_set(a);
    if (is_empty_set(a))
        printf("Set is not empty\n");
    else
        printf("Set is empty\n");
    printf("card is %d\n", card_set(a));
    print_set(a);
    return 0;
}