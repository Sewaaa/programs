/*
Un numero di Armstrong di tre cifre è un intero tale che la somma dei cubi delle
sue cifre è uguale al numero stesso. 
Per esempio, 33 + 73 + 13 = 371, quindi 371 è un numero di Armstrong.
Scrivere una funzione che abbia come parametri input un array A[] d'interi e il
numero n di elementi presenti, azzeri i valori di A[] che non sono numeri di
Armstrong, e infine stampi solo i valori non nulli rimanenti.
Articolare la soluzione illustrando i passaggi seguiti:
(a) Analisi e specifica,
(b) Progettazione mediante raffinamento progressivo,
(c) Traduzione in C.
*/

#include <stdio.h>
#define maxdim 50

void leggiVettore(int a[], int n);
void stampaVettore(int a[],int n);
void isArm(int a[],int n);

int main()
{
	int a[maxdim],n;
	
	do{
	printf("\nQuanti numeri devi inserire? ");
	scanf("%d",&n);
	}while(!(n>0 && n<maxdim));
	
	leggiVettore(a,n);
	isArm(a,n);
	printf("Tra quelli inseriti sono numeri Armstrong: ");
	stampaVettore(a,n);
	
}

void leggiVettore(int a[], int n)
{
	int i,z;
	for(i=0;i<n;i++)
	{
		do{
			z=0;
			printf("\nInserisci Valore [%d]: ",i);
			scanf("%d",&a[i]);
			if(a[i]<100||a[i]>999)
			{
				z=1;
				printf("Errore: Devi inserire solo numeri con 3 cifre\n");	
			}
		}while(!(z==0));
	}
}

void stampaVettore(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			printf(" %d", a[i]);
		}	
	}	
}

void isArm(int a[],int n)
{
	int i,result;
	for(i=0;i<n;i++)
	{
		result=sommacubi(a[i]);
		if(a[i]!=result)
		{
			a[i]=000;
		}		
	}
}

int sommacubi(int el)
{
	int result,i=0,n3,n2,n1,temp,vet[50];
	
	for(i=0;el>0;i++)
	{
		vet[i]=el%10;
		el=el/10;
	}
	
	result=(vet[0]*vet[0]*vet[0])+(vet[1]*vet[1]*vet[1])+(vet[2]*vet[2]*vet[2]);
	return result;
}
