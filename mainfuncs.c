#include<stdio.h>
#include<stdlib.h>
#include"main.c"
void addstudent() {
				student s;
				FILE *fp;
				double MIS;
				fp = fopen(argv[1], "a");
				if(fp == NULL) {
					printf("	Operation failed. Select choice again.\n");
					return;
				}
	/* To check cases of INVALID IDs */
	printf("Enter student MIS\n");
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
	printf("Enter first name:");
	scanf("%s", s.fname);
	printf("\nenter last name:");
	scanf("%s", s.lname);
	printf("\nenter year/class:");
	scanf("%s", s.year);
	printf("\nEnter department :");
	scanf("%s", s.dept);
	printf("Enter scores in subjects1, 2, 3, 4 and 5:\n");
	scanf("%d %d %d %d %d", s.sub1, s.sub2, s.sub3, s.sub4, s.sub5);
	fprintf(fp, "%lf\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\t%d", s.MIS, s.fname, s.lname, s.year, s.dept, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5);

	}

void editname(double MIS, char *fname, char *lname){/*edit name*/
		//FILE *fp;
		//student s;
		int count = 0, flag = 0;
		/*fp = fopen(argv[1], "r+");
		if(fp == NULL) {
			printf("Operation failed. Select your choice again\n");
			return;
		}*/	
		while(fread(&s, sizeof(s), 1, fp) == 1) {
			count++;
			if(MIS == s.MIS) {
				flag = 1;
				strcpy(s.fname, fname);
				strcpy(s.lname, lname);
				break;
			}
		}
		if(flag == 0)
			printf("No such record\n");
		else {
			fseek(fp, (count- 1) * sizeof(s), 0);
			fprintf(fp, "%s\t%s\t%lf\t%s\t%s\t%d\t%d\t%d\t%d\t%d", s.fname, s.lname, s.MIS, s.year, s.dept, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5);
			fseek(fp, 0, 0);
			printf("\t MIS: %lf\n"
				"\tFirst Name : %s\n"
				"\tLast Name : %s\n", s.MIS, s.fname, s.lname);

			printf("record edited\n");
		}
}

void edityear(double MIS, char *year){/*edit name*/
		//FILE *fp;
		//student s;
		int count = 0, flag = 0;
		/*fp = fopen(argv[1], "r+");
		if(fp == NULL) {
			printf("Operation failed. Select your choice again\n");
			return;
		}*/	
		while(fread(&s, sizeof(s), 1, fp) == 1) {
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
			fprintf(fp, "%s\t%s", fname
			fseek(fp, 0, 0);
			printf("\t MIS: %lf\n"
				"\tFirst Name : %s\n"
				"\tLast Name : %s\n", s.MIS, s.fname, s.lname);

			printf("record edited\n");
		}
}

/* Displays a list of all registered students */
void viewstudents() {
	FILE *fp;
	student s;
	int flag = 0;
	fp = fopen("student", "r");
	if(ptr == NULL) {
		printf("	No student has registered yet.\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, ptr) == 1) {
		flag = 1;
		printf("	MIS		: %lf\n"\
			"	First Name	: %s\n", s.MIS, s.fname);
	}
	if(flag == 0)
		printf("	No student has registered yet.\n");
	fclose(ptr);
}
































//#include"main.h"
/*void addrec(char *argv[1]) {
	‪student s;/*not using ptr here*/
	/*int n;
	FILE *fp = open(argv[1], "a");
	if(fp == NULL)
            printf( "Could not open the file\n" );
	printf("Enter the number of entries\n");
	scanf("%d", &n);
	while(n) {
		printf("Details of entry number %d\n", n);
		printf("Enter first name:");
		scanf("%s", s.fname);
		printf("\nEnter last name:");
		scanf("%s", s.lname);
		printf("\nEnter MIS number:");
		scanf("%lf", &s.MIS);
		printf("\nEnter FY/SY/TY/BTech:");
		scanf("%s", s.year);
		printf("\nEnter department name:");
		scanf("%s", s.dept);
		printf("\nEnter scores in 5 subjects:");
		scanf("%d %d %d %d %d", &s.sub1, &s.sub2, &s.sub3, &s.sub4, &s.sub5);
		/*printf("Enter first name, last name, MIS, Year/class, department name, And scores in 5 subjects\n");
		scanf("%s %s %lf %s %s %d %d %d %d %d", &s.fname, &s.lname, &s.MIS, &s.year, &s.dept, &s.sub1, &s.sub2, &s.sub3, &s.sub4, &s.sub5);*/
		/*n--;
		fprintf(fp, "%s\t%s\t%lf\t%s\t%s\t%d\t%d\t%d\t%d\t%d");
	}
}*/




