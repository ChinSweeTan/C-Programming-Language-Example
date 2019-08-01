#include<stdio.h>

int main(){
	
	double n1;
	double n2;
	double total;
	int operation;
	char opText;
	
	printf("Enter any 1st number: ");
	scanf("%lf", &n1);
	printf("Enter any 2nd number: ");
	scanf("%lf", &n2);
	
operation:
	printf("\n1. Addition/Plus (+). \n");
	printf("2. Subtraction/Minus (-). \n");
	printf("3. Multiplication/Times (*). \n");
	printf("4. Division/Obelus (/). \n");
	printf("Select the math operation (1,2,3,4): ");
	scanf("%d",&operation);
	if(operation >4 || operation < 0){
		goto operation;
	}
	
	switch(operation){
		case 1:
			total = n1 + n2;
			opText = '+';
			break;
		case 2:
			total = n1 - n2;
			opText = '-';
			break;
		case 3:
			total = n1 * n2;
			opText = '*';
			break;
		case 4:
			total = n1 / n2;
			opText = '/';
			break;
	}
	
	printf("\nANSWER: %.2f %c %.2f = %.2f", n1, opText, n2, total);
	return 0;
}
