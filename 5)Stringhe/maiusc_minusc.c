/*Data una stringa convertila da maiuscola a minuscola e viceversa (metodo con codice ASCII e metodo funzione automatica)*/

#include <stdio.h>
#include <string.h>

#define max 10

void leggistringa(char a[]);
void converti_manualmente(char a[]);
void converti_automaticamente(char a[]);

int main()
{
	char a[max+1];
	printf("Inserisci stringa da converire: ");
	leggistringa(a);
	//converti_manualmente(a);
	converti_automaticamente(a);
	
	puts(a);
}

void leggistringa(char a[])
{
	fgets(a,max+1,stdin);
	if(a[strlen(a)-1]=='\n')
	{
		a[strlen(a)-1]='\0';
	}
}

void converti_automaticamente(char a[])
{
	int i;
	
	for (i=0;i<strlen(a);i++)
	{
		if(isalpha(a[i]))
		{	
			if(isupper(a[i]))
			{
				a[i] = tolower(a[i]);
			}
			else
			{
				a[i] = toupper(a[i]);
			}
		}
		else
		{
			a[i]='.';
		}
	}
	
}

void converti_manualmente(char a[])
{
	int i;
	
	for (i=0;i<strlen(a);i++)
	{
		if(65<=a[i]&&a[i]<=90)
		{
			a[i]=a[i]+32;
		}
		else
		{	
			if(97<=a[i]&&a[i]<=122)
			{
				a[i]=a[i]-32;
			}
		}
	}
}
