#include<stdio.h>
#include<time.h>
#include<string.h>

int mainMenu();
int goMainMenu();
void printFoodMenu();
void orderFood();
void printOrderDetail();
void writeReceipt();
void writeRecord();
int readRecordFile();
int InputError();

struct comboData{
	int combo;
	double price;
};

struct recordData{
	int id;
	int date;
	int time;
	int type;
	double total;
	struct comboData combo[10];
};

int main(){
	mainMenu();
}

int mainMenu(){
	int action, input;
	
	system("cls");
	printf("--- Welcome to ABC Restaurant --- \n");
	printf("1. Order Food. \n");
	printf("2. Print records & Summary. \n");
	printf("0. End. \n");
	do{
		printf("Select action (1,2,3,0): ");
		scanf("%d", &action);
		input = InputError(action, 0, 2);
	}while(input == 1);
	
	switch(action){
		case 1:
			orderFood();
			break;
		case 2:
			readRecordFile();
			break;
		case 0:
			printf("\n\n ********** THANK YOU & GOOD BYE ********** ");
			return 0;
		default:
			break;
	}
	return 0;
}

int goMainMenu(){
	int option, input;
	
	do{
		printf("\nGo Back to main menu? (1.Yes, 2.No): ");
		scanf("%d", &option);
		input = InputError(option, 1, 2);	
	}while(input == 1);
	
	switch(option){
		case 1:
			mainMenu();
			break;
		case 2:
			printf("\n\n ********** THANK YOU & GOOD BYE ********** ");
			return 0;
			break;
		default:
			break;
	}
}

void printFoodMenu(){
	system("cls");
	printf(" ***** Welcome to ABC Restaurant ***** \n");
	printf(" --------------------------------------------------  \n");
	printf("|   Combo    |      Price(RM)    |       Food      | \n");
	printf(" --------------------------------------------------  \n");
	printf("|  Combo A   |      RM 7.50      |  Buger + Drink  | \n");
	printf(" --------------------------------------------------  \n");
	printf("|  Combo B   |      RM 7.00      |  Rice + Drink   | \n");
	printf(" --------------------------------------------------  \n");
	printf("|  Combo C   |      RM 5.50      |      Burger     | \n");
	printf(" --------------------------------------------------  \n");
	printf("|  Combo D   |      RM 5.00      |       Rice      | \n");
	printf(" --------------------------------------------------  \n");
	printf("|  Combo E   |      RM 2.00      |       Water     | \n");
	printf(" --------------------------------------------------  \n");
	printf("\n");
}

void orderFood(){
	struct recordData rcd;
	int dt, order, combo;
	int input;
	int i = 0;
	double total = 0;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	printFoodMenu();
	do{
		printf("1.Dive in or 2.Take away? (1,2): ");
		scanf("%d", &dt);
		input = InputError(dt, 1, 2);
	}while(input == 1);
	printf("How many order? ");
	scanf("%d", &order);
	printf("\n");
	do{
		do{
			printf("Select N%d combo number (1,2,3,4,5): ", (i+1) );
			scanf("%d", &rcd.combo[i].combo);
			input = InputError(rcd.combo[i].combo, 1, 5);
		}while(input == 1);
		switch(rcd.combo[i].combo){
			case 1:
				rcd.combo[i].price = 7.50;
				break;
			case 2:
				rcd.combo[i].price = 7.00;
				break;
			case 3:
				rcd.combo[i].price = 5.50;
				break;
			case 4:
				rcd.combo[i].price = 5.00;
				break;
			case 5:
				rcd.combo[i].price = 1.00;
				break;
			default:
				rcd.combo[i].price = 0.00;
				break;
		}
		total += rcd.combo[i].price;
		i++;
	}while(i < order);
	
	//passing value
	rcd.type = dt;
	rcd.total = total;
	rcd.date = (tm.tm_mday * 100) + (tm.tm_mon + 1);
	rcd.time = (tm.tm_hour * 100) + (tm.tm_min);
	rcd.id = rcd.date + rcd.time;
	printOrderDetail(rcd, order);
	writeReceipt(rcd, order);
	writeRecord(rcd, order);
	printf("\n");
	goMainMenu();
}

