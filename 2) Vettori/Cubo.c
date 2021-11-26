#include <stdio.h>
#define SIZE 5

void ReadArray(int a[]);

void PrintArray(int a[]);


void QuadVet(int a[], int b[]);

int main()
{
    int a[SIZE],b[SIZE],c[SIZE];
    int l,nl;
    ReadArray(a);
    QuadVet(a,b);
    QuadVet(b,c);


    printf("elementi array a: ");
    PrintArray(a);
     printf("elementi array b: ");
    PrintArray(b);
     printf("elementi array c: ");
    PrintArray(c);
    
    
 

    return 0;
}




void ReadArray(int a[]){
    int i;
    for (i=0; i < SIZE; i++){
        printf(" inserisci il %d elemento :", i + 1 );
        scanf("%d", &a[i]);
    
    }
  
};



void PrintArray(int a[]){
    int i;
    for (i=0; i < SIZE; i++){
        printf("%d ", a[i]);
    }

    printf("\n");
  
}

 void QuadVet(int a[], int b[]){
     int i;
     for (i=0; i < SIZE; i++){
         b[i]=a[i]*a[i];
    }
 }