/*****************************************************************************
 * Copyright (C) Golda George goldageorge.1995@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"

void readline(char *str, int n) {
	int i = 0;
	char c;
	while(i < (n - 1) && ((c = getchar()) != '\n') && (c != EOF)) {
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return;
}

void deleterec(int rno, char *fn) {
	FILE * fp, *fp2;
	student s;
	int flag = 0, name;
	fp = fopen(fn, "a+");
	fp2 = fopen("New", "a+");
	if(fp2 == NULL) {
		printf("Operation failed\n");
		return;
	}
	if (fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		if(rno == s.rno) {
			flag = 1;
			continue;
		}
		fwrite(&s, sizeof(s), 1, fp2);
	}
	remove(fn);
	name = rename("New", fn);
	fclose(fp);
	printf("Record deleted\n");
	return;
}

void sviewscore(int rno, char *fn) {
	FILE *fp;
	student s;
	fp = fopen(fn, "r");
	float net;
	char grade[3];
	if(fp == NULL)
		printf("Operation failed\n");
	while(fread(&s, sizeof(s), 1, fp) == 1)
		if(rno == s.rno) {
			net = (((s.sub1 + s.sub2 + s.sub3 + s.sub4 + s.sub5) / 500.0) * 100.0);
			if(net <= 100 && net >= 90)
				strcpy(grade, "AA");
			else if(net < 90 && net >= 80)
				strcpy(grade, "AB");
			else if(net < 80 && net >= 70)
				strcpy(grade, "BB");
			else if(net < 70 && net >= 60)
				strcpy(grade, "BC");
			else if( net < 60 && net >= 50)
				strcpy(grade, "CC");
			else if(net < 50 && net >= 40)
				strcpy(grade, "CD");
			else if(net < 40 && net >= 30)
				strcpy(grade, "DD");
			else
				strcpy(grade, "FF");
			printf("SHOWING SCORES\nSub 1 : %d\n"
				"Sub 2 : %d\n"
				"Sub 3 : %d\n"
				"Sub 4 : %d\n"
				"Sub 5 : %d\n"
				"Percentage score : %f\n"
				"Grade : %s\n", s.sub1, s.sub2, s.sub3, s.sub4, s.sub5, net, grade);
			if(net >= 30)
				printf("PASSED\n");
		}
	return;
}

/*void viewrecord(char *fn) {
	FILE *fp;
	student s;
	int rno;
	float net;
	char *grade;
	fp = fopen(fn, "r");
	if(fp == NULL)
		printf("Operation failed\n");
	printf("Enter roll number:");
	scanf("%d", &rno);
	while(fread(&s, sizeof(s), 1, fp) == 1)
		if(rno = s.rno) {
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
			printf("Roll number: %d"
				"First name : %s"
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
				"Grade : %s", s.rno, s.fname, s.lname, s.dob, s.mob, s.yob, s.moa, s.yoa, s.ward, s.district, s.state, s.pin, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5, net, grade);
		}
	fclose(fp);
	return;
}	
*/		
void viewall(char *fn) {
	FILE *fp;
	student s;
	float net;
	char *grade;
	fp = fopen(fn, "r");
	if(fp == NULL)
		printf("Operation failed\n");
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		net = ((s.sub1 + s.sub2 + s.sub3 + s.sub4 + s.sub5) / 500.0) * 100.0;
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
			"Grade : %s", s.fname, s.lname, s.dob, s.mob, s.yob, s.moa, s.yoa, s.address, s.district, s.state, s.pin, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5, net, grade);
	}
	fclose(fp);
	return;
}
	
