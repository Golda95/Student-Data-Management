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
#include<stdio.h>/*sort change file*/
#include<string.h>
#include<stdlib.h>
#include"main.h"
#define MAX 500

int main() {
	int choice, smenu, amenu, edit, rno, addrec, del;
	char sp[100], ap[100], fn[100];
	while(1) {
		start:
		choice = startmenu();
		switch(choice) {
			case 1: {/* student login*/
				printf("Enter password\n");
				scanf("%s", sp);
				if(strcmp(sp, "student") == 0) {
					printf("Enter roll number\n");
					scanf("%d", &rno);
					printf("Enter file name\n");
					scanf("%s", fn);
					sviewscore(rno, fn);
				}
				else
					printf("Invalid password. Try again\n");
				break;
			}


			case 2: {/*admin login*/
				admin:
				printf("Enter password\n");
				scanf("%s", ap);
				if(strcmp(ap, "admin") != 0) {
					printf("Invalid password. Try again\n");
					goto admin;
				}	
				else {
					file:
					printf("Enter filename\n");
					scanf("%s", fn);
					admins:
					amenu = adminmenu();
					switch(amenu) {
						case 1: {/*Add record*/
							addrec = addrecord(fn);
							if(addrec == 0)
							 	goto file;
							else 
								goto admins;
						}
						case 2:{ /*View individual record*/
							printf("Enter roll number:");
							scanf("%d", &rno);
							viewrecord(rno, fn);
							goto admins;
							break;
						}
						case 3: {/*Edit record*/
							printf("Edit student details\n"
								"1. Edit first name\n"
								"2. Edit last name\n"
								"3. Edit date of birth\n"
								"4. Edit contact number\n"
								"5. Edit address\n"
								"6. Edit scores\n"
								"7. Go back\n"
								"Enter your choice\n");
							scanf("%d", &edit);
							printf("Enter roll number!\n");
							scanf("%d", &rno);
							switch(edit) {
								case 1:{/*Edit first name*/
									editfirstname(rno, fn);
									break;
								}
								case 2: {/*Edit last name*/
									editlastname(rno, fn);
									break;
								}
								case 3: {/*Edit dob*/
									editdob(rno, fn);
									break;
								}
								case 4: {/*Edit contact number*/
									editcontact(rno, fn);
									break;
								}
								case 5: {/*Edit address*/
									editaddress(rno, fn);
									break;
								}
								case 6: {/*Edit scores*/
									editscores(rno, fn);
									break;
								}
								case 7: {/*return to previous menu*/
									goto admins;
									break;
								}
								default: {
									printf("Invalid choice. Try againcheck\n");
									break;
								}
							}
							goto admins;
							break;
						}
						case 4: { /*Delete a record*/
							printf("Enter roll number:");
							scanf("%d", &del);
							deleterec(del, fn);
							goto admins;
							break;
						}
						case 5: {/*Return to start menu*/
							goto start;
							break;
						}
						case 6: { /*Exit the program*/
							return 0;
						}
						default: {
							printf("Invalid choice. Try again\n");
							goto admins;
							break;
						}
					}
				}
				break;
			}
			case 3: {/*Exit the program*/
				return 0;
			}
			default:{
				printf("Invalid entry. Try again\n");
				goto start;
			}
		}
	}
	return 0;
}







