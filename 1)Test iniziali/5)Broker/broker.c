#include <stdio.h>

int main()
{
	int transazione,commissione;
	
	printf("\n\t- Broker - \nImmettere l'ammontare della transazione: ");
	scanf("%d", &transazione);
					/*Calcolo commissione*/
	commissione = calcolo_commissione (transazione);
	
	printf("\n Ammontare selezionato: $%d \t Commissione: $%d \n",  transazione,commissione);
}

int calcolo_commissione(int transazione)
{
 	int commissione;
 	if(transazione<2500)
 	{
 		commissione=30+(transazione*1.7)/100;
	}
	if(transazione>=2500 && transazione<6250)
	{
		commissione=56+(transazione*0.66)/100; 
	}
	if(transazione>=6250 && transazione<20000)
	{
		commissione=76+(transazione*0.34)/100; 
	}
	if(transazione>=20000 && transazione<50000)
	{
		commissione=100+(transazione*0.22)/100; 
	}
	if(transazione>=50000 && transazione<500000)
	{
		commissione=155+(transazione*0.11)/100;
	}
	if(transazione>500000)
	{
		commissione=255+(transazione*0.09)/100;
	}
	
	if(commissione<39)
	{
		commissione=39;
	}
return commissione;
}