void viewrecord(int rno, char *fn) {
	FILE *fp;
	student s;
	float net;
	char grade[3];
	fp = fopen(fn, "r");
	if(fp == NULL)
		printf("operation failed\n");
	if(rno == 0) {
		printf("No such student record\n");
		return;
	}
	while(fread(&s, sizeof(s), 1, fp) == 1)
		if(rno == s.rno) {
			net = ((s.sub1 + s.sub2 + s.sub3 + s.sub4 + s.sub5) / 500.0) * 100.0;
			if(net <= 100 && net >= 90)
				strcpy(grade, "AA");
			else if(net < 90 && net >= 80)
				strcpy(grade, "AB");
			else if(net < 80 && net >= 70)
				strcpy(grade, "BB");
			else if(net < 70 && net >= 60)
				strcpy(grade, "BC");
			else if( net < 60 && net >= 50)
				strcpy(grade, "CC");
			else if(net < 50 && net >= 40)
				strcpy(grade, "CD");
			else if(net < 40 && net >= 30)
				strcpy(grade, "DD");
			else if(net < 30)
				strcpy(grade, "FF");
			printf("First name : %s\n"
				"Last name : %s\n"
				"DoB	   : %d/%d/%d\n"
				"Admitted in: %d/%d\n"
				"Address   : %s, %s, %s, %s\n"
				"Scores in individual subjects-\n"
				"Sub 1 : %d\n"
				"Sub 2 : %d\n"
				"Sub 3 : %d\n"
				"Sub 4 : %d\n"
				"Sub 5 : %d\n"
				"Percentage score : %f\n"
				"Grade : %s\n", s.fname, s.lname, s.dob, s.mob, s.yob, s.moa, s.yoa, s.address, s.district, s.state, s.pin, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5, net, grade);
		}
	fclose(fp);
	return;
}

void editscores(int rno, char *fn) {/*use fseek and fputs*/
	FILE *fp;
	student s;
	int sub1, sub2, sub3, sub4, sub5;
	int count = 0, flag = 0;
	fp = fopen(fn, "a+");
	if(fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	printf("Enter new scores\nSub 1 :");
	scanf("%d", &sub1);
	printf("Sub 2 :");
	scanf("%d", &sub2);
	printf("Sub 3 :");
	scanf("%d", &sub3);
	printf("Sub 4 :");
	scanf("%d", &sub4);
	printf("Sub 5 :");
	scanf("%d", &sub5);
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		count++;
		if(rno == s.rno) {
			flag = 1;
			s.sub1 = sub1;
			s.sub2 = sub2;
			s.sub3 = sub3;
			s.sub4 = sub4;
			s.sub5 = sub5;
			break;
		}
	}
	if(flag == 0)
		printf("This roll number does not exist\n");
	else {
		fseek(fp, (count - 1) * sizeof(s), 0);
		//fprintf(fp, "%s", name);
		fseek(fp, 0, 0);
		printf("Roll number :%d\nSub 1 : %d\n"
			"Sub 2 : %d\n"
			"Sub 3 : %d\n"
			"Sub 4 : %d\n"
			"Sub 5 : %d\n", s.rno, s.sub1, s.sub2, s.sub3, s.sub4, s.sub5);
	}
	fclose(fp);
	return;
	//while(fread(&s, sizeof(s), 1, 
}
void editaddress(int rno, char *fn) {/*use fseek and fputs*/
	FILE *fp;
	student s;
	char address[MAX], district[MAX], state[MAX], pin[MAX], a, b, c;
	int count = 0, flag = 0;
	fp = fopen(fn, "a+");
	if(fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	printf("Enter new address\n");
	a = getchar();
	readline(address, MAX);
	printf("Enter new district\n");
	b = getchar();
	readline(district, 60); 
	printf("Enter new state\n");
	c = getchar();
	readline(state, 60);
	printf("Enter new pin\n");
	scanf("%s", pin);
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		count++;
		if(rno == s.rno) {
			flag = 1;
			strcpy(s.address, address);
			strcpy(s.district, district);
			strcpy(s.state, state);
			strcpy(s.pin, pin);
			break;
		}
	}
	if(flag == 0)
		printf("This roll number does not exist\n");
	else {
		fseek(fp, (count - 1) * sizeof(s), 0);
		//fprintf(fp, "%s", name);
		fseek(fp, 0, 0);
		printf("Roll number :%d\n"
			"Edited address :%s, %s, %s-%s\n", s.rno, s.address, s.district, s.state, s.pin);
	}
	fclose(fp);
	return;
	//while(fread(&s, sizeof(s), 1, 
}


