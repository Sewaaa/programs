/*Scrivere una funzione che riceva come parametri un vettore di stringhe,
il numero dei suoi elementi, e restituisca una stringa allocata dinamicamente,
formata dalle lettere iniziali delle stringhe non vuote e non nulle di V*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_lung 30

void leggistringa(char a[][max_lung+1],int i);
char *salva_iniziali(char a[][max_lung+1],int n);
void stampa_vettorestringa(char  a[][max_lung+1],int n);

int main()
{
	
int n,i;
char *p;
	
	printf("\nQuante stringhe vuoi inserire? ");
	scanf("%d",&n);
	
	int lunghezze[n];
	char a[n][max_lung+1];
	
	while(getchar() != '\n'); // pulisci buffer	
	
	for(i=0;i<n;i++)
	{
		printf("\nInserisci stringa %d: ", i+1);
		leggistringa(a,i);	
	}
	
	stampa_vettorestringa(a,n); //stampa vettore di stringhe
    p=salva_iniziali(a,n);
								/*Stampa vettore con iniziali delle stringhe*/
	for(i=0;i<n;i++)
	 	{
	 		printf("Iniziale stringa %d : %c\n", i+1,p[i]);	
		}
	free(p);
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

char *salva_iniziali(char a[][max_lung+1],int n)
{
	int i;
	char *s;
	s=(char*)malloc(n); 
	
	if(!s)return NULL; //se s ha ricevuto un valore non valido 
	
	for(i=0;i<n;i++)
	{
		s[i]=a[i][0];
	}
	return s;
	
}
 void stampa_vettorestringa(char a[][max_lung+1],int n)
 {
 	int i,j;
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
 }
