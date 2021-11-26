#include <stdio.h>
#define MAXLIST  50

/* prototipi di funzioni */

int leggiLista(int lista[ ], int max);
void ordina(int lista[ ], int n);
void swap(int lista[ ], int i, int j);
int scorri(int lista[ ], int n);
void stampaLista(int lista[ ], int n);
void  ricercaord(int a[], int n);

int main(void)
{
      int n, lista[MAXLIST];
      n = leggiLista(lista, MAXLIST);
      ordina(lista, n);
      stampaLista(lista, n);
      ricercaord(lista,n);
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
     printf("Immettere una sequenza di valori,\n 0 per terminare");
     while (n<max)
     {
           printf("\nInserisci il prossimo valore: ");
           scanf("%d", &val);
           if (val == 0)  break;
           lista[n] = val;
           n++;
      }
     return n;
}

/*
 * Function: ordina
 * Usage: ordina(lista, n)
 * ---------------------------------------
 * richiama scorri(lista, n) in un ciclo
 * finché ci sono elementi da scambiare
*/

void  ordina(int lista[ ], int n)
{
      while (scorri(lista,n));
}

/*
 * scorre la lista chiamando swap(lista,i,i+1)
 * per scambiare elementi consecutivi. 
 * Restituisce 1 se è fatto almeno uno
 *  scambio, 0 altrimenti
 */

int scorri(int lista[ ], int n)
{
     int i, scambi=0;
     for (i=0; i<n-1; i++)
     {
            if (lista[i] > lista[i+1])
            {
                    swap(lista, i, i+1);
                    scambi =1;
             }
      }
     return scambi;
}

/*
 * Function: swap
 * Usage: swap(lista, i, i+1)
 * ---------------------------------------
 * scambia i valori di indice i e i+1 
 * in lista 
*/

void swap(int lista[ ], int i, int j)
{
     int temp;
     temp = lista[i];
     lista[i] = lista[j];
     lista[j] = temp;
}

/*
 * Function: stampaLista
 * Usage: stampaLista(lista, n)
 * ---------------------------------------
 * stampa la lista dopo l’ordinamento
*/

void stampaLista(int lista[ ], int n)
{
     int i;
     for (i=0; i<n; i++)
     {
           printf(" %d", lista[i]);
      }
}

void  ricercaord(int a[], int n) 
{
    int i = 0,elem;               
    printf("\nInserisci elemento da ricercare:  ");
    scanf("%d",&elem);
   while(i < n  &&  a[i] < elem)   /* visita finalizzata */
 	      i++;             
    if(i == n || a[i] > elem) 
		i = -1;
		
		if(i==-1)
		  printf("Elemento non trovato");
		  else printf("Elemento trovato in posizione [%d]", i);        
    return;   
}


