#include <stdio.h>

int main()
{
	int h;
	printf("\n\tTriangolo\nInserisci altezza triangolo: ");
	scanf("%d", &h);
					/*Chiamata funzione per stampa triangolo*/
	triangolo(h);
	
}

triangolo(int h)
{
	int i=1,j=0,n=1,v,p=1;
							/*Calcolo puntini in ultima riga*/
	while(i<h)
	{
		n=n+2;
		i++;
	}
	
	while(j<h)
	{
		printf("\t\t\n");
		
		
								/*Calcolo Spazi vuoti */
		v=(n-1)/2;
		n=n-2;
								/*Stampa spazi vuoti prima dei puntini*/
		i=0;
		while(i<v)
		{
			printf(" ");
			i++;
		}
											/*Stampa puntini*/
		i=0;
		while(i<p)
		{
			printf("*");
			i++;
		}
		p=p+2;
		
									/*Stampa spazi vuoti dopo puntini*/
		i=0;
		while(i<v)
		{
			printf(" ");
			i++;
		}
	j++;
	}

return;
}
