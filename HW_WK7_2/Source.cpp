#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include <iostream>
#include <string>

using namespace std;
int main() {
	char password[3][30];
	string input;
	int condition[5],Allcondition;
	int i = 0,j = 0,k = 0,p = 0;
	getline(cin, input);
	while (j < 3) {
		k = 0;
		while (input[i] != ',' && input[i] != NULL) {
			password[j][k] = input[i];
			i++;
			k++;
		}
		if (input[i]==','|| input[i] == NULL) {
			password[j][k] = NULL;
			i++;
		}
		j++;
	}
	k = 0;
	while (p < 3) {
		if (strlen(password[p])>=6 && strlen(password[p]) <= 12) {
			condition[0] = 1;
			while (k < strlen(password[p])) {
				if (password[p][k] >= 'a' && password[p][k] <= 'z') {
					k = 0;
					condition[1] = 1;
					break;
				}
				else {
					condition[1] = 0;
					k++;
				}
			}
			k = 0;
			while (k < strlen(password[p])) {
				if (password[p][k] >= 'A' && password[p][k] <= 'Z') {
					k = 0;
					condition[2] = 1;
					break;
				}
				else {
					condition[2] = 0;
					k++;
				}
			}
			k = 0;
			while (k < strlen(password[p])) {
				if (password[p][k] >= '0' && password[p][k] <= '9') {
					k = 0;
					condition[3] = 1;
					break;
				}
				else {
					condition[3] = 0;
					k++;
				}
			}
			k = 0;
			while (k < strlen(password[p])) {
				if (password[p][k] == '$' || password[p][k] == '#' || password[p][k] == '@') {
					k = 0;
					condition[4] = 1;
					break;
				}
				else {
					condition[4] = 0;
					k++;
				}
			}
		}
		if(condition[0]==1&& condition[1] == 1 && condition[2] == 1 && condition[3] == 1 && condition[4] == 1){
			if (p==0) {
				printf("%s (Kob)",password[p]);
			}
			else if (p == 1) {
				printf("%s (Romtham)", password[p]);
			}
			else if (p == 2) {
				printf("%s (Jojo)", password[p]);
			}
			break;
		}
		p++;
	}
	return 0;
}