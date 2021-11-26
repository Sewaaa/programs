#include <stdio.h>
#define RMAX 50
#define CMAX 50

void input_array(int a[RMAX][CMAX], int nr, int nc);
void output_array(int a[RMAX][CMAX], int nr, int nc);

int main(void)
{
	int a[RMAX][CMAX],nr,nc;
	
	printf("\nInserisci Numero Righe: ");
	scanf("%d", &nr);
	printf("\nInserisci Numero Colonne: ");
	scanf("%d", &nc);
	input_array(a,nr,nc);
	output_array(a,nr,nc);
}

void input_array(int a[RMAX][CMAX], int nr, int nc) 
{  
	int i, j;   
    for (i = 0; i < nr; i++) 
       for(j = 0; j < nc; j++) {
	       printf( "a[%d][%d]: ", i, j);
           scanf("%d", &a[i][j]);  } 
}

void output_array(int a[RMAX][CMAX], int nr, int nc) 
{ 
	 int i, j;   
    for (i = 0; i < nr; i++) {
       for(j = 0; j < nc; j++)
	       printf(" %d ", a[i][j]);
      printf("\n");  }
}

