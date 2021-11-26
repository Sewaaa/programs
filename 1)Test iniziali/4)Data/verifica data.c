#include <stdio.h>
#include "lib/date.h"

int main()
{
	int aaaa,mm,gg,i;
	
	do{
	printf("\n - Inserisci l'anno: ");
	scanf("%d", &aaaa);
	printf("\n - Inserisci il mese: ");
	scanf("%d", &mm);
	printf("\n - Inserisci il giorno: ");
	scanf("%d", &gg);
	
	date(aaaa,mm,gg);
	do{
		printf("\n Vuoi inserirne un'altro?\n1)si\n2)no\n\n- ");
		scanf("%d", &i);
	}while((i!=1) && (i!=2));
	}while(i!=2);
}
