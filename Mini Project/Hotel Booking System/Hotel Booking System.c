#include<stdio.h>
#include<string.h>
#include<time.h>

void checkRoomRecordFile(); // first time system
void createNewRoomFile();
struct HotelRoomData getRoomData();
void writeNewRoomFile();
void printRoom();
void bookingRoom(); //booking room
void roomMenuList();
void writeBookingRecordFile();
void writeReceiptFile(); //receipt
int searchRoom(); //serach room
int verifyRoomID();
void readRoomFileByType();
struct CustomerData addCustomer(); //add customer
void writeCustomerFile();
void printCustomer();
void confirmInputData();
void updateRoomFile(); //update room
void writeRoomFile();
void cancelRoom(); //check-out room
void readAllRoomFile();
void printRecord(); //print records
void readAllCustomerFile();
void readAllBookingFile();
void mainMenu(); //main menu

struct CustomerData{
	char name[20];
	char phone[10];
	int age;
	char gender[6];
};
struct HotelRoomData{
	int id;
	int type;
	int bedNum;
	double price;
	int condition;
	char userName[20];
};

int InputError(int num, int min, int max){
	//input is out of range
	if(num < min || num > max){
		printf("\a ... Wrong input! Try Again ... \n");
		return 0;
	}
	//input is not out of range
	else
		return 1;
}
double calPrice(int t, int n){
	if(t==1)
		return (10.00 * n);
	else if(t==2)
		return (25.00 * n);
	else if(t==3)
		return (45.00 * n);
	else
		return (70.00 * n);
}
int Confirmation(){
	int confirm = 0, input = 0, i = 0;
	
	printf("\n");
	for(i = 0; i < 50; i++)
		printf("-");
	do{
		printf("\n\t*Are you sure? (1.Yes / 2.No): ");
		scanf("%d", &confirm);
		input = InputError(confirm, 1, 2);
	}while(input == 0);
	
	if(confirm == 1)
		return 1;
	else 
		return 0;
}

int main(){
	checkRoomRecordFile(); //to decide whatever is new system or not
	return 0;
}
void checkRoomRecordFile(){
	FILE *file;
	
	system("cls");
	file = fopen("Room Record.txt", "r");
	if(file == NULL){
		printf("File is Not Exist in the system! \n\n");
		createNewRoomFile();
		mainMenu();	
	}
	else{
		printf("File is Exist! Going to Main Menu... \n");
		mainMenu();
	}
	fclose(file);
}

// ---------- Create New Room File ----------
void createNewRoomFile(){
	struct HotelRoomData room[20];
	int i = 0 ;
	
	system("cls");
	printf("Creating hotel room record ...\n\n");
	for(i = 0; i < 5; i++){
		room[i] = getRoomData( (10 * 100 + i + 1), 1, 1, 10.00, 0);
		room[i + 5] = getRoomData( (20 * 100 + i + 1), 2, 2, 25.00, 0);
		room[i + 10] = getRoomData( (30 * 100 + i + 1), 3, 4, 45.00, 0);
		room[i + 15] = getRoomData( (40 * 100 + i + 1), 4, 2, 70.00, 0);
	}
	writeNewRoomFile(room);
//	for(i = 0; i < 100; i++)
//		printf("*");
//	printf("\n");
//	for(i = 0; i < 20; i++)
//		printRoom( room[i] );
//	for(i = 0; i < 100; i++)
//		printf("*");
	printf("\nRoom Data is created.\n");
}
struct HotelRoomData getRoomData(int id, int type, int bed, double p, int cond){
	struct HotelRoomData r;
	
	r.id = id;
	r.type = type;
	r.bedNum = bed;
	r.price = p;
	r.condition = cond;
	strcpy(r.userName, "NULL");
	
	return r;
}
void writeNewRoomFile(struct HotelRoomData *r){
	FILE *file;
	int i = 0;
	
	file = fopen("Room Record.txt", "w"); //"w" overwrite, "a" update
	while(i < 20){
		fprintf(file, "\n%d\t", r[i].id);
		fprintf(file, "%d\t", r[i].type);
		fprintf(file, "%d\t", r[i].bedNum);
		fprintf(file, "%.2f\t", r[i].price);
		fprintf(file, "%d\t", r[i].condition);
		fprintf(file, "%s\t", r[i].userName);	
		i++;	
	}
	fclose(file);
}
void printRoom(struct HotelRoomData r){
	printf("Room ID: %d \t", r.id);
	printf("Room Type: %d \t", r.type);
	printf("No. of Bed: %d \t", r.bedNum);
	printf("Price: RM%.2f \t", r.price);
	if(r.condition == 0)
		printf("Condition: Free. \t");
	else
		printf("Condition: In-use. \t");
	printf("User: %s \n", r.userName);
}
// ---------- END SECTION for create new room ----------

