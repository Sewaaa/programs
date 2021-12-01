/*Data una lettera ed una frase, contare quante volte compare la lettera nella frase (maiuscole e minuscole comprese)*/

#include <stdio.h>
#include <string.h>

#define max 50

void leggistringa(char a[]);
int conta_lettera(char a[], char let);

int main()
{
	char a[max+1],l;
	int n;
	
	printf("Inserisci frase: ");
	leggistringa(a);
	printf("\n\nInserisci lettera: ");
	scanf("%c", &l);

	n=conta_lettera(a,l);
	printf("\n\nLettera \"%c\" trovata %d volte\n", l,n);
}

void leggistringa(char a[])
{
	fgets(a,max+1,stdin);
	if(a[strlen(a)-1]=='\n')
	{
		a[strlen(a)-1]='\0';
	}
	return;
}
 
int conta_lettera(char a[], char let)
{
	char let2;
	int n=0,i;
	if(isupper(let))
	{
		let2 = tolower(let);
	}
	else
	{
		let2 = toupper(let);
	}
		
	for(i=0;i<strlen(a);i++)
	{
		if(let==a[i]||let2==a[i])
		{
			n++;
		}
	}
	return n;
}
