#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct rect{
	double x;
	double y;
	double w;
	double h;
}Rect;

/*Prototipi*/

Rect *rettangoli_grandi(Rect a[],int n,double areamin,int *ngrandi);
void *xmalloc(size_t size);

int main()
{
	Rect a[4]; 
	Rect **p;
	int i,n=3, ngrandi;
	double areamin=1.0;
	
	for(i=0;i<2;i++)
	{
		printf("\nInserisci w: ");
		scanf("%lf", &a[i].w);
		printf("\nInserisci h: ");
		scanf("%lf", &a[i].h);
	}
	
	printf("\n ngrandi fuori: %d", ngrandi);
		
	p = rettangoli_grandi(a,n,areamin,&ngrandi);	
	
	printf("\n ngrandi finito: %d", ngrandi);
	for(i=0;i<ngrandi;i++)
	{
		printf("\n\n\tRettangolo %d\n", i+1);
		printf("\nw: %lf\nh: %lf\n", p[i]->w,p[i]->h);
		printf("\n\n");
	}
	
}


Rect *rettangoli_grandi(Rect a[],int n,double areamin,int *ngrandi)
{
	Rect **b;
	int i,j=0;
	double areaA;
	
	b=(Rect**)xmalloc(n*sizeof(Rect*));
		printf("\n ngrandi no incr: %d", ngrandi);
	for(i=0;i<n;i++)
	{
		areaA = (a[i].w)*(a[i].h);
	
		printf("\nAreaA %lf > %lf ?  ", areaA,areamin);
	
		if(areaA>areamin)
		{
			printf(" si\n");
			
			b[j]=(Rect*)xmalloc(sizeof(Rect));
			*ngrandi++;
			b[j]->x=a[i].x;
			b[j]->y=a[i].y;
			b[j]->w=a[i].w;
			b[j]->h=a[i].h;
			j++;
			printf("\n ngrandi: %d", ngrandi);
		}
	}
	 if((*ngrandi)!=0)
	 {
	 
	 	return b;
	 }
	 else
	 {
	 	
	 	free(b);
	 	return -1;
	 }

}


void *xmalloc(size_t size) 
{
    void *p;

    p = malloc(size);

    if(p == NULL) {
        fprintf(stderr, "Errore\n");
        exit(-1);
    }

    return p;
}
