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
#define max 50

void leggiVettore(int a[], int n);
void stampaVettore(int a[],int n);
int compatta(int a[],int b[], int n,int z);
int  ricerca(int a[], int n,int elem);




int main()
{
	int a[max],n,z,b[max];
	
	do{
		printf("Quanti elementi vuoi inserire? (<20) : ");
		scanf("%d",&n);
	}while(!(n>0 && n<20));
	
	leggiVettore(a,n);
	printf("\nVettore A: ");
	stampaVettore(a,n);
	z=compatta(a,b,n,z);
	printf("\nVettore B (compattato): ");
	stampaVettore(b,z);
	
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
	for(i=0;i<n-1;i++)
	{
		printf(" %d", a[i]);
	}	
}

int  ricerca(int a[], int n,int elem) 
{
	
    int i = 0;                             
  	
    while(i < n)                    
 	{      if (a[i] == elem)
                    break;        
          else i++;    
     }       
    if(i == n)
	{ 
//	printf("\n%d Non Trovato", elem);
	return -1;  			
	}
//  printf("\n %d Trovato in posizione Vettore[%d]", elem,i); 
	return i;            
}

int compatta(int a[],int b[], int n,int z)
{
	int i=0,y=0,temp,pos;
	
	b[0]=a[0];
	z=1;
	y=1;
	
	while(i<n)
	{
		i++;
		temp=a[i];
		pos=ricerca(b,z,temp);
		
		if(pos==-1)
		{
			b[y]=temp;
			y++;
			z++;
//			printf("\ncopiato");
		}
	}
	return z;
}





