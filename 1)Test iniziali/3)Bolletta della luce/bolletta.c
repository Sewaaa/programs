#include <stdio.h>

int main()
{
	int codice_ut;
	float prec_kwh,att_kwh,canone,costoxkwh=0.0624,usati_kwh,amm_bolletta,costo_kwh_usati;
	
	printf("\nInserisci Codice Utente: ");
	scanf("%d", &codice_ut);
	
	printf("\nInserisci la quota fissa (canone): ");
	scanf("%f", &canone);
	
	printf("\nInserisci lettura precedente kwh: ");
	scanf("%f", &prec_kwh);
	
	printf("\nInserisci lettura attuale kwh: ");
	scanf("%f", &att_kwh);
	
	usati_kwh=att_kwh-prec_kwh;
	costo_kwh_usati=costoxkwh*usati_kwh;
	amm_bolletta=canone+costo_kwh_usati;
	
	printf("-----------------------------------------\n\t\t - Bolletta - \n-----------------------------------------\n\n\tkwh usati: %g\tCosto Totale: %g", usati_kwh,amm_bolletta);
}
