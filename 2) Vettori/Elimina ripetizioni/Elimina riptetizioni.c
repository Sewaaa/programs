/*
Scrivere un programma che legga N numeri interi da tastiera e li memorizzi in un vettore. 
Il numero N viene inserito dall'utente ed è minore di 20,
Il programma deve generare un secondo vettore che
compatta i numeri contenuti nel primo vettore. In
particolare:
ogni numero che compare ripetuto nel primo vettore,
-deve comparire una sola volta nel secondo vettore
Il programma deve visualizzare il contenuto del
secondo vettore.
Ad esempio, si supponga N=8 e si consideri la sequenza
di numeri
1 18 3 0 24 3 6 0
Il programma deve visualizzare
1 18 3 0 24 6
*/

#include <stdio.h>
#define maxA 50

void leggiVettore(int a[], int n);
void stampaVettore(int a[],int n);
int compatta(int a[], int n);
int ricerca(int a[],int n,int el,int posIn);
void swap(int a[],int n,int posIn);



int main()
{
	int a[maxA], n;
	
	do{
		printf("Quanti elementi vuoi inserire? (<20) : ");
		scanf("%d",&n);
	}while(!(n>0 && n<20));
	
	leggiVettore(a,n);
	printf("\nVettore: ");
	stampaVettore(a,n);
	n=compatta(a,n);
	printf("\nVettore compattato: ");
	stampaVettore(a,n);
	
}

void leggiVettore(int a[], int n)
{
	int i,val;
	for(i=0;i<n;i++)
	{
		printf("\nInserisci Valore [%d]: ",i);
		scanf("%d",&a[i]);
	}
}

void stampaVettore(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf(" %d", a[i]);
	}	
}

int ricerca(int a[],int n,int el,int posIn)
{
	int i,ric=0; 
	for(i=posIn;i<n;i++)
	{
		if(el==a[i])
		{
			ric++;
			if(ric==2)
			{
				printf("\n %d Trovato ripetizione in pos [%d]", el,i);
				return i;
			}
		}
	}
	return -1;
}

int compatta(int a[], int n)
{
	int i,pos;
	for(i=0;i<n;)
	{
		pos=ricerca(a,n,a[i],i);
		if(pos!=-1)
		{
			swap(a,n,pos);
			n--;
		}
		else
		{
			i++;
		}
	}
	return n;
}

void swap(int a[],int n,int posIn)
{
	int i,temp;
	for(i=posIn;i<n;i++)
	{
		a[i]=a[i+1];
	}
	return ;
}



