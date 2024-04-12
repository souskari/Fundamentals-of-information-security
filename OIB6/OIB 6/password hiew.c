#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int proverka(char* parol, char* consol) {
	int i = 0; int lenp=0,lenc = 0;
	while (parol[i] != '\0' && consol[i] != '\0' && parol[i] == consol[i]) {
		i++;
	}
	int j = 0;
	while (parol[j] != '\0') {
		lenp++; j++;
	}
	if (i == lenp) {
		return 1;
	}
	else return 0;
}

int main() {
	FILE* pasfile;
	pasfile = fopen("password.txt", "r");
	char text[128] = { 0 };
	char parol[128] = { 0 };
	int c; int i = 0;
	while ((c = fgetc(pasfile)) != EOF) {
		parol[i] = c;
		i++;
	}
	fclose(pasfile);
	parol[i] = '\0';
	printf("Enter password: ");
	scanf("%s", &text);
	int p;
	if (p=proverka(parol, text) == 1) {
		printf("Password accept, WELCOME\n");
	}
	else {
		printf("Password ERROR\n");
	}
}