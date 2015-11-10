/*Function prototype and structure declaration*/
#define MAX 500
typedef struct student {
	char fname[MAX], lname[MAX], ward[MAX], district[MAX], state[MAX], contact[11], pin[7];
	int rno, dob, mob, yob, moa, yoa;
	int sub1, sub2, sub3, sub4, sub5;
}student;

void sviewscore(int rno, char *fn);
void viewall(char *fn);
void viewrecord(int rno, char *fn);
void editlastname(int rno, char *fn);
void editfirstname(int rno, char *fn);
void addrecord(char *fn);
int adminmenu();
int studentmenu();
