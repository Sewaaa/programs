#include <stdio.h>
#include <unistd.h>

int main(){
	int n1=0,i=1;
	
	printf("Ma salve ! Quanti numeri vuoi vedere?\n");
	scanf("%d", &n1);
	 while(i<=n1)
	 {
		 printf(" - %d \n", i);
		 i++;
		 sleep(1);
	 }
	
}