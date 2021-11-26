#include <stdio.h>
#include <unistd.h>

int main(){
	int op=0,somma,n1,n2;
	
	printf("-Menu-\n\n0)Esci\n1)Somma tra 2 numeri\n----------------\n");
	scanf("%d", &op);
	switch(op)
	{
									/* Caso 0 termina programma*/
		case 0:
		break;
									/*Caso 1 Somma tra 2 numeri*/
		case 1:
			printf("\nInserire primo numero:  ");
			scanf("%d", &n1);
			printf("\nInserire secondo numero:  ");
			scanf("%d", &n2);
			somma=n1+n2;
			printf("\n %d + %d = %d \n",n1,n2,somma);
		break;
	}
	
}