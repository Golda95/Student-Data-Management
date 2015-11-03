#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main1.h"
void addrecord(char *fn) {
	FILE *fp;
	student s;
	int rno;
	fp = fopen(fn, "a");
	if(fp == NULL)
		printf("Operation failed\n");
	printf("Enter roll number\n");
	scanf("%d", &rno);
	if(rno == 0) {
			printf("Invalid roll number\n");
			fclose(fp);
			return;
		}
	while(fread(&s, sizeof(s), 1, fp) == 1)
		if(rno == s.rno) {
			printf("This record already exists\n");
			fclose(fp);
			return;
		}
	s.rno = rno;
	printf("Enter student details\nFirst name :");
	scanf("%s", s.fname);
	printf("Last name :");
	scanf("%s", s.lname);
	printf("Date of birth\n dd :");
	scanf("%d", &s.dob);
	printf("mm :");
	scanf("%d", &s.mob);	
	printf("yy :");
  	scanf("%d", &s.yob);
	printf("Month of admission :");
	scanf("%d", &s.madmission);
	printf("Year :");
	scanf("%d", &s.yadmission);
  	printf("Address details(ward name) :");
	scanf("%s", s.ward);
	printf("City :");
	scanf("%s", s.city);
	printf("State :");
	scanf("%s", s.state);
	printf("PIN code :");
	scanf("%s", s.pin);
	printf("Enter scores in individual subjects\n"
	      "Sub 1 :");
	scanf("%d", &s.sub1);
	printf("Sub 2 :");
	scanf("%d", &s.sub2);
	printf("Sub 3 :");
	scanf("%d", &s.sub3);
	printf("Sub 4 :");
	scanf("%d", &s.sub4);
	printf("Sub 5 :");
	scanf("%d", &s.sub5);
	fprintf(fp, "%d  %s %s\t%d/%d/%d\t%d/%d\t%s\t%s, %s, %s- %s\t\t\t%d\t%d\t%d\t%d\t%d\n", s.rno, s.fname, s.lname, s.dob, s.mob, s.yob, s.madmission, s.yadmission, s.contact, s.locality, s.city, s.pin, s.state, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5);
	fclose(fp);
	printf("Record added\n");
	return;
}

void viewscore() {
	printf("Checking viewscore\n");
}

void viewresult() {
	printf("Checking viewresult\n");
}

int adminmenu() {
	int choice;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"\t\tWELCOME ADMINISTRATOR\n"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"1. Add record\n"
		"2. Edit record\n"
		"3. Delete record\n"
		"4. View individual record\n"
		"5. View all records\n"
		"6. Sort records\n"
		"Enter your choice\n");
	scanf("%d", &choice);
	return choice;

		
}
				
/*void adminlogin() {
	char p[100];
	printf("Enter password\n");
		scanf("%s", p);
		if(strcmp(p, "admin") == 0)
			adminmenu();
		else {
			printf("Invalid password. Try again\n");
			return;
		}
	}*/

int studentmenu() {
	int choice;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"\t\tWELCOME STUDENT\n"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"1. View scores\n"
		"2. View percentage\n"
		"Enter your choice\n");
	scanf("%d", &choice);
	return choice;
}
/*int studentlogin(char *sp) {
	/*char p[100];
	/printf("Enter password\n");
		scanf("%s", p);*/
		/*if(strcmp(sp, "student") == 0)
			return 1;
		else
			return 0;
	}*/
