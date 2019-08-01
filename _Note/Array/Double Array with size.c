#include<stdio.h>

int main(){
	int array[3][3];
	int i = 0, j;
	
	printf("Enter any 9 number for the 3x3 matrix.\n\n");
	printf("---------- Input Here ----------\n");
	while(i < 3){
		printf("Enter 3 number for Row %d:\n", i+1);
		j = 0;
		while(j < 3){
			printf("Element %d*%d, Input here: ", i+1, j+1);
			scanf("%d", &array[i][j]);
			j++;
		}
		i++;
	}
	
	printf("\n ------------- Result -------------\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			printf("%d\t", array[i][j]);
		printf("\n");
	}

	return 0;
}
