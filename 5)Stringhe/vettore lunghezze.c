/*Abbiamo un vettore di n stringhe e vogliamo calcolare la lunghezza di ciascuna stringa e memorizzarla in un vettore di interi*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_lung 30

void map_lenght(char stringhe[][max_lung+1],int n, int lunghezze[]);
void leggistringa(char a[][max_lung+1],int i);

int main()
{
	int n,i,j;
	
	printf("\nQuante stringhe vuoi inserire? ");
	scanf("%d",&n);
	
	int lunghezze[n];
	char a[n][max_lung+1];
	
	leggistringa(a,i); //la chiami per la prima volta a vuoto, perchè la prima volta non legge (non so pk)
		
	for(i=0;i<n;i++)
	{
		printf("\nInserisci stringa %d: ", i+1);
		leggistringa(a,i);	
		 map_lenght(a,n,lunghezze);
	}
	
		/*Stampa stringhe*/
	 printf("\n");
	 for(i=0;i<n;i++)
	 {
	 	printf("Stringa %d: ", i+1);
	 	for(j=0;j<strlen(a[i]);j++)
	 	{
	 		printf("%c",a[i][j]);	
		}
	 	printf("\n");
	 }
	 
	 	/*Stampa lunghezze stringhe*/
	 for(i=0;i<n;i++)
	 {
	 	printf("\nLunghezza Stringa %d: %d", i+1,lunghezze[i]);
	 }
	
	
}

void leggistringa(char a[][max_lung+1], int i)
{
	fgets(a[i],max_lung+1,stdin);
	if(a[i][strlen(a[i])-1]=='\n')
	{
		a[i][strlen(a[i])-1]='\0';
	}
	return;
}


void map_lenght(char stringhe[][max_lung+1],int n, int lunghezze[])
{
	int i;
	for(i=0;i<n;i++)
	{
		lunghezze[i]=strlen(stringhe[i]);
	}
}
