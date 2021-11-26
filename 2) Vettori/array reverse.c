#include <stdio.h>
#define NUMEL  10
int  main (void)
{
      int lista [NUMEL];
      GetLista(lista);			//chiamata funzione per prende valori input
      Reverse(lista);		    //chiamata funzione reverse per ribaltare valori nel vettore
      printf("\nLa lista inversa e': ");
      PrintLista(lista); 		//chiamta funzione per stampa elementi vettore
      return 0;
}

GetLista(int lista[ ])
{
      int i;
      for (i=0; i<NUMEL; i++)
      {
      		printf("Insrisci Vettore [%d]: ",i);
           	scanf("%d", &lista[i]);
      }
}

Reverse(int lista[ ])
{
      int i, temp;
      for (i=0; i<NUMEL/2; i++)
      {
            temp = lista[i];
            lista[i] = lista[NUMEL-1- i];
            lista[NUMEL-1- i] = temp;
      }
}

PrintLista(int lista[ ])
{
      int i;
      for (i=0; i<NUMEL; i++)
           printf(" %d", lista[i]);
}







