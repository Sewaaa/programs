/*STRINGHE*/
#include <stdio.h>
#include <string.h>

#define maxcaratteri 80
void count_spaces(char s[]);
int main()
{
	char c;
	c="abc"[1]; //salva in c solo B
	printf("%c",c);
	
	char ch[maxcaratteri+1]="abc";	
	printf("\n%s",ch);
	
							/*Prende input e stampa SCANF*/
	char a[maxcaratteri+1];
	printf("\nInserisci : ");
	scanf("%s", a); //però non prende gli spazi
	printf("\n");
	puts(a);
	
								/*Prende input e stampa GETS*/
	printf("\nInserisci : ");
	gets(a);   //però và oltre lo spazio assegnato 
	printf("\n");
	puts(a);
	
									/*Prende input e stampa FGETS*/
	printf("\nInserisci : ");
	fgets(a,maxcaratteri+1,stdin);   //però dopo la striga inserisce anche il "accapo" e poi "\0"
		if(a[strlen(a)-1]=='\n')	//quindi verifichiamo e nel caso eliminiamo
		{
			a[strlen(a)-1]='\0';
		}
	printf("\n");
	puts(a);
	
	
	count_spaces(a);//conta quanti spazi vuoti ci sono 
	
	strcpy(a,"abc2"); // a="abc2" (ma non copia il valore nullo nell'ulta posizione \0)
	a[sizeof(a)-1]='\0'; //quindi lo facciamo manualmente
	printf("\n");
	puts(a);
	
	
	int ris;
	ris=strlen(a); //conta lunghezza e ti riporta in output il numero
	printf("\nlunghezza: %d", ris);
	
	strcat(a,"def3"); //aggiunge alla fine di a def3 (concatenazione)	
	printf("\n");
	puts(a);
						
							/*Confronto lessicografico (in base al codice ASCII)*/
	
	char b1[maxcaratteri+1]="abc";
	char b2[maxcaratteri+1]="def";
	if(strcmp(b1,b2) <0){} // a<b ?
	if(strcmp(b1,b2) <=0){} //a<=b ?
	if(strcmp(b1,b2) !=0){} // a!=b ?
	if(strcmp(b1,b2) ==0){} //a==b ?
	if(strcmp(b1,b2) >=0){} // a>=b ? ...
	
	
}

void count_spaces(char s[])
	{
	  int count = 0, i;

	  for (i = 0; s[i] != '\0'; i++)
	    if (s[i] == ' ')
	      count++;
	  printf("%d",count);
	}

