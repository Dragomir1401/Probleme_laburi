#include<stdio.h>
int main()
{
int a,b,c,n,x,y,s=0,n1,i;
int s1=0,nr=0;
float m1;
int m;
scanf("%d",&n);
 switch(n){
        case 1:{scanf("%d",&a);
				scanf("%d",&b);
				scanf("%d",&c);
				m1=(float)(a+b+c)/3;
				printf("%.4f",m1);
				break;
			}
		case 2:{scanf("%d",&m);
				
				for(i=2;i<m;i++){int prim=1;
				
				for(int d=2;d<=i/2;d++)if(d%i==0)prim=0;
					if(prim==1){s1=s1+i;
								nr=nr+1;
					}
				}
				printf("%d ",s1);
				printf("\n%d ",nr);
				
				
			
			break;
		}
		case 3:{scanf("%d",&x);
			if(x==0)y=3-x;
				else if(x>=1&&x<=4)y=3;
						else if(x>4)y=3*x-9;
						printf("%d",y);

			break;
		
		}
		case 4:{scanf("%d",&n1);
				for(int i=1;i<n1;i++)
				if(i%3==0 || i%5==0)s=s+i;
					printf("%d",s);

			break;
		}
		 default:printf("Ati introdus un numar din afara intervalului!");
	}
	return 0;
}