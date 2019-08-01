#include<stdio.h>

int main(){
	//preset the array data without size
	int array[] = {2, 4, 6, 8, 10};
	int i = 0;
	
	printf("Intialised 5 number in the array.\n");
	printf("\n ------------------ Result ------------------\n");
	for(i = 0; i < 5; i++)
		printf("Element %d\t Array Index %d\t Input Data = %d\n", i + 1, i, array[i]);
	
	return 0;
}
