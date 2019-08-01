#include<stdio.h>

int main(){
	int input;
	
	printf("Enter any integer number: ");
	scanf("%d", &input);
	
	if(input > 10){
		printf("\nInput: %d, is larger than 10.", input);
	}
	else if(input == 10){
		printf("\nInput: %d, is equal to 10.", input);
	}
	else{
		printf("\nInput: %d, is smaller than 10.", input);
	}
	
	return 0;
}
