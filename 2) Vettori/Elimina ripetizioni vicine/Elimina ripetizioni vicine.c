/*
Scrivere analisi, specifica, progettazione e realizzazione 
di una funzione compatta(), che riceve un vettore A di taglia MAXDIM
 riempito con n elementi, e lo modifica in modo che elementi
  consecutivi uguali siano sostituiti da un'unica occorrenza. 
  La funzione deve restituire il numero di elementi rimasti.
*/

#include <stdio.h>
#define maxdim 50


int leggiLista(int lista[ ], int max);
void stampaLista(int lista[ ], int n);
int uguaglianza(int lista[],int n);
void swap(int lista[],int n, int i);

int main()
{
	int vett[maxdim],n;
	
	n=leggiLista(vett,maxdim);
	printf("\n Vettore inserito: ");
	stampaLista(vett,n);
	
	n=uguaglianza(vett,n);
	printf("\n Vettore senza ripetizioni: ");
	stampaLista(vett,n); 
}

int leggiLista(int lista[ ], int max)
{
     int n=0, val;
     printf("Immettere una sequenza di valori, 0 per terminare");
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
     printf("\n");
     for (i=0; i<n; i++)
     {
           printf(" %d", lista[i]);
      }
}

int uguaglianza(int lista[],int n)
{
	int i=0;
	while(i<n-1)
	{
		if(lista[i]==lista[i+1])
		{
			swap(lista,n,i);
			n--;
		}
		else
		{
			i++;
		}
		
	}
	return n;
}

void swap(int lista[],int n, int i)
{
	for(;i<n-2;i++)
		lista[i+1]=lista[i+2];
		return;
}
