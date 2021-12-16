
#include <stdio.h>
#include <stdlib.h>


int main()
{

FILE *f;
char nome[]="ciao";
float num;
int i=0;
	
	f=fopen(nome,"w+b"); //crea file
	
	fseek(f,0,SEEK_END);//setta testina alla fine
		                           /*Prende in input numeri da inserire*/
		for(i=0;i<2;i++)
		{
			printf("\nInserisci numero: ");
		  	scanf("%f",&num);
		  	fwrite(&num ,sizeof(float),1,f);
		}
	fseek(f,0,SEEK_SET);//setta testina all'inizio dopo che hai finito le operazioni
	
		/*Stampa*/
	  fseek(f,0,SEEK_SET); //setta testina all'inizio
	  printf("\n -STAMPA- \n");                
	  for(i=0;i<2;i++)
	  {
	  	fread(&num,sizeof(float),1,f);
	    printf("%.2f \n", num);
	  }
}
