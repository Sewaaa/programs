/*traccia: */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define max_lung 30

/*Prototipi*/
void leggi(char *a);
void *xmalloc(size_t size);
void riempi_stringhe(char *a[], int sizea);
int primadi(char *fname, char *spartiacque, char *a[], int sizea);
void leggi_file(char *fname);

int main()
{
	char fname[max_lung+1];
    char spartiacque[max_lung+1];
    int sizea,i,count;

    printf("Inserire il nome del file: ");
    leggi(fname);

    printf("Inserire stringa spartiacque: ");
    leggi(spartiacque);

    printf("\nQuante stringhe vuoi inserire? ");
    scanf("%d", &sizea);

    char *a[sizea];
    
	while(getchar() != '\n'); // pulisci buffer
	
	riempi_stringhe(a, sizea); //lettura stringhe
	 
	count=primadi (fname,spartiacque,a,sizea); //memorizzazione stringhe prima dello spartiacque
	printf("\nStringhe Salvate: %d", count); //stampa stringhe salvate nel file

	leggi_file(fname); //stampa del file
	
	return 0;
}

int primadi(char *fname, char *spartiacque, char *a[], int sizea)
{
	FILE *fp;
    int i, count = 0;

    fp = fopen(fname, "w");

    if(fp == NULL) 
	{
        fprintf(stderr,"Errore nell'apertura del file: %s\n", fname);
        exit(-1);
    }

    for(i = 0; i < sizea; i++) {
        if((strcmp(a[i], spartiacque)) < 0)  // 0 se sono uguali | 1 se è maggiore | -1 se è minore 
		{
            fprintf(fp,"%s\n", a[i]);
            count++;
        }
    }

    fprintf(fp,"END\n");
    fclose(fp);

    return count;
}

void leggi_file(char *fname)
{
   FILE *f;
   char stringa[max_lung+1];
   f=fopen(fname, "r"); 
   printf("\n\n - Stampa Contenuto file -\n"); 
   while (fscanf(f,"%s",stringa)>0) 
   {
     printf("%s\n", stringa); 
   }
   fclose(f); 
}

void riempi_stringhe(char *a[], int sizea)
{
	int i, lun;
    char tmp[max_lung+1];

    printf("\n");

    for(i = 0; i < sizea; i++) 
	{
        printf("Inserire la stringa %d: ", i + 1);
        leggi(tmp);
        lun = strlen(tmp);
        a[i] = xmalloc(lun+1);
        strcpy(a[i], tmp);
    }
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


