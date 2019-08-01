#include<stdio.h>

int main(){
	int i = 0;
	int input;
	int max;
	
	printf("\nCombine of Loop Statement.\n");
	printf("1. For loop.\n");
	printf("2. While loop.\n");
	printf("3. Do_while loop.\n");
	printf("\nEnter any one number from the list here: ");
	scanf("%d", &input);
	
	switch(input){
		case 1:
			printf("\n\tMethod 1 - Counting start:");
			for(i = 0; i < 10; i++)
				printf("\nValue of i = %d", i);
			break;
		case 2:
			printf("\n\tMethod 2 - Counting start:");
			while(i < 10){
				printf("\nValue of i = %d", i);
				i++;
			}
			break;
		case 3:
			printf("Enter maximum number(1 to 50): ");
			scanf("%d", &max);
			printf("\nMethod 3 - Counting start:");
			do{
				printf("\nValue of i = %d", i);
				i++;
			}while(i < max);
			break;
		default:
			printf("\a\tOut of the list ...");
			break;
	}
	printf("\n\tCounting END as %d", i);
	
	return 0;
}
