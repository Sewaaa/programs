#include <stdio.h>
#define SIZE 5

int ReadArray(int a[]);

void PrintArray(int a[], int size);

int RemoveRipeti(int a[], int b[],int size);

int main()
{
    int a[SIZE],b[SIZE];
    int l,nl;
    l = ReadArray(a);
    nl = RemoveRipeti(a,b,l);
    printf("Vettore prima della rimozione: \n ");
    PrintArray(a,l);
    printf("Vettore dopo la rimozione: \n ");
    PrintArray(b,nl);


    return 0;
}




int ReadArray(int a[]){
    int i;
    for (i=0; i < SIZE; i++){
        printf(" inserisci il %d elemento :", i + 1 );
        scanf("%d", &a[i]);
    
    }
    return i; 
};



void PrintArray(int a[], int size){
    int i;
    for (i=0; i < size; i++)
	{
        printf("%d ", a[i]);
    }
    printf("\n");
  
}

int RemoveRipeti(int a[], int b[],int size){
    int GiaMesso = 0;
    int i;
    int j;
    int k = 0;  
    for (i=0; i < size; i++)
	{
        GiaMesso = 0;
        for (j=0; j < size; j++)
		{
           if (a[i]==b[j]){GiaMesso = 1;}
                   
   		} 
		if( GiaMesso == 0)
		{
	        b[k]= a[i];
	        k++;
	    }

	}
return k;
}

