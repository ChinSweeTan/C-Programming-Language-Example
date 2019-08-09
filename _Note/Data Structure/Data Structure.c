#include<stdio.h>
#include<string.h>

void printInformation();
struct customer{
	char name[20];
	int age;
	char gender[6];
	double height;
	double weight;
};

int main(){
	struct customer yourInfo;
	//2 ways to preset the data for structure
	//1. declaration first then set its data
	//2. declaration and set data at the same time
	struct customer presetInfo1;
	struct customer presetInfo2 = {"lee", 12, "female", 160.05, 45.30};
	
	strcpy(presetInfo1.name, "Jack");
	strcpy(presetInfo1.gender, "Male");
	presetInfo1.age = 20;
	presetInfo1.height = 170;
	presetInfo1.weight = 50;
	
	printf("Enter name: ");
	scanf("%s", &yourInfo.name);
	printf("Enter age: ");
	scanf("%d", &yourInfo.age);
	printf("Enter gender: ");
	scanf("%s", &yourInfo.gender);
	printf("Enter height: ");
	scanf("%lf", &yourInfo.height);
	printf("Enter weight: ");
	scanf("%lf", &yourInfo.weight);
	
	printf("\n ----- Your Information ----- ");
	printInformation(yourInfo);
	printf("\n ----- Preset Information ----- ");
	printInformation(presetInfo1);
	printInformation(presetInfo2);
}

void printInformation(struct customer data){
	printf("\nName: %s", data.name);
	printf("\nAge: %d", data.age);
	printf("\nGender: %s", data.gender);
	printf("\nHeight: %.2f", data.height);
	printf("\nWeight: %.2f\n", data.weight);
}