// ---------- Booking Room ----------
void bookingRoom(){
	int input = 0, id = 0, conf = 0; //false
	int type = 0, night = 0;
	double total = 0;
	char name[20];
	struct CustomerData c;
	struct HotelRoomData r;
	
	roomMenuList();
	do{
		printf("Enter room type (1,2,3,4): ");
		scanf("%d", &type);	
		input = InputError(type, 1, 4);
	}while(input == 0);
	switch(type){
		case 1:
			id = searchRoom(1);
			if(id == 0){
				// wrong ID number
				mainMenu();
			}
			break;
		case 2:	
			id = searchRoom(2);
			if(id == 0){
				// wrong ID number
				mainMenu();
			}
			break;
		case 3:
			id = searchRoom(3);
			if(id == 0){ 
				// wrong ID number
				mainMenu();
			}
			break;
		case 4:
			id = searchRoom(4);
			if(id == 0){
				// wrong ID number
				mainMenu();
			}
			break;
		default:
			mainMenu();
			break;
	}
	printf("\nHow many night stay: ");
	scanf("%d", &night);
	total = calPrice(type, night);
	printf("\nRoom ID: %d \n", id);
	printf("Night  : %d \n", night);
	printf("Total  : RM%.2f \n", total);
	conf = Confirmation();
	if(conf == 1){
		c = addCustomer();
		confirmInputData(c, id, type, night, total); //include update
		mainMenu();
	}
	else
		mainMenu();
}
void roomMenuList(){
	system("cls");
	printf(" ---------------- BOOKING ROOM ----------------- \n");
	printf("\t ------------------------------- \n");
	printf("\t |   Room   |  Price(RM)/Night  | \n");
	printf("\t ------------------------------- \n");
	printf("\t |  Room A  |      RM 10.00     | \n");
	printf("\t |  Single  |                   | \n");
	printf("\t ------------------------------- \n");
	printf("\t |  Room B  |      RM 25.00     | \n");
	printf("\t |  Double  |                   | \n");
	printf("\t ------------------------------- \n");
	printf("\t |  Room C  |      RM 45.00     | \n");
	printf("\t |  Family  |                   | \n");
	printf("\t ------------------------------- \n");
	printf("\t |  Room D  |      RM 70.00     | \n");
	printf("\t |   VIP    |                   | \n");
	printf("\t ------------------------------- \n");
	printf("\n");
}
void writeBookingRecordFile(struct CustomerData c, int id, int night, double total){
	FILE *file;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	
	file = fopen("Booking History Record.txt", "a");
	fprintf(file, "\n%d\t", c.age + id);
	fprintf(file, "%d\t", id); //roomID
	fprintf(file, "%d\t", night); //night
	fprintf(file, "%.2f\t", total); //total
	fprintf(file, "%d\t", (tm.tm_mday  *100 + tm.tm_mon + 1) ); //date
	//customer part
	fprintf(file, "%s\t", c.name);
	if(c.gender[0] == 'm' || c.gender[0] == 'M')
		fprintf(file, "Male\t"); 
	else if(c.gender[0] == 'f' || c.gender[0] == 'F')
		fprintf(file, "Female\t"); 
	else
		fprintf(file, "NotReg\t"); 
	fprintf(file, "%d\t", c.age); 
	fprintf(file, "%s\t", c.phone);
	fclose(file);
}
void writeReceiptFile(struct CustomerData c, int id, int type, int night, double total){
	FILE *file;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int i = 0;
	double price = 0;
	
	if(type == 1)
		price = 10.00;
	else if(type == 2)
		price = 25.00;
	else if(type == 3)
		price = 45.00;
	else if(type == 4)
		price = 70.00;
	else
		price = 0;
	
	file = fopen("Receipt.txt", "w");
	fprintf(file, " ---------- ABC Hotel Receipt ---------- \n");
	fprintf(file, "Receipt ID: %d\n", c.age + id);
	fprintf(file, "Date: %d\t Time: %d\n", (tm.tm_mday*100 + tm.tm_mon+1), (tm.tm_hour*100 + tm.tm_min));
	fprintf(file, "\n\tCustomer Information:");
	fprintf(file, "\nName: %s\t Contact No.: %s\n", c.name, c.phone);
	if(c.gender[0] == 'm' || c.gender[0] == 'M')
		fprintf(file, "Gender: Male\t Age:%d\n", c.age);
	else if(c.gender[0] == 'f' || c.gender[0] == 'F')
		fprintf(file, "Gender: Female\t Age:%d\n", c.age);
	else
		fprintf(file, "Gender: NotReg\t Age:%d\n", c.age);
	fprintf(file, "\n\tHotel Room Information:");
	fprintf(file, "\nRoom ID\t Night\t Price(RM)\n");
	fprintf(file, "%d\t %d\t %.2f\n", id, night, price);
	for(i = 0; i < 40; i++)
		fprintf(file, "*");
	fprintf(file, "\nTotal: \t\t RM%.2f\n", total);
	for(i = 0; i < 40; i++)
		fprintf(file, "*");
	fclose(file);
}
// ---------- END SECTION for booking room ----------

