#include<stdio.h>
#include<stdlib.h>
#include"main.h"


int usermenu() {
	int choice;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"\t\tSTUDENT DATA MANAGEMENT\n"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"1. STUDENT\n"
		"2.ADMINISTRATOR\n");
		scanf("%d", &choice);
		return choice;
}
int printmenu(char *argv[1]) {
	int choice;
	printf("1.\tAdd\tRecord\n"
		"2.\tEdit\tRecord\n"
		"3.\tDelete\tRecord\n"
		"4.\tView\tIndividual Record\n"
		"5.\tView\tAll Records\n"
		"6.\tExit\n");
	scanf("%d", &choice);
	switch(choice) {
		case 1:{/*Add record*/

			void addstudent();/* {
				student s;
				FILE *fp;
				double MIS;
				fp = fopen(argv[1], "a");
				if(fp == NULL) {
					printf("	Operation failed. Select choice again.\n");
					return;
				}
	/* To check cases of INVALID IDs */
	/*printf("Enter student MIS\n");
	scanf("%lf", &MIS);
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		if(MIS== s.MIS) {
			printf("	This ID already exists\n");
			fclose(fp);
			return;
		}
		if(MIS == 0) {
			printf("	INVALID ID\n");
			fclose(fp);
			return;
		}
	}
	}*/
	break;
	case 2:{/*Edit record*/
		int choice;
		FILE *fp;
		student s;
		double MIS;
		char fname[50], lname[50];
		printf("Enter MIS\n");
		scanf("%lf", &MIS);
		printf("1.\tEdit name\n"
			"2.\tEdit year/class\n"
			"3.\tEdit department\n"
			"4.\tEdit scores\n"
			"Enter your choice\n");
		scanf("%d", &choice);
		fp = fopen(argv[1], "r+");
		if(fp == NULL) {
			printf("Operation failed. Select your choice again\n");
			return;
		}	
		switch(choice) {
			case 1:{/*edit name*/
				printf("Enter new first name and last name\n");
				scanf("%s %s", fname, lname);
				void editname(double MIS,char *fname, char *lname);/*{/*edit name*/
		//FILE *fp;
		//student s;
		/*int count = 0, flag = 0;
		/*fp = fopen(argv[1], "r+");
		if(fp == NULL) {
			printf("Operation failed. Select your choice again\n");
			return;
		}*/	
		/*while(fread(&s, sizeof(s), 1, fp) == 1) {
			count++;
			if(MIS == s.MIS) {
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			printf("No such record\n");
		else {
			fseek(fp, (count- 1) * sizeof(s), 0);
			fprintf(fp, "
			fseek(fp, 0, 0);
			printf("\t MIS: %lf\n"
				"\tFirst Name : %s\n"
				"\tLast Name : %s\n", s.MIS, s.fname, s.lname);

			printf("record edited\n");
		}
	//fclose(fp);*/
	break;
	}
			case 2:{/*edit year/class*/
				char year[10];
				printf("Enter year/class\n");
				scanf("%s", year);
				void edityear(double MIS, char *year);
				break;}
			case 3:{/*edit dept*/
				break;}

			case 4:{/*edit scores*/
				break;}
	break;/*edit ends here*/
}

	case 3:{/*View all records*/
		void viewstudents();
		break;}




	
	default:{
		printf("Invalid entry\n");
		break;}
	}
	return 0;
}
	//printf("Enter first name, last name, year/class, department and scores in subject 1, subject 2, subject 3, subject 4, subject 5\n");
	//scanf("%s %s %s %s %d %d %d %d %d", 
	/*fclose(ptr);
	strcpy(s.name, name);
	strcpy(s.contact, contact);
	s.id = id;
	ptr = fopen("student", "a");
	if(ptr == NULL) {
		printf("	Operation failed. Try again.\n");
		return;
	}
	fwrite(&s, sizeof(s), 1, ptr);
	printf("\n	ID		: %u\n"\
		"	Name		: %s\n"\
		"	Contact		: %s\n\n", s.id, s.name, s.contact);
		printf("		Student Successfully Registered.\n");
	fclose(ptr);*/

			
int login() {
	char pwd[20];
	printf("\t\t1.LOGIN\n"
		"Enter password:\n");
	scanf("%s", pwd);
	if(strcmp(pwd, "student"))
		return 1;
	else
		return 0;
}
int main(int argc, char *argv[]){
	int choice, log, i;
	choice = usermenu();
	if(choice == 2)
		log = login();
	else if(login)
		i = printmenu(argv[1]);
	return 0;
}
/*1.\tAdd\tRecord\n"
		"2.\tExit\n"
		"Select your choice\n");
	scanf("%d", &choice);*/
	/*switch(choice) {
		case 1:{
			void addrec(char *argv[1]);
			break;
		}
		case 2:{/*Exit Program*/
			/*return 0;
		}
		default:{
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;
}*/
