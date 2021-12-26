#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define max_lung 50

typedef struct
{
	char *nome;
	char *cognome;
	char *citta;
	int  eta;
}persona;

void *lettura_persone(persona **p,int *k);
void leggi(char *s);
void *xmalloc(size_t size);

int *eta_media(persona **p,int k);


char *citta_max(persona **p, int k);
/*
void *ricerca_per_citta();
*/
int main()
{
	int k, *eta_m;
	persona **p;
	char *citta;
	
	p=lettura_persone(p,&k);
	eta_m=eta_media(p,k);
	printf("\n\nEta' media: %d", eta_m);
	citta=citta_max(p,k);
	printf("Citta max: %s", citta);
}

char *citta_max(persona **p,int k)
{
	int i=0,j=0,count=0,count_max=0;
	char *maxx, max[max_lung+1];
	
	strcpy (max,p[j]->citta);
	for(j=0;j<k;j++)
	{
		for(i=0;i<k;i++)
		{
			if( ( strcmp(p[j]->citta,p[i]->citta) ) == 0)
			{
				count++;
			}
		}
		if(count>count_max)
		{
				printf("\nhey");
			count_max=count;
			strcpy(max,p[j]->citta);
		}
	}
	printf("max interno: %s", max);
	maxx=max;
	return maxx;
}

int *eta_media(persona **p,int k)
{
	int i, media=0;
	int *m;
	
	for(i=0;i<k;i++)
	{
		media=media+p[i]->eta;	
	}	
	media=(media/k);
	m=media;
	return m;
}

void *lettura_persone(persona **p,int *k)
{
	char nome[max_lung+1];
	char cognome[max_lung+1];
	char citta[max_lung+1];
	int i;
	
	printf("\nQuante persone vuoi inserire? ");
	scanf("%d", k);
	
	p=(persona**)xmalloc(*k*sizeof(persona*));
	
	for(i=0;i<*k;i++)
	{
		p[i]=(persona*)xmalloc(sizeof(persona));
			while(getchar()!='\n'); 
		printf("\n\n[Persona %d] Inserisci nome: ", i+1);
		leggi(nome);
		p[i]->nome=xmalloc(strlen(nome)+1);
		strcpy(p[i]->nome,nome);
		
		printf("\n[Persona %d] Inserisci cognome: ", i+1);
		leggi(nome);
		p[i]->nome=xmalloc(strlen(nome)+1);
		strcpy(p[i]->nome,nome);
		
		printf("\n[Persona %d] Inserisci citta': ", i+1);
		leggi(nome);
		p[i]->nome=xmalloc(strlen(nome)+1);
		strcpy(p[i]->nome,nome);
		
		printf("\n[Persona %d] Inserisci eta: ", i+1);
		scanf("%d", &p[i]->eta);
	}
	return p;
}


void leggi(char *s)
{
	fgets(s,max_lung+1,stdin);
	if(s[strlen(s)-1]=='\n')
	{
		s[strlen(s)-1]='\0';
	}
}

void *xmalloc(size_t size)
{
	void *p;
	p=malloc(size);
	if(p==NULL)
	{
		fprintf(stderr,"Errore");
		exit(-1);
	}
	return p;
}


