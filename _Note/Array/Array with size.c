#include<stdio.h>

int main(){
	int array[5];
	int i = 0;
	
	printf("Enter any 5 number.\n\n");
	printf("----- Input Here -----\n");
	do{
		printf("Element %d, input here: ",i + 1);
		scanf("%d", &array[i]);
		i++;
	}while(i < 5);
	
	printf("\n ------------------ Result ------------------\n");
	for(i = 0; i < 5; i++)
		printf("Element %d\t Array Index %d\t Input Data = %d\n", i + 1, i, array[i]);

	return 0;
}
