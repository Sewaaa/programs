/*traccia: */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define max_lung 30

typedef struct acquisto
{
	char descrizione[30];
	int quantita;
	double prezzo_unitario;
}Acquisto;

/*Prototipi*/
void leggi(char *a);
Acquisto *leggi_acquisti(FILE *f,int *n_acquisti);
void *xmalloc(size_t size);
void riempi_file(FILE *f, int  n_file);

int main()
{
	Acquisto *a;
	char fname[max_lung+1];
    int n_file;
    FILE *f;

    printf("Inserire il nome del file: ");
    leggi(fname);

    printf("\nQuanti prodotti vuoi inserire? ");
    scanf("%d", &n_file);

    
	while(getchar() != '\n'); // pulisci buffer
	
	f = fopen(fname, "w");//apertura file in scritura
    if(f == NULL) 
	{
        fprintf(stderr, "Errore nell'apertura del file: %s\n", fname);
        exit(-1);
    }
	riempi_file(f,n_file); //riempimento file

	while(getchar() != '\n'); // pulisci buffer

	f = fopen(fname, "r");//apertura file in lettura
    if(f == NULL) 
	{
        fprintf(stderr, "Errore nell'apertura del file: %s\n", fname);
        exit(-1);
    }
	a=leggi_acquisti(f,&n_file); //stampa del file

	fclose(f); 
	
	return 0;
}


void riempi_file(FILE *f, int  n_file)
{
	int i;
	Acquisto a[max_lung+1];
    
	printf("\n");

	fprintf(f,"%d\n", n_file); 
    
	for(i = 0; i < n_file; i++) 
	{
        printf("[Prodotto %d] Inserire la Descrizione: ", i + 1);
        leggi(a[i].descrizione);
       
        printf("[Prodotto %d] Inserire la Quantita' : ", i + 1);
        scanf("%d", &a[i].quantita);
        
		printf("[Prodotto %d] Inserire il Prezzo: ", i + 1);
        scanf("%lf", &a[i].prezzo_unitario);
        
		
        fprintf(f,"%s\n", a[i].descrizione);
        fprintf(f,"%d\n", a[i].quantita);
        fprintf(f,"%lf\n", a[i].prezzo_unitario);
        while(getchar()!='\n'); // pulisci buffer
    }
}

Acquisto *leggi_acquisti(FILE *f,int *n_acquisti)
{
   int i;
   Acquisto *p;
   
   printf("\n\n - Stampa Contenuto file -\n"); 
   fscanf(f,"%d",n_acquisti);
   printf("%d\n",n_acquisti); 
   
    p=(Acquisto*)xmalloc(*n_acquisti*sizeof(Acquisto));
   
	for(i=0;i<*n_acquisti;i++)
	{
		fscanf(f,"%s",p[i].descrizione); 		printf("%s\n", p[i].descrizione); 
  		fscanf(f,"%d",&p[i].quantita);			printf("%d\n", p[i].quantita); 
  		fscanf(f,"%lf",&p[i].prezzo_unitario); 	printf("%lf\n", p[i].prezzo_unitario); 
	}
  	return p;
}

void leggi(char *a)
{
	fgets(a,max_lung+1,stdin);
	if(a[strlen(a)-1]=='\n')
	{
		a[strlen(a)-1]='\0';
	}
	return;
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