// ---------- Search & Verify Room ----------
int searchRoom(int type){
	int id = 0, i = 0, result = 0;
	
	readRoomFileByType(type);
	printf("Enter Room ID: ");
	scanf("%d", &id);
	result = verifyRoomID(id, type);
	if(result == 1){
		printf("Room exist and Able to use.");
		return id;
	}
	else{
		printf("NO ROOM.");
		return 0;
	}
}
int verifyRoomID(int id, int type){
	FILE *file;
	struct HotelRoomData temp[20];
	int i = 0;
	char buffer[20];
	
	file = fopen("Room Record.txt", "r");
	if(file == NULL)
		printf("Unable to read the file...");

	while( fgets(buffer, 20, file) != NULL ){
		fscanf(file, "%d", &temp[i].id);
		fscanf(file, "%d", &temp[i].type);
		fscanf(file, "%d", &temp[i].bedNum);
		fscanf(file, "%lf", &temp[i].price);
		fscanf(file, "%d", &temp[i].condition);
		fscanf(file, "%s", &temp[i].userName);
		if(temp[i].id == id && temp[i].condition == 0 && temp[i].type == type)
			return 1;
	}
	fclose(file);
	return 0;
}
void readRoomFileByType(int type){
	FILE *file;
	int size = 20, i = 0;
	char buffer[size];
	struct HotelRoomData temp[size];
	
	system("cls");
	file = fopen("Room Record.txt", "r");
	if(file == NULL)
		printf("Unable to read the file...");
	
	printf(" ********************** Rooms (Type %d) ********************** \n", type);
	printf("ID\t Type\t No.Bed\t Price(RM)\t Condition\t User\n");
	while( fgets(buffer, size, file) != NULL ){
		fscanf(file, "%d", &temp[i].id);
		fscanf(file, "%d", &temp[i].type);
		fscanf(file, "%d", &temp[i].bedNum);
		fscanf(file, "%lf", &temp[i].price);
		fscanf(file, "%d", &temp[i].condition);
		fscanf(file, "%s", &temp[i].userName);
		if(temp[i].type == type){
			printf("%d \t",temp[i].id);
			printf(" %d \t",temp[i].type);
			printf(" %d \t",temp[i].bedNum);
			printf("%.2lf \t\t",temp[i].price);
			if(temp[i].condition == 0)
				printf(" Free \t\t");
			if(temp[i].condition ==1 )
				printf(" In-use \t");
		printf(" %s \n",temp[i].userName);
		}
		i++;
	}
	printf(" ********************************************************** \n");
	fclose(file);
}
// ---------- END SECTION for serach & verify ----------

// ---------- Add Customer ----------
struct CustomerData addCustomer(){
	struct CustomerData cust;
	int conf = 0;
	
