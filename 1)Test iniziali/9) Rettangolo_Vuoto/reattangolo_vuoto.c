#include <stdio.h>

int main()
{
	int h,b;
	printf("\n\tRettangolo Vuoto\nInserisci altezza del rettangolo: ");
	scanf("%d", &h);
	printf("\nInserisci larghezza del rettangolo: ");
	scanf("%d", &b);
					/*Chiamata funzione per stampa rettangolo vuoto*/
	rettangolo(h,b);
	
}

rettangolo(int h, int b)
{
	int i=1,j=1;
	if(b==0||h==0)
	{
	}
	else
	{
		while(i<=h)
		{
			printf("\n\t");
			if(i==1||i==h)
			{
				j=1;
				while(j<=b)
				{
					printf("*");
					j++;
				}
			}
			else
			{
				if(b==1)
				{
				 	printf("*");
				}
				else
				{
					j=1;
					printf("*");
					j++;
					while(j!=1&&j!=b)
					{
						printf(" ");
						j++;
					}
					printf("*");
				}
			}
		i++;
		}
	}
	return;
}
