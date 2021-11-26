#include <stdio.h>
#define MAXLIST  50

/* prototipi di funzioni */

int leggiLista(int lista[ ], int max);
void stampaLista(int lista[ ], int n);
int inserisci(int lista[ ], int n);
int elimina(int a[], int n);
int main(void)
{
      int n, lista[MAXLIST];
      n = leggiLista(lista, MAXLIST);
      stampaLista(lista,n);
	  n= inserisci(lista,n);
	  stampaLista(lista,n);
	  n= elimina(lista,n);
	  stampaLista(lista,n);
      return 0;
}

/*
 *  legge una lista di interi terminata dal 
 *  valore 0, la inserisce in un array, e
 *  restituisce il numero di elementi letti
*/

int leggiLista(int lista[ ], int max)
{
     int n=0, val;
     printf("\nImmettere una sequenza di valori, 0 per terminare");
     while (n<max)
     {
           printf("\nInserisci il [%d] valore: ", n);
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
}
// precondizione: 0 <= pos <= n

int inserisci(int lista[ ], int n) 
{
    int i,el,pos;  
    printf("\nNumero da inserire nel vettore:  ");
    scanf("%d",&el);
    printf("\nIn che posizione vuoi inserirlo? ");
    scanf("%d",&pos);
    if (pos<0 || pos>n) 
            return n;
    for (i = n; i > pos; i--)      
 	        lista[i] = lista[i-1];    // shift a destra
     lista[pos] = el;
     return n+1;  
}

// precondizione: 0 <= pos < *n

int elimina(int a[], int n) 
{
	int pos;
        printf("\nInserisci la posizione dell'elemento da eliminare:  ");
    	scanf("%d",&pos);
		 int i;  
         if (pos<0 || pos>=n)
               return n;
         for (i = pos; i < n-1; i++)      
 	             a[i] = a[i+1];    // shift a sinistra
         return n-1;  
}