	system("cls");
	printf(" ----- ENTER CUSTOMER INFORMATION -----\n\n");
	printf("Name: ");
	scanf("%s", &cust.name);
	printf("Gender (Male / Female): ");
	scanf("%s", &cust.gender);
	printf("Age: ");
	scanf("%d", &cust.age);
	printf("Contact No.: ");
	scanf("%s", &cust.phone);
	conf = Confirmation();
	if(conf == 1){
		writeCustomerFile(cust);
		printf("Record updated ... \n");
		return cust;
	}
	else
		mainMenu();
}
void writeCustomerFile(struct CustomerData c){
	FILE *file;
	file = fopen("Customer Record.txt", "a");
	if(file == NULL)
		printf("ERROR");
		
	fprintf(file, "\n%s\t", c.name);
	fprintf(file, "%d\t", c.age);
	if(c.gender[0] == 'm' || c.gender[0] == 'M')
		fprintf(file, "Male\t");
	else if(c.gender[0] == 'f' || c.gender[0] == 'F')
		fprintf(file, "Female\t");
	else
		fprintf(file, "NotReg\t");
	fprintf(file, "%s\t", c.phone);
	fclose(file);
}
void printCustomer(struct CustomerData c){
	printf("Name: %s \t", c.name);
	if(c.gender[0] == 'm' || c.gender[0] == 'M')
		printf("Gender: Male\t");
	else if(c.gender[0] == 'f' || c.gender[0] == 'F')
		printf("Gender: Female\t");
	else
		printf("Gender: NotReg\t");
	printf("Age: %d \t", c.age);
	printf("Phone: %s \n", c.phone);
}
void confirmInputData(struct CustomerData cust, int id, int type, int n, double t){
	int conf = 0;
	
	system("cls");
	printf("\t ---------- INFO CONFIRMATION ---------- \n\n");
	printf("Customer Information \n");
	printCustomer(cust);
	printf("\nHotel Room Information \n");
	printf("Room ID: %d \t", id);
	printf("Night: %d \t", n);
	printf("Total: RM%.2f \n", t);
	conf = Confirmation();
	if(conf == 1){
		updateRoomFile(id, cust, 1);
		writeReceiptFile(cust, id, type, n, t);
		writeBookingRecordFile(cust, id, n, t);
	}
	else
		mainMenu();
}
// ---------- END SECTION for add customer ----------

// ---------- Update Room File ----------
void updateRoomFile(int id, struct CustomerData c, int cond){
	FILE *file;
	int i = 0;
	char buffer[20];
	struct HotelRoomData temp[20];
	
	file = fopen("Room Record.txt", "r");
	if(file == NULL)
		printf("\nUnable to read the file ... \n");
	while( fgets(buffer, 20, file) != NULL){
		fscanf(file, "%d", &temp[i].id);
		fscanf(file, "%d", &temp[i].type);
		fscanf(file, "%d", &temp[i].bedNum);
		fscanf(file, "%lf", &temp[i].price);
		fscanf(file, "%d", &temp[i].condition);
		fscanf(file, "%s", &temp[i].userName);
		if(temp[i].id == id && temp[i].condition != cond){ 
			temp[i].condition = cond;
			strcpy(temp[i].userName, c.name);
		}
		i++;
	}
	fclose(file);
	writeRoomFile(temp);
	printf("REWRITE DONE");
}
void writeRoomFile(struct HotelRoomData *r){
	FILE *file;
	int i = 0;
	
	file = fopen("Room Record.txt", "w"); //"w" overwrite, "a" update
	while(i < 20){
		fprintf(file, "\n%d\t", r[i].id);
		fprintf(file, "%d\t", r[i].type);
		fprintf(file, "%d\t", r[i].bedNum);
		fprintf(file, "%.2f\t", r[i].price);
		fprintf(file, "%d\t", r[i].condition);
		fprintf(file, "%s\t", r[i].userName);	
		i++;	
	}
	fclose(file);
}
// ---------- END SECTION for update room ----------

//---------- Check-out Room ----------
void cancelRoom(){
	int id = 0, conf = 0;
	struct CustomerData cust;
	
	system("cls");
	printf(" ---------------- CANCEL ROOM ----------------- \n");
	readAllRoomFile();
	printf("Enter Room ID: ");
	scanf("%d", &id);
	strcpy(cust.name, "NULL");
	updateRoomFile(id, cust, 0);
	printf("\nRecord Updated ... Goto main menu... \n");
	conf = Confirmation();
	if(conf == 1)
		mainMenu();
}
void readAllRoomFile(){
	FILE *file;
	int size = 20, i = 0;
	char buffer[size];
	struct HotelRoomData temp[size];
	
	file = fopen("Room Record.txt", "r");
	if(file == NULL)
		printf("Unable to read the file...");

	printf("\n ********************************************************** \n");
	printf("Room ID\t Type\t No.Bed\t Price(RM)\t Condition\t User\n");
	while( fgets(buffer, size, file) != NULL ){
		fscanf(file, "%d", &temp[i].id);
		fscanf(file, "%d", &temp[i].type);
		fscanf(file, "%d", &temp[i].bedNum);
		fscanf(file, "%lf", &temp[i].price);
		fscanf(file, "%d", &temp[i].condition);
		fscanf(file, "%s", &temp[i].userName);
		printf("%d \t",temp[i].id);
		printf(" %d \t",temp[i].type);
		printf(" %d \t",temp[i].bedNum);
		printf("%.2lf \t\t",temp[i].price);
		if(temp[i].condition == 0)
			printf(" Free \t\t");
		if(temp[i].condition ==1 )
			printf(" In-use \t");
		printf(" %s \n",temp[i].userName);
	}
	printf(" ********************************************************** \n");
	fclose(file);
}
// ---------- END SECTION for check-out room ----------

