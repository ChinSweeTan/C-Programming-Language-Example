#include<stdio.h>

int main(){
	int input;
	
	printf("\tHello and Welcome to \nSelective Statement Chapter in C Programming. \n");
	printf("\n\n\tEnter a number (from 1 to 3): ");
	scanf("%d", &input);
	
	switch(input){
		case 1:
			printf("\n\tYou have enter %d, as ONE", input);
			break;
		case 2:
			printf("\n\tYou have enter %d, as TWO", input);
			break;
		case 3:
			printf("\n\tYou have enter %d, as THREE", input);
			break;
		default:
			printf("\n\tYou have enter other number than 1 to 3 ...\n");
			printf("\tWhere it go to the default case.\n");
			break;
	}
	
	return 0;
}
