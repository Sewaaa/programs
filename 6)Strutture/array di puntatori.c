#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define max_lung 50

typedef struct{
	char *nome;
	char *cognome;
	char cf[16+1];
}persona;

void *lettura_persone(int k, persona **p);
void leggi(char p[]);
void *xmalloc(size_t size);

void main()
{
	int k,i;
	persona **p;
	printf("\nQuante persone vuoi inserire? ");
	scanf("%d", &k);
	
	p=lettura_persone(k,p);
	
	for(i=0;i<k;i++)
	{
		printf("\tPersona %d\n", i+1);
		printf("\nNome: %s\nCognome: %s\nCF: %s", p[i]->nome,p[i]->cognome,p[i]->cf);
		printf("\n\n");
	}
}



void *lettura_persone(int k, persona **p)
{
	char nome[max_lung+1];
	char cognome[max_lung+1];
	int i;
	
	p=(persona**)xmalloc(k*sizeof(persona*));
	
	while(getchar()!='\n'); 
	
	for(i=0;i<k;i++)
	{
		p[i]=(persona*)xmalloc(sizeof(persona));
		
		printf("[Persona %d] Inserisci Nome: ", i+1);
		leggi(nome);
		p[i]->nome = xmalloc(strlen(nome)+1);
   		strcpy(p[i]->nome, nome);
   		
		printf("[Persona %d] Inserisci Cognome: ", i+1);
		leggi(cognome);
		p[i]->cognome = xmalloc(strlen(cognome)+1);
   		strcpy(p[i]->cognome, cognome);
   		
		printf("[Persona %d] Inserisci Cf: ", i+1);
		leggi(p[i]->cf);
		
		printf("\n");
	}
	return p;
}


								/*Lettura Stringa*/
void leggi(char p[])
{
	fgets(p,max_lung+1,stdin);
	if(p[strlen(p)-1]=='\n')
	{
		p[strlen(p)-1]='\0';
	}
	
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