// ---------- Print Record ----------
void printRecord(){
	int action = 0, input = 0, conf = 0;
	
	system("cls");
	printf(" ---------------- DISPLAY RECORD ----------------- \n\n");
	printf("1. Room record. \n");
	printf("2. Customer record. \n");
	printf("3. Booking record. \n");
	do{
		printf("Enter action (1,2,3): ");
		scanf("%d", &action);
		input = InputError(action, 1, 3);
	}while(input == 0);
	switch(action){
		case 1:
			readAllRoomFile();
			break;
		case 2:
			readAllCustomerFile();
			break;
		case 3:
			readAllBookingFile();
			break;
		default:
			break;
	}
	printf("\nGoto main menu... \n");
	conf = Confirmation();
	if(conf == 1)
		mainMenu();
}
void readAllCustomerFile(){
	FILE *file;
	int i = 0, size = 20;
	char buffer[size];
	struct CustomerData temp[size];
	
	file = fopen("Customer Record.txt", "r");
	if(file == NULL)
		printf("Unable to read the file...");
	
	printf("\n ********************************************************** \n");
	printf("Name\t Age\t Gender\t Contact No.\n");
	while( fgets(buffer, size, file) != NULL ){
		fscanf(file, "%s", &temp[i].name);
		fscanf(file, "%d", &temp[i].age);
		fscanf(file, "%s", &temp[i].gender);
		fscanf(file, "%s", &temp[i].phone);
		printf("%s \t",temp[i].name);
		printf(" %d \t",temp[i].age);
		printf(" %s\t",temp[i].gender);
		printf("%s \n",temp[i].phone);
	}
	printf(" ********************************************************** \n");
	fclose(file);
}
void readAllBookingFile(){
	FILE *file;
	int i = 0, size = 20;
	int bookID[size], night[size], date[size];
	double total[size];
	char buffer[size];
	struct CustomerData tempC[size];
	struct HotelRoomData tempR[size];
	
	file = fopen("Booking History Record.txt", "r");
	if(file == NULL)
		printf("Unable to read the file...");
	
	printf("\n ********************************************************** \n");
	printf("BookingID\t RoomID\t Night\t Total(RM)\t Date\t"); 
	printf("Name\t Gender\t Age\t Contact No.\n");
	while( fgets(buffer, size, file) != NULL ){
		fscanf(file, "%d", &bookID[i]);
		fscanf(file, "%d", &tempR[i].id);
		fscanf(file, "%d", &night[i]);
		fscanf(file, "%lf", &total[i]);
		fscanf(file, "%d", &date[i]);
		fscanf(file, "%s", &tempC[i].name);
		fscanf(file, "%s", &tempC[i].gender);
		fscanf(file, "%d", &tempC[i].age);
		fscanf(file, "%s", &tempC[i].phone);
		printf("%d \t\t",bookID[i]);
		printf(" %d \t",tempR[i].id);
		printf(" %d \t",night[i]);
		printf(" %.2lf\t\t",total[i]);
		printf(" %d \t",date[i]);
		printf(" %s \t",tempC[i].name);
		printf(" %s\t",tempC[i].gender);
		printf(" %d \t",tempC[i].age);
		printf(" %s \n",tempC[i].phone);
	}
	printf(" ********************************************************** \n");
	fclose(file);
}
// ---------- END SECTION for print record ----------

// ---------- Main Menu ----------
void mainMenu(){
	int action, input = 0;
	
	system("cls");
	printf("\t ---------- Welcome to ABC Hotel ----------- \n\n");
	printf("\n ********** MAIN MENU ********** \n");
	printf("1. Check-in / Booking Room. \n");
	printf("2. Check-out / Cancel Room. \n");
	printf("3. Print Record. \n");
	printf("0. Close system. \n");
	do{
		printf("Enter action number (1,2,3,0): ");
		scanf("%d", &action);
		input = InputError(action, 0, 3);
	}while(input == 0);
	switch(action){
		case 1:
			bookingRoom();
			break;
		case 2:
			cancelRoom();
			break;
		case 3:
			printRecord();
			break;
		default:
			break;
	}
	printf("\t ***** THANK YOU ***** \n");
}
// ---------- END SECTION for Main Menu ----------
