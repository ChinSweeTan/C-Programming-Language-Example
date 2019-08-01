#include<stdio.h>

int main(){
	int ans;
	
	printf("\n2 + 2 = x \n");
	printf("What is x?\n");
	do{
		printf("\nInput your answer: ");
		scanf("%d", &ans);	
		if(ans == 4)
			printf("You are correct!");
		else
			printf("\aIncorrect, Try again ...\n");
	}while(ans != 4);
	
	return 0;
}
