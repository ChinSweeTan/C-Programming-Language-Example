#include<stdio.h>

void startLift(int);
int selectFloor(int);

int main(){
	int currentLift = 0;
	startLift(currentLift);
	printf("Elevator System Close-Down");
	return 0;
}

void startLift(int curLift){
	int nPassenger = 0; 
	char con;

	system("cls");
	printf("\nLift currently start at %d Floor. \n", curLift);
	printf("\a\n\t *** Door open *** ");
	do{
		printf("\nNo. of Passenger (max:10): ");
		scanf("%d", &nPassenger);
		if(nPassenger > 10)
			printf("\n\a Overweight! Try Again ....");
	}while(nPassenger > 10);
	curLift = selectFloor(nPassenger);
	printf("\nLift currently ended at %d Floor. \n", curLift);
	printf("\nContinue using the lift? (Y - Yes , N - No): ");
	scanf("%s", &con);
	if(con == 'Y' || con =='y')
		startLift(curLift);
}

int selectFloor(int num){
	int i = 0, n = 0, j = 0;
	int liftFloor[10];
	int temp1=0;
	
	printf("\n");
	for(i = 0; i < num; i++){
		do{
			printf("Enter the %d floor number (1 to 10): ", i+1);
			scanf("%d", &liftFloor[i]);		
			if(liftFloor[i] > 10)
				printf("\n\a %d Floor is not available! Try Again ....\n", liftFloor[i]);
		}while(liftFloor[i] > 10);
	}
	
	printf("\a\t *** Door closing *** \n");
	//ascending floor number
	for(i = 0; i < num; i++){
		for(j = i + 1; j < num; j++) {
			if (liftFloor[i] > liftFloor[j]) {
				temp1 =  liftFloor[i];
                liftFloor[i] = liftFloor[j];
				liftFloor[j] = temp1;
            }
		}
	}
	
	for(i = 0; i < num; i++){
		if(liftFloor[i] == n)
			printf("Repeated floor number");
		else
			printf("\nLift is moving to %d Floor ...", liftFloor[i]);
		n = liftFloor[i];
	}
	
	return n;
}
