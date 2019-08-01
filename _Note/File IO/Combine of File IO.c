#include<stdio.h>

struct yourData{
	char name[20];
	char gender[6];
	int age;
	double height;
	double weight;
};

void writeFile(){
	FILE *file;
	struct yourData data;
	
	printf("Enter your name: ");
	scanf("%s", &data.name);
	printf("Enter your gender: ");
	scanf("%s", &data.gender);
	printf("Enter your age: ");
	scanf("%d", &data.age);
	printf("Enter your height: ");
	scanf("%d", &data.height);
	printf("Enter your weight: ");
	scanf("%d", &data.weight);
	
	file = fopen("Your Data.txt", "w+");
	fprintf(file, "\n%s\t", data.name);
	fprintf(file, "%s\t", data.gender);
	fprintf(file, "%d\t", data.age);
	fprintf(file, "%d\t", data.height);
	fprintf(file, "%d", data.weight);
	fclose(file);
	printf("Record been written.");
}
void addDataFile(){
	FILE *file;
	struct yourData data;
	
	printf("Enter your name: ");
	scanf("%s", &data.name);
	printf("Enter your gender: ");
	scanf("%s", &data.gender);
	printf("Enter your age: ");
	scanf("%d", &data.age);
	printf("Enter your height: ");
	scanf("%d", &data.height);
	printf("Enter your weight: ");
	scanf("%d", &data.weight);
	
	file = fopen("Your Data.txt", "a+");
	if(file == NULL)
		printf("\aUnable to find the file!");
		
	fprintf(file, "\n%s\t", data.name);
	fprintf(file, "%s\t", data.gender);
	fprintf(file, "%d\t", data.age);
	fprintf(file, "%d\t", data.height);
	fprintf(file, "%d", data.weight);
	fclose(file);
	printf("Record been added.");
}
void readFile(){
	FILE *file;
	struct yourData temp[10];
	int size = 20, i = 0;
	char buffer[size]; //any size of buffer, not too small
	
	file = fopen("Your Data.txt","r");
	if(file == NULL)
		printf("\aUnable to find the file!");
	printf("\n ---------- All Records ----------");
	printf("\nName\t Gender\t Age\t Height\t Weight\n");
	while( fgets(buffer, size, file) != NULL){
		//get data from file
		fscanf(file, "%s", &temp[i].name);
		fscanf(file, "%s", &temp[i].gender);
		fscanf(file, "%d", &temp[i].age);
		fscanf(file, "%lf", &temp[i].height);
		fscanf(file, "%lf", &temp[i].weight);
		//printing out
		printf("%s\t", temp[i].name);
		printf(" %s\t", temp[i].gender);
		printf(" %d\t", temp[i].age);
		printf(" %.2f\t", temp[i].height);
		printf(" %.2f\n", temp[i].weight);
	}
	fclose(file);
}

int main(){
	int option;
	
	printf("Combine of File I/O.");
	printf("\n1. Write new file.");
	printf("\n2. Read the file.");
	printf("\n3. Add data to the file.");
	printf("\nEnter number from the list here: ");
	scanf("%d", &option);
	printf("\n");
	
	switch(option){
		case 1:
			writeFile();
			break;
		case 2:
			readFile();
			break;
		case 3:
			addDataFile();
			break;
		default:
			printf("\a\tOut of the list ...");
			break;
	}
	
	return 0;
}
