#include<stdio.h>/*sort change file*/
#include<string.h>
#include<stdlib.h>
#include"main1.h"
#define MAX 500

int main() {
	int choice, smenu, amenu, edit;
	char sp[100], ap[100], fn[100];
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"\t\tSTUDENT DATA MANAGEMENT\n"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
		"1. STUDENT\n"
		"2.ADMINISTRATOR\n"
		"Enter your choice\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1: {/* student login*/
				printf("Enter password\n");
				scanf("%s", sp);
				if(strcmp(sp, "student") == 0)
					smenu = studentmenu();
				
				else
					printf("Invalid password. Try again\n");
				switch(smenu) {
					case 1: {/*view scores*/
						viewscore();
						break;
					}
					case 2: {/*view result*/
						viewresult();
						break;
					}
					default: {
						printf("Invalid choice\n");
						break;
					}
				}
				break;
			}




/*Just to keep track
*/







			case 2: {/*admin login*/
				printf("Enter password\n");
				scanf("%s", ap);
				if(strcmp(ap, "admin") == 0)
					amenu = adminmenu();
				else
					printf("Invalid password. Try again\n");
				printf("Enter filename\n");
				scanf("%s", fn);
				switch(amenu) {
					case 1: {/*Add record*/
						addrecord(fn);
						break;
					}
					case 2: {/*Edit record*/
						printf("Edit student details\n"
							"1. Edit first name\n"
							"2. Edit last name\n"
							"3. Edit date of birth\n"
							"4. Edit contact number\n"
							"5. Edit address\n"
							"6. Edit scores\n"
							"Enter your choice\n");
						scanf("%d", &edit);
						switch(edit) {
							case 1:{/*Edit first name*/
								editfirstname(
						break;
					}
					case 3: {/*Delete record*/
						break;
					}
					case 4: {/*View individual record*/
						break;
					}
					case 5: {/*View all records*/
						break;
					}
					case 6: {/*Sort records*/
						break;
					}
					default: {
						printf("Invalid choice. Try again\n");
						return 0;
					}
				}
				break;
			}
			default: {
				printf("Invalid choice. Try again\n");
				return 0;
			}
		}
	return 0;
}
