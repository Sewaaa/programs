#include <stdio.h>

int main()
{
	int n;
	printf("\n\tQuadrato Vuoto\nInserisci lato del quadrato: ");
	scanf("%d", &n);
					/*Chiamata funzione per stampa quadrato vuoto*/
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
			if(i==1||i==n)
			{
				printf("*");
			}
			else
			{
				if(j!=1&&j!=n)
				{
					printf(" ");
				}
				else
				{
					printf("*");
				}
			}
			j++;
		}
	i++;
	}
	return;
}
