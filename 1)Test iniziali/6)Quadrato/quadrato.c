#include <stdio.h>

int main()
{
	int n;
	printf("\n\tQuadrato\nInserisci lato del quadrato: ");
	scanf("%d", &n);
					/*Chiamata funzione per stampa quadrato*/
	quadrato(n);
	
}

quadrato(int n)
{
	int i=1;
	while(i<=n)
	{
		printf("\n\t");
		int j=1;
		while(j<=n)
		{
			printf("*");
			j++;
		}
	i++;
	}
	return;
}
