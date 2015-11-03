/*Function prototype and structure declaration*/
#define MAX 500
typedef struct student {
	char fname[MAX], lname[MAX], ward[MAX], city[MAX], state[MAX], contact[11], pin[7];
	int rno, dob, mob, yob, madmission, yadmission;
	int sub1, sub2, sub3, sub4, sub5;
}student;

void viewscore();
void viewresult();
//int studentlogin(char *sp);
int studentmenu();
//void adminlogin();
int adminmenu();
void addrecord(char *fn);
