#include<stdio.h>

int main(){
	int i = 0; //intialise loop counter
	
	printf("Counting start here:\n");
	while(i < 10){
		printf("\nValue of i = %d", i);
		i++;
	}
	printf("\nCounting end as %d", i);
	
	return 0;
}
