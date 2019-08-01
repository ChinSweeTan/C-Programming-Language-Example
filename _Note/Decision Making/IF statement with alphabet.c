#include<stdio.h>

int main(){
	char input;
	
	printf("Enter any integer number: ");
	scanf("%c", &input);
	
	if(input == 'm'){
		printf("\nGender consider as Male.");
	}
	else if(input == 'f'){
		printf("\nGender consider as Female.");
	}
	else{
		printf("\nThe keyword is not valid.");
	}
	
	return 0;
}
