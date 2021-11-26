/*
 * File: bubbles.c
 * ---------------------------------------
 * Legge una lista di interi terminata 
 * dal valore 0, la inserisce in un array
 * ne fa l’ordinamento con bubblesort
 * e infine stampa la sequenza ordinata
 */

#include <stdio.h>
#define MAXLIST  50

/* prototipi di funzioni */

int leggiLista(double lista[ ], int max);
void ordina(double lista[ ], int n);
void swap(double lista[ ], int i, int j);
int scorri(double lista[ ], int n);
void stampaLista(double lista[ ], int n);

int main(void)
{
      int n;
	  double lista[MAXLIST];
      n = leggiLista(lista, MAXLIST);
      ordina(lista, n);
      stampaLista(lista, n);
      return 0;
}

/*
 *  legge una lista di interi terminata dal 
 *  valore 0, la inserisce in un array, e
 *  restituisce il numero di elementi letti
*/

int leggiLista(double lista[ ], int max)
{
     int n=0;
	 double val;
     printf("Immettere una sequenza di valori, 0 per terminare\n");
     while (n<max)
     {
           printf("Inserisci il prossimo valore: ");
           scanf("%lf", &val);
           if (val == 0.0)  break;
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

void  ordina(double lista[ ], int n)
{
      while (scorri(lista,n));
}

/*
 * scorre la lista chiamando swap(lista,i,i+1)
 * per scambiare elementi consecutivi. 
 * Restituisce 1 se è fatto almeno uno
 *  scambio, 0 altrimenti
 */

int scorri(double lista[ ], int n)
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

void swap(double lista[ ], int i, int j)
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

void stampaLista(double lista[ ], int n)
{
     int i;
     for (i=0; i<n; i++)
     {
           printf(" %.2lf", lista[i]);
      }
}

