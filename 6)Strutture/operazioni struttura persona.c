#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define max_lung 50

typedef struct{
	char *nome;
	char *cognome;
}persona;
							/*Prototipi*/
void *xmalloc(size_t size);
void *inserisci_dati(persona **p,int k);
void leggi(char *p);
void stampa(persona **p,int k);
void cerca_iniziale_nome(persona **p,int k);
void cerca_nome(persona **p,int k);
void cerca_persona(persona **p,int k);
											/*MAIN*/
int main()
{
	persona **p;
	int k,op;

	printf("Quante persone vuoi inserire? ");
	scanf("%d", &k);
	p=inserisci_dati(p,k);

	do{
		printf("\n\n\t\t Menu \n\n1)Stampa Elenco\n2)Cerca per Nome\n3)Cerca per Iniziale del Nome\n4)Cerca per Nome e Cognome\n5)Termina\n\nScegli:");
		scanf("%d", &op);
	
		switch (op)
		{
			case 1:
				stampa(p,k);
				break;
			case 2:
				while(getchar()!='\n'); 
				cerca_nome(p,k);
				break;
			case 3:
				while(getchar()!='\n'); 
				cerca_iniziale_nome(p,k);
				break;
			case 4:
				while(getchar()!='\n'); 
				cerca_persona(p,k);
				break;
			case 5:
				return 0;
				break;
			default:
				printf("\n\t- Numero non valido -\n");
				break;
			
		}	
	}while(1);
}

void cerca_persona(persona **p,int k)
{
	char nome[max_lung+1],cognome[max_lung+1];
	int i,result=0;
	
	printf("\nPersona da cercare - Inserisci nome : ");
	leggi(nome);
	printf("\nPersona da cercare - Inserisci cognome: ");
	leggi(cognome);
	
	for(i=0;i<k;i++)
	{
		if((strcmp(p[i]->nome,nome))==0 && (strcmp(p[i]->cognome,cognome))==0 )
		{
			//persona trovata
			result=1;
			break;
		}
	}
	if(result==1)
	{
		printf("\n\t - Persona trovata -\n");
		printf("\n[Persona %d] Nome: %s Cognome: %s \n", i+1,p[i]->nome,p[i]->cognome);
	}
	else
	{
			printf("\n\t - Persona NON trovata -\n");
	}
}

void cerca_nome(persona **p,int k)
{
	int i;
	char nome[max_lung+1];
	printf("\nInserisci nome da cercare: ");
	leggi(nome);
	printf("\n\t Persone Trovate: ");
	for(i=0;i<k;i++)
	{
		if((strcmp(p[i]->nome,nome))==0)
		{
			printf("\n[Persona %d] %s %s \n", i+1,p[i]->nome,p[i]->cognome);
		}
	}
}


void cerca_iniziale_nome(persona **p,int k)
{
	int i;
	char lettera[max_lung+1],iniziale;
	printf("\nInserisci iniziale del nome da cercare: ");
	scanf("%c", &iniziale);
	printf("\n\t Persone Trovate: ");
	for(i=0;i<k;i++)
	{
		strcpy(lettera,p[i]->nome);
		if(lettera[0]==iniziale)
		{
				printf("\n[Persona %d] %s %s \n", i+1,p[i]->nome,p[i]->cognome);
		}
	}
}

void stampa(persona **p,int k)
{
	int i;
	printf("\n- STAMPA -\n", i);
	for(i=0;i<k;i++)
	{
		printf("\n[Persona %d]", i+1);
		printf("\nNome: %s\nCognome: %s\n", p[i]->nome,p[i]->cognome);
	}
}

void *inserisci_dati(persona **p,int k)
{
	int i;
	char nome[max_lung+1], cognome[max_lung+1];
			
	p=(persona**)xmalloc(k*sizeof(persona*));
	while(getchar() != '\n'); // pulisci buffer
	for(i=0;i<k;i++)
	{
		p[i]=(persona*)xmalloc(sizeof(persona)); 	
		
		printf("\n[Persona %d]\n", i+1);
	    									/*Prelievo e allocamento Nome*/
		printf("Inserire Nome: ");
	    leggi(nome);
	    p[i]->nome = xmalloc(strlen(nome)+1);
	    strcpy(p[i]->nome, nome);
	    
	    									/*Prelievo e allocamento Cognome*/
	    printf("Inserire Cognome: ");
	 	leggi(cognome);
	 	p[i]->cognome = xmalloc(strlen(cognome)+1);
	    strcpy(p[i]->cognome, cognome);
	}
	return p;
}

void *xmalloc(size_t size) 
{
    void *p;

    p = malloc(size);

    if(p == NULL) {
        fprintf(stderr, "Errore\n");
        exit(-1);
    }

    return p;
}
								/*Lettura Stringa*/
void leggi(char *p)
{
	fgets(p,max_lung+1,stdin);
	if(p[strlen(p)-1]=='\n')
	{
		p[strlen(p)-1]='\0';
	}
	
}
