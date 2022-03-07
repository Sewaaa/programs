#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char nome[20]; 
	float prezzo;
	int giorno;
	int mese;
	int anno;
}vendita;
						/*Prototipi*/
void vendi_prodotto(char fname[]);
void string_date_to_numbers(char data[], int *giorno, int *mese, int *anno);
void stampa_totale(char fname[]);
void stampa_per_data(char fname[]);
void stampa_per_prodotto(char fname[]);

				/*MAIN*/
int main()
{
	int op;
	char fname[]="scontrino.txt";
	
	do{
		printf("\t\t-MENU-\n\n");
		printf("\t0.Esci\n\t1. Vendi prodotto\n\t2. Stampa scontrino giornaliero\n\t3. Stampa scontrino totale\n\t4. Stampa scontrino per prodotto\n\n>");
		scanf("%d", &op);
		switch(op)
		{
					/*vendi prodotto*/
			case 1:
				vendi_prodotto(fname);
			break;
					/*stampa incasso giornaliero*/
			case 2:
				stampa_per_data(fname);
			break;
					/*Stampa incasso totale*/
			case 3:
				stampa_totale(fname);
			break;
					/*Stampa per prodotto*/
			case 4:
				stampa_per_prodotto(fname);
			break;
			
			case 0:
				exit(1);
			break;
			
		}
	}while(1);
	
}
					/*Vendita prodotto Inserimento in file*/
void vendi_prodotto(char fname[])
{
	FILE *fp;
	vendita v;
	char data[10+1];
	
	fp=fopen(fname,"a");
	printf("Nome Prodotto> ");
	scanf("%s", &v.nome);
	printf("Prezzo> ");
	scanf("%f", &v.prezzo);
	printf("Data (gg/mm/aaaa)> ");
	scanf("%s", &data);
	
	string_date_to_numbers(data,&v.giorno,&v.mese,&v.anno);
	
	if(v.giorno<10 && v.mese<10)
	{
		fprintf(fp,"0%d/0%d/%d %s %.2f\n", v.giorno,v.mese,v.anno,v.nome,v.prezzo);
	}
	else
	{
		if(v.giorno<10)
		{
			fprintf(fp,"0%d/%d/%d %s %.2f\n", v.giorno,v.mese,v.anno,v.nome,v.prezzo);
		}
		else
		{
			if(v.mese<10)
			{
				fprintf(fp,"%d/0%d/%d %s %.2f\n", v.giorno,v.mese,v.anno,v.nome,v.prezzo);
			}
			else
			{
				fprintf(fp,"%d/%d/%d %s %.2f\n", v.giorno,v.mese,v.anno,v.nome,v.prezzo);
			}
		}
		
	}
	
	
	fclose(fp);	
	return;
}
							/*COnversione data a intero*/
void string_date_to_numbers(char data[], int *g, int *m, int *a)
{
	char giorno[2+1];
	char mese[2+1];
	char anno[4+1];
	char c;
	
	c=data[0];
	giorno[0]=c;
	c=data[1];
	giorno[1]=c;
	*g=atoi(giorno);

	c=data[3];
	mese[0]=c;
	c=data[4];
	mese[1]=c;
	*m=atoi(mese);
	
	c=data[6];
	anno[0]=c;
	c=data[7];
	anno[1]=c;
	c=data[8];
	anno[2]=c;
	c=data[9];
	anno[3]=c;
	*a=atoi(anno);

	return;
}
				/*stampa file totale*/
void stampa_totale(char fname[])
{
	FILE *fp;
	char str[50];
	fp=fopen(fname,"r");
	char *result;
	
	printf("\t\t-STAMPA-\n");
	while(1)
	{
		result=fgets(str,50,fp);
		if(result==NULL)
		{
			break;
		}
		printf("\n\t%s",str);
	}
	printf("\n\n");
	fclose(fp);
	return;
}

void stampa_per_data(char fname[])
{
	FILE *fp;
	char str[50],str2[50], dod[9];
	char *result, *datafile;
	int cmpresult,i;
		
	fp=fopen(fname,"r");
	printf("\nData Odierna (gg/mm/aaaa)> ");
	scanf("%s", &dod);
//	printf("\n\t%s\n", dod);
	
	
	printf("\t\t-STAMPA-\n");
	while(1)
	{
		result=fgets(str,50,fp);
		if(result==NULL)
		{
			break;
		}
		strcpy(str2,str);
		datafile = strtok(str2," ");
		cmpresult=strcmp(datafile,dod);
	//	printf("\ncmpresult: %d\n", cmpresult);
		if(cmpresult==0)
		{
			printf("\n\t %s",str);
		}
	}
	printf("\n\n");
	fclose(fp);
	return;
}

void stampa_per_prodotto(char fname[])
{
	FILE *fp;
	char str[50],str2[50], prod[30], prodfile[50];
	char *result,*pch;
	int cmpresult,i;
		
	fp=fopen(fname,"r");
	printf("\nNome prodotto> ");
	scanf("%s", &prod);
	
	printf("\t\t-STAMPA-\n");
	while(1)
	{
		result=fgets(str,50,fp);
		if(result==NULL)
		{
			break;
		}
		strcpy(str2,str);
		pch = strtok(str2," ");
		for (i=0;pch != NULL;i++)
  		{
  			//printf ("test1: %s\n",pch);
    		pch = strtok (NULL," ");	
			if(i==0)
    		{
				cmpresult=strcmp(prod,pch);
			//	printf("prod: %s , pch: %s\n", prod,pch);
				if(cmpresult==0)
				{
					printf ("%s\n",str);
				}
			}
 		 }
	}
	printf("\n\n");
	fclose(fp);
	return;
}



