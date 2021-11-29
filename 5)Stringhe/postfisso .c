/*
Scrivere un programma che legge 2 stringhe s1 e s2, verificare se s1 è un postfisso di s2
*/
#include <stdio.h>
#include <string.h>
#define max 10

void leggistringa(char a[]);
char* confronta (char s1[],char s2[]);

int main()
{
	char s1[max+1],s2[max+1], *result;
	
	printf("\nStringa 1: ");
	leggistringa(s1);
	
	printf("Stringa 2: ");
	leggistringa(s2);
	
	result=confronta(s1,s2);
	if(result!=NULL)
	{
		printf("\nPresente postfisso %s ", result );
	}
	else
	{
		printf("\nNon esiste postfisso");
	}
}

void leggistringa(char a[])
{
	fgets(a,max+1,stdin);
	if(a[strlen(a)-1]=='\n')
	{
		a[strlen(a)-1]='\0';
	}
}

char* confronta (char s1[],char s2[])
{
	int num;
	num=strlen(s2)-strlen(s1);
	if(num<0) return NULL;
 	if(strcmp(s1,s2+num) ==0)
 	{
 		return s2+num;
	}
	else return NULL;
} 



