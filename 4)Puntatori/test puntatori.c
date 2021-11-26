#include <stdio.h>
void azzera1 (int n);
void azzera2 (int *n);
int main()
{
	int i, *p;
	
	p=&i; //salva in p l'indirizo di i
	
	printf("\nInserisci i: ");
	scanf("%d", p); 	//per prendere i in input salvandola tramite il puntatore che contiene il suo indiritto non serve &
	
	printf("1) %d", *p); //stampa oggetto contenuto nell'indirizzo salvato in p
	
	p=NULL;				//svuota il puntatore
	
	
	
//----------------------------------------------------------                                                 
	i=5;
	azzera1(i);
	printf("\n(Azzera1) Valore di i : %d\n", i);
	
	i=5;
	azzera2(&i);
	printf("\n(Azzera2) Valore di i : %d\n", i);
}

void azzera1 (int n)
{
     n = 0;
     //per far tornare la i modificata devi perforza fare un return i, sennò le modifiche non verranno apportate;
}

void azzera2 (int *n)
{
     *n = 0;
     //anche senza return la i è stata modificata
}

