#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main1.h"

void sviewscore(int rno, char *fn) {
	FILE *fp;
	student s;
	fp = fopen(fn, "r");
	float net;
	char *grade;
	if(fp == NULL)
		printf("Operation failed\n");
	while(fread(&s, sizeof(s), 1, fp) == 1)
		if(rno == s.rno) {
			net = ((s.sub1 + s.sub2 + s.sub3 + s.sub4 + s.sub5) / 5) * 100;
			if(net <= 100 && net >= 90)
				grade = "AA";
			else if(net < 90 && net >= 80)
				grade = "AB";
			else if(net < 80 && net >= 70)
				grade = "BB";
			else if(net < 70 && net >= 60)
				grade = "BC";
			else if( net < 60 && net >= 50)
				grade = "CC";
			else if(net < 50 && net >= 40)
				grade = "CD";
			else if(net < 40 && net >= 30)
				grade = "DD";
			else
				grade = "FF";
			printf("Sub 1 : %d"
				"Sub 2 : %d"
				"Sub 3 : %d"
				"Sub 4 : %d"
				"Sub 5 : %d"
				"Percentage score : %f"
				"Grade : %s", s.sub1, s.sub2, s.sub3, s.sub4, s.sub5, net, grade);
			if(net >= 30)
				printf("PASSED\n");
		}
}
void viewall(char *fn) {
	FILE *fp;
	student s;
	float net;
	char *grade;
	fp = fopen(fn, "r");
	if(fp == NULL)
		printf("Operation failed\n");
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		net = ((s.sub1 + s.sub2 + s.sub3 + s.sub4 + s.sub5) / 5) * 100;
		if(net <= 100 && net >= 90)
			grade = "AA";
		else if(net < 90 && net >= 80)
			grade = "AB";
		else if(net < 80 && net >= 70)
			grade = "BB";
		else if(net < 70 && net >= 60)
			grade = "BC";
		else if( net < 60 && net >= 50)
			grade = "CC";
		else if(net < 50 && net >= 40)
			grade = "CD";
		else if(net < 40 && net >= 30)
			grade = "DD";
		else
			grade = "FF";
		printf("First name : %s"
			"Last name : %s	"
			"DoB	   : %d/%d/%d"
			"Admitted in: %d/%d"
			"Address   : %s, %s, %s, %s"
			"Scores in individual subjects-"
			"Sub 1 : %d"
			"Sub 2 : %d"
			"Sub 3 : %d"
			"Sub 4 : %d"
			"Sub 5 : %d"
			"Percentage score : %f"
			"Grade : %s", s.fname, s.lname, s.dob, s.mob, s.yob, s.moa, s.yoa, s.ward, s.district, s.state, s.pin, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5, net, grade);
	}
	fclose(fp);
}
	
void viewrecord(int rno, char *fn) {
	FILE *fp;
	student s;
	float net;
	char *grade;
	fp = fopen(fn, "r");
	if(fp == NULL)
		printf("operation failed\n");
	while(fread(&s, sizeof(s), 1, fp) == 1)
		if(rno == s.rno) {
			net = ((s.sub1 + s.sub2 + s.sub3 + s.sub4 + s.sub5) / 5) * 100;
			if(net <= 100 && net >= 90)
				grade = "AA";
			else if(net < 90 && net >= 80)
				grade = "AB";
			else if(net < 80 && net >= 70)
				grade = "BB";
			else if(net < 70 && net >= 60)
				grade = "BC";
			else if( net < 60 && net >= 50)
				grade = "CC";
			else if(net < 50 && net >= 40)
				grade = "CD";
			else if(net < 40 && net >= 30)
				grade = "DD";
			else
				grade = "FF";
			printf("First name : %s"
				"Last name : %s	"
				"DoB	   : %d/%d/%d"
				"Admitted in: %d/%d"
				"Address   : %s, %s, %s, %s"
				"Scores in individual subjects-"
				"Sub 1 : %d"
				"Sub 2 : %d"
				"Sub 3 : %d"
				"Sub 4 : %d"
				"Sub 5 : %d"
				"Percentage score : %f"
				"Grade : %s", s.fname, s.lname, s.dob, s.mob, s.yob, s.moa, s.yoa, s.ward, s.district, s.state, s.pin, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5, net, grade);
		}
	fclose(fp);
}

void editlastname(int rno, char *fn) {/*use fseek and fputs*/
	FILE *fp;
	student s;
	char *name;
	int count = 0, flag = 0;
	fp = fopen(fn, "r+");
	if(fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	printf("Enter new last name\n");
	scanf("%s", name);
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		count++;
		if(rno == s.rno) {
			flag = 1;
			strcpy(s.lname, name);
			break;
		}
	}
	if(flag == 0)
		printf("This roll number does not exist\n");
	else {
		fseek(fp, (count - 1) * sizeof(s), 0);
		//fprintf(fp, "%s", name);
		fseek(fp, 0, 0);
		printf("%s : checking\n", s.lname);
	}
	fclose(fp);
	//while(fread(&s, sizeof(s), 1, 
}

void editfirstname(int rno, char *fn) {/*use fseek and fputs*/
	FILE *fp;
	student s;
	char *name;
	int count = 0, flag = 0;
	fp = fopen(fn, "w+");
	if(fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	printf("Enter new first name\n");
	scanf("%s", name);
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		count++;
		if(rno == s.rno) {
			flag = 1;
			strcpy(s.fname, name);
			break;
		}
	}
	if(flag == 0)
		printf("This roll number does not exist\n");
	else {
		fseek(fp, (count - 1) * sizeof(s), 0);
		fprintf(fp, name, s.fname);
		fseek(fp, 0, 0);
		printf("%s : checking\n", s.fname);
	}
	fclose(fp);
	//while(fread(&s, sizeof(s), 1, 
}

void addrecord(char *fn) {
	FILE *fp;
	student s;
	int rno, check;
	fp = fopen(fn, "a");
	if(fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	printf("Enter roll number\n");
	scanf("%d", &rno);
	if(rno == 0) {
			printf("Invalid roll number\n");
			fclose(fp);
			return;
		}
	while(fread(&s, sizeof(s), 1, fp) == 1)
		if(s.rno == rno) {
		/*fscanf(fp, "%d", &check);
		if(check == rno) {*/
			printf("This record already exists\n");
			fclose(fp);
			return;
		//}
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
	scanf("%d", &s.moa);
	printf("Year :");
	scanf("%d", &s.yoa);
  	printf("Address details(ward name) :");
	scanf("%s", s.ward);
	printf("City :");
	scanf("%s", s.district);
	printf("State(Abbrev) :");
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
	fprintf(fp, "%d  %s %s\t%d/%d/%d\t%d/%d\t%s\t%s, %s, %s- %s\t\t\t%d\t%d\t%d\t%d\t%d\n", s.rno, s.fname, s.lname, s.dob, s.mob, s.yob, s.moa, s.yoa, s.contact, s.ward, s.district, s.pin, s.state, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5);
	fclose(fp);
	printf("Record added\n");
	return;
}

/*void viewscore() {
	printf("Checking viewscore\n");
}

void viewresult() {
	printf("Checking viewresult\n");
}*/

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
