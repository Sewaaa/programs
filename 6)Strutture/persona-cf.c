#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define max_lung 50
							/*Struttura Persona*/
typedef struct{
	char *nome;
	char *cognome;
	char cf[16+1];
}persona;
							/*Prototipi*/
void *allocamento(size_t size);
persona *inserisci_dati(persona *p);
void leggistringa(char p[]);
int controllo_cf(char cf[]);
								/*MAIN*/
int main()
{
	persona *p;

	p=inserisci_dati(p);
	
	printf("\nNome: %s\nCognome: %s\nCF: %s", p->nome,p->cognome,p->cf);
}

persona *inserisci_dati(persona *p)
{
	int result;
	char nome[max_lung+1], cognome[max_lung+1];
	
	p=allocamento(sizeof(p));  			//allocamento puntatore al record
    									/*Prelievo e allocamento Nome*/
	printf("Inserire Nome: ");
    leggistringa(nome);
    p->nome = allocamento(strlen(nome)+1);
    strcpy(p->nome, nome);
    									/*Prelievo e allocamento Cognome*/
    printf("Inserire Cognome: ");
 	leggistringa(cognome);
 	p->cognome = allocamento(strlen(cognome)+1);
    strcpy(p->cognome, cognome);
    										/*Prelievo Codice Fiscale*/
	printf("Inserire Codice Fiscale: ");
    leggistringa(p->cf);
    										/*Controllo Codice fiscale*/
	result=controllo_cf(p->cf);
	if(result==1){ printf("\n - Codice Fiscale Valido -"); }
	else { printf("\n - Codice Fiscale NON Valido -"); }
	
	return p;
}
						/*Allocamento record tipo Persona*/
void *allocamento(size_t size) 
{
	void *p;
	p=malloc(sizeof(size));   
    
	if(!p) return NULL;
	 
	return p;
}
								/*Lettura Stringa*/
void leggistringa(char p[])
{
	fgets(p,max_lung+1,stdin);
	if(p[strlen(p)-1]=='\n')
	{
		p[strlen(p)-1]='\0';
	}
	
}

					/*Controllo Codice fiscale*/
int controllo_cf(char cf[])
{
	int result=0;
	
	if ( isalpha(cf[0]) && isalpha(cf[1]) && isalpha(cf[2]) && isalpha(cf[3]) && isalpha(cf[4]) && isalpha(cf[5]) && isalpha(cf[8]) && isalpha(cf[11]) && isalpha(cf[15]) )
	{
			if ( isdigit(cf[6]) && isdigit(cf[7]) && isdigit(cf[9]) && isdigit(cf[10]) && isdigit(cf[12]) && isdigit(cf[13]) && isdigit(cf[14]) )
			{
				result=1;
			}
	}
	
	return result;
}