void editcontact(int rno, char *fn) {/*use fseek and fputs*/
	FILE *fp;
	student s;
	char contact[11];
	int count = 0, flag = 0;
	fp = fopen(fn, "a+" );
	if(fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	printf("Enter new contact number\n");
	scanf("%s", contact);
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		count++;
		if(rno == s.rno) {
			flag = 1;
			strcpy(s.contact, contact);
			break;
		}
	}
	if(flag == 0)
		printf("This roll number does not exist\n");
	else {
		fseek(fp, (count - 1) * sizeof(s), 0);
		//fprintf(fp, "%s", name);
		fseek(fp, 0, 0);
		printf("Roll number :%d\n"
			"Edited contact number :%s\n", s.rno, s.contact);
	}
	fclose(fp);
	return;
	//while(fread(&s, sizeof(s), 1, 
}
void editdob(int rno, char *fn) {/*use fseek and fputs*/
	FILE *fp;
	student s;
	int dob, mob, yob;
	int count = 0, flag = 0;
	fp = fopen(fn, "a+");
	if(fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	printf("Enter new date, month and year of birth(separated by spaces)\n");
	scanf("%d %d %d", &dob, &mob, &yob);
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		count++;
		if(rno == s.rno) {
			flag = 1;
			s.dob = dob;
			s.mob = mob;
			s.yob = yob;
			break;
		}
	}
	if(flag == 0)
		printf("This roll number does not exist\n");
	else {
		fseek(fp, (count - 1) * sizeof(s), 0);
		//fprintf(fp, "%s", name);
		fseek(fp, 0, 0);
		printf("Roll number :%d\n"
			"Edited date of birth :%d/%d/%d\n", s.rno, s.dob, s.mob, s.yob);
	}
	fclose(fp);
	return;
	//while(fread(&s, sizeof(s), 1, 
}

void editlastname(int rno, char *fn) {/*use fseek and fputs*/
	FILE *fp;
	student s;
	char name[MAX], c;
	int count = 0, flag = 0;
	fp = fopen(fn, "a+");
	if(fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	printf("Enter new last name\n");
	c = getchar();
	readline(name, 60);
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
		printf("Roll number :%d\n"
			"Edited last name :%s\n", s.rno, s.lname);
	}
	fclose(fp);
	return;
	//while(fread(&s, sizeof(s), 1, 
}

void editfirstname(int rno, char *fn) {/*use fseek and fputs*/
	FILE *fp;
	student s;
	char name[MAX], c;
	int count = 0, flag = 0;
	fp = fopen(fn, "a+");
	if(fp == NULL) {
		printf("Operation failed\n");
		return;
	}
	printf("Enter new first name\n");
	c = getchar();
	readline(name, 60);
	while(fread(&s, sizeof(s), 1, fp) == 1) {
		//count++;
		if(rno == s.rno) {
			strcpy(s.fname, name);
			printf("Roll number : %d\n"
				"Edited first name :%s\n", s.rno, s.fname);
		}
		else
			printf("This roll number does not exist\n");
	}
	fclose(fp);
	return;
}
	
			/*flag = 1;
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
	return;
	//while(fread(&s, sizeof(s), 1, 
}*/

int addrecord(char *fn) {
	FILE *fp;
	student s;
	int rno;
	char c;
	fp = fopen(fn, "a");
	if(fp == NULL) {
		printf("File could not be opened. Try again\n");
		return 0;
	}
	roll:
	printf("Enter roll number\n");
	scanf("%d", &rno);
	if(rno == 0) {
			printf("Invalid roll number. Try again\n");
			fclose(fp);
			goto roll;
	}
	while(fread(&s, sizeof(s), 1, fp) == 1)
		if(s.rno == rno) {
		/*fscanf(fp, "%d", &check);
		if(check == rno) {*/
			printf("This record already exists\n");
			fclose(fp);
			goto roll;
		//}
		}
	s.rno = rno;
	printf("Enter student details\nFirst name :");
	c = getchar();
	readline(s.fname, 60);
	printf("Last name :");
	c = getchar();
	readline(s.lname, 60);
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
  	printf("Address :");
	c = getchar();
	readline(s.address, MAX);
	printf("District :");
	c = getchar();
	readline(s.district, 60);
	printf("State :");
	c = getchar();
	readline(s.state, 60);
	printf("PIN code :");
	scanf("%s", s.pin);
	printf("Enter contact number :");
	scanf("%s", s.contact);
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
	fwrite(&s, sizeof(s), 1, fp);
	fclose(fp);
	printf("Record added\n");
	return 1;
}


int adminmenu() {
	int choice;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"\t\tWELCOME ADMINISTRATOR\n"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"1. Add record\n"
		"2. View record\n"
		"3. Edit record\n"
		"4. Delete record\n"
		"5. Go to main menu\n"
		"6. Exit\n"
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
int startmenu() {
	int choice;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
			"\t\tSTUDENT DATA MANAGEMENT\n"
			"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
			"1. STUDENT\n"
			"2.ADMINISTRATOR\n"
			"3.EXIT\n"
			"Enter your choice\n");
	scanf("%d", &choice);
	return choice;
}		


