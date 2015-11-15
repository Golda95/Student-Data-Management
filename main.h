/*Function prototype and structure declaration*/
#define MAX 500
typedef struct student {
	char fname[MAX], lname[MAX], address[MAX], district[MAX], state[MAX], contact[11], pin[7];
	int rno, dob, mob, yob, moa, yoa;
	int sub1, sub2, sub3, sub4, sub5;
}student;

void readline(char *str, int n);
void deleterec(int rno, char *fn);
void sviewscore(int rno, char *fn);
void viewall(char *fn);
void viewrecord(int rno, char *fn);
void editscores(int rno, char *fn);
void editaddress(int rno, char *fn);
void editcontact(int rno, char *fn);
void editdob(int rno, char *fn);
void editlastname(int rno, char *fn);
void editfirstname(int rno, char *fn);
int addrecord(char *fn);
int adminmenu();
int startmenu();
