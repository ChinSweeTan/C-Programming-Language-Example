#include<stdio.h>

int main(){
	char input;
	
	printf("\tHello and Welcome to \nSelective Statement Chapter in C Programming. \n");
	printf("\n\n\tEnter an alphabet (from a to c): ");
	scanf("%c", &input);
	
	switch(input){
		case 'a':
			printf("\n\tYou have enter letter %c, as 'a' ", input);
			break;
		case 'b':
			printf("\n\tYou have enter letter %c, as 'b' ", input);
			break;
		case 'c':
			printf("\n\tYou have enter letter %c, as 'c' ", input);
			break;
		default:
			printf("\n\tYou have enter other alphabet than a to c ...\n");
			printf("\t\tOR \n\tYou have enter captical letter alphabet ...\n");
			printf("\tWhere it go to the default case.\n");
			break;
	}
	
	return 0;
}