void printOrderDetail(struct recordData r, int o){
	int i = 0;
	
	printf("\n----- ORDER RECORD ----- \n");
	printf("ID: %d \n", r.id);
		if(r.type == 1)
			printf("Customer Dive in. \n");
		if(r.type == 2)
			printf("Customer Take Away. \n");
		for(i = 0; i < o; i++){
			printf("Order: %d \t", i + 1);
			printf("Combo: %d \t", r.combo[i].combo);
			printf("Price: RM%.2f \n", r.combo[i].price);
		}
		printf("Total: RM%.2f", r.total);	
}

void writeReceipt(struct recordData r, int o){
	FILE *file;
	int i = 0;
	
	file = fopen("Receipt.txt", "w+");
	fprintf(file, "ID: %d\n", r.id);
	fprintf(file, "Date: %d\t Time: %d\n", r.date, r.time);
	if(r.type == 1)
		fprintf(file, "Type: Dive in\n");
	if(r.type == 2)
		fprintf(file, "Type: Take away\n");
	fprintf(file, "Order[%d]\t Combo\t Price \n", o);
	while(i < o){
		fprintf(file, "%d\t\t %d\t %.2f\n", (i+1), r.combo[i].combo, r.combo[i].price);
		i++;
	}
	for(i = 0; i < 40; i++)
		fprintf(file, "*");
	fprintf(file, "\nTotal:\t\t\t %.2f\n", r.total);
	for(i = 0; i < 40; i++)
		fprintf(file, "*");
		
	fclose(file);
}

void writeRecord(struct recordData r, int o){
	FILE *file;
	
	file = fopen("Record.txt", "a");
	//you can write all data in the same line
	//example: fprintf(file, "%d\t %d/t", r.id, r.date);
	fprintf(file, "\n%d\t", r.id);
	fprintf(file, "%d\t", r.date);
	fprintf(file, "%d\t", r.time);
	fprintf(file, "%d\t", r.type);
	fprintf(file, "%d\t", o);
	fprintf(file, "%.2f", r.total);
	fclose(file);
}

int readRecordFile(){
	FILE *file;
	struct recordData temp[10];
	int size = 10, i = 0;
	int order[size];
	char buff[size];
	int  di = 0, ta = 0, meal = 0;
	double sum = 0;
	
	system("cls");
	if( ( file = fopen("Record.txt", "r") ) == NULL)
		printf("Read File Error!!\n");
	
	printf(" --------------- All Records --------------- \n");
	printf("ID\t Date\t Time\t Type\t Order\t Total\n");
	while( fgets(buff, size, file) != NULL){
		fscanf(file, "%d", &temp[i].id);
		fscanf(file, "%d", &temp[i].date);
		fscanf(file, "%d", &temp[i].time);
		fscanf(file, "%d", &temp[i].type);
		fscanf(file, "%d", &order[i]);
		fscanf(file, "%lf", &temp[i].total);
		if(temp[i].type == 1)
			di += 1;
		if(temp[i].type == 2)
			ta += 1;
		printf("%d \t", temp[i].id);
		printf(" %d \t", temp[i].date);
		printf(" %d \t", temp[i].time);
		printf(" %d \t", temp[i].type);
		printf(" %d \t", order[i]);
		printf(" %.2lf\n", temp[i].total);
		sum += temp[i].total;
		meal += order[i];
		i++;
	};
	printf(" ------------------------------------------- \n");
	fclose(file);
	
	printf("\n\n ---------- Summary ---------- \n");
	printf("No. of Record: %d \n", i);
	printf("No. of Dive in: %d \n", di);
	printf("No. of Take Away: %d \n", ta);
	printf("No. of Meal served: %d \n", meal);
	printf("Sum of Total: RM%.2f \n", sum);
	printf(" ----------------------------- \n");
	
	goMainMenu();
}

int InputError(int num, int min, int max){
	//input is out of range
	if(num < min || num > max){
		printf("\a ... Wrong input! Try Again ... \n");
		return 1;
	}
	//input is not out of range
	else
		return 0;
}
