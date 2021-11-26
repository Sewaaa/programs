/*
Realizzare un programma che legga due array
A e B (funzione leggi), rispettivamente di n ed
m elementi, e stampi tutti gli elementi
presenti in B, ma non in A (funzione
differenza).
*/

#include <stdio.h>
#define maxn 50
#define maxm 50
#define maxdiff 50

int leggiLista(int lista[ ], int max);
void stampaLista(int lista[ ], int n);
void differenza(int a[],int b[],int n,int m);
int  ricerca(int a[], int n,int elem);

int main()
{
	
	int a[maxn],b[maxm],n,m;
	
	n=leggiLista(a,maxn);
	m=leggiLista(b,maxm);
	
	printf("\n Vettore A inserito: ");
	stampaLista(a,n);
	printf("\n Vettore B inserito: ");
	stampaLista(b,m);
	
	differenza(a,b,n,m);
	
}

int leggiLista(int lista[ ], int max)
{
     int n=0, val;
     printf("\t\tIMMETTERE UNA SEQUEZA DI VALORI, 0 PER TERMINARE\n");
     while (n<max)
     {
           printf("\n Inserisci il [%d] valore: ",n);
           scanf("%d", &val);
           if (val == 0)  break;
           lista[n] = val;
           n++;
      }
     return n;
}

void stampaLista(int lista[ ], int n)
{
     int i;
     for (i=0; i<n; i++)
     {
           printf(" %d", lista[i]);
      }
    printf("\n");
}

void differenza(int a[],int b[],int n,int m)
{
	int i,j,z=0,el,pos=-1,c[50];
	
	for(i=0;i<m;i++)
	{
		el=b[i];
		pos=ricerca(a,n,el);
		
		if(pos!=1)
		{
			c[z]=b[i];
			z++;	
		}
	}
	printf("\n\tB - A = ");
	stampaLista(c,z);
}

int  ricerca(int a[], int n,int elem) 
{
	
    int i = 0;                               	
    while(i < n)                     
 	{      if (a[i] == elem)
                    break;        
          else i++;    
    }            
   
    if(i == n)
	{ 
		return -1;  				/* se non trovato  */
	}
	else
	{	
		return 1;
	}
  	                /* altrimenti la posizione dell’elemento */
}

