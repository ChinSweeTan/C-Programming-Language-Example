#include<stdio.h>

int main(){
	int i; //loop counter
	
	printf("Counting start here:\n");
	//intialise i with a number to become either...
	//lower using i--
	//higer using i++
	for(i = 0; i < 10; i++){
		printf("\nValue of i = %d", i);
	}
	printf("\nCounting end as %d", i);
	
	return 0;
}
