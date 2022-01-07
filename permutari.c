#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
#define MAX_ELEM 25
 
struct permutare {
  int elemente[MAX_ELEM];
  int n;
};
int identity(struct permutare p)
{
	for(int i=0;i<p.n;i++)
		if(p.elemente[i]!=i+1) return 0;
	return 1;

}
int grad_permutare(struct permutare p)
{
 	struct permutare copie;
    int grad=1;
   	for(int i=0;i<p.n;i++)
    	copie.elemente[i]=p.elemente[i];
    
    while(!identity(p))
    {
    for(int i=0;i<p.n;i++)
    	{
    	int a=p.elemente[i];
    	p.elemente[i]=copie.elemente[a-1];
    	}
    grad++;
    }

    return grad;
}
int main()
{
    int nr_permutari;
  scanf("%d", &nr_permutari);
  struct permutare p;

  for(int i = 0; i < nr_permutari; i++) 
  {
    scanf("%d", &p.n);

    for(int j = 0; j < p.n; j++) 
    {
      scanf("%d", &p.elemente[j]);
    }
    //printf("%d\n", identity(p));
    printf("%d\n", grad_permutare(p));
  }
  return 0;
}
/*
5
1 1
1
3 1 2 3
3
4 3 1 4 2
4
4 2 4 3 1
4
4 1 2 4 3
4

*/
