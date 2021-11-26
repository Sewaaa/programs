#include <stdio.h>
#define MAXLIST  50

/* prototipi di funzioni */

int leggiLista(int lista[ ], int max);
void ordina(int lista[ ], int n);
void swap(int lista[ ], int i, int j);
int scorri(int lista[ ], int n);
void stampaLista(int lista[ ], int n);
void  ricercabin(int a[], int n);

int main(void)
{
      int n, lista[MAXLIST];
      n = leggiLista(lista, MAXLIST);
      ordina(lista, n);
      stampaLista(lista, n);
      ricercabin(lista,n);
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

void  ricercabin(int a[], int n) 
{  int h, k, p,elem;               
    printf("\nInserisci elemento da ricercare:  ");
    scanf("%d",&elem);
    int trovato = 0;     
    
    h = 0; k = n-1;                 // estremi dell’intervallo in cui ricercare           
    while(h <= k && ! trovato) 
    {
          p = (h + k) / 2;          // posizione centrale
 	      if (a[p] == elem)
                    trovato = 1;     // permette di uscire dal ciclo 
          else if(a[p] > elem)
                     k = p-1;           // la ricerca continua nella prima metà  
          else h = p+1; 
    }          // la ricerca continua nella seconda metà              
    if(!trovato)
            printf("ELemento non trovato");
			else printf("Elemento trovato in posizione [%d]", p);          
    return;   
}



