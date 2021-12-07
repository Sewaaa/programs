/*Scrivere un programma che gestisca un elenco di coppie nome e cognome
Deve leggere l'elenco inserendole in un array bidimensionale di stringhe allocate dinamicamente
Dato un certo nome, stampare un elenco di cognomi dipersone aventi quel dato nome*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLUN 40
#define NUMSTR 3

void leggi(char a[]);
char *leggistringa(int maxlun);
void stampa_associati(char *el[][2], char nome[]);

int main()
{
	char *el[NUMSTR][2];
	char nome[MAXLUN+1];
	int i;
											/*Prende in Input*/
	for(i=0;i<NUMSTR;i++)
	{
		printf("Inserisci Nome %d: ",i+1);
		el[i][0]=leggistringa(MAXLUN+1);
		printf("Inserisci Cognome %d: ",i+1);
		el[i][1]=leggistringa(MAXLUN+1);	
		printf("\n");	
	}
	/*---------stampa-------*/
	int j;   
    for (i = 0; i < NUMSTR; i++) {
       for(j = 0; j < 2; j++)
	       printf(" %s ", el[i][j]);
      printf("\n");  }
    /*-------------------*/
											/*Ricerca per nome*/
	printf("\nInserisci Nome da cercare: ");
	leggi(nome);
	printf("\nCognomi corrispondenti:\n");
	stampa_associati(el,nome);
}

void stampa_associati(char *el[][2], char nome[])
{
	int i;
	for(i=0;i<NUMSTR;i++)
	{
		if(!strcmp(el[i][0],nome))
		{
			printf(" %s\n", el[i][1]);
		}
	}
}


									/*Adatta la stringa alla lunghezza della stringa inserita*/
char *leggistringa(int maxlun)
{
	char *s,*s1;
	int lun;
	
	s=(char*)malloc(maxlun+1); 
	
	if(!s)return NULL; //se s ha ricevuto un valore non valido 
	
	leggi(s);
	
	lun=strlen(s);
	
	s1=malloc(lun+1);
	
	if(!s1)return NULL;
	
	strncpy(s1,s,lun);
	
	free(s);
	
	return s1; 
}
								/*Legge stringa*/
void leggi(char a[])
{
	fgets(a,MAXLUN+1,stdin);
	if(a[strlen(a)-1]=='\n')
	{
		a[strlen(a)-1]='\0';
	}
	return;
}




