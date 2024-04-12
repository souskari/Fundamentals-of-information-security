#define _CRT_SECURE_NO_WARNINGS
#include <conio.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

#define STEPS 35 //�� �������� �������� (33 �����) (�� ������� ��������� ���� - ������� ����� �� � ����� ���������)
#define delitels " ,-.:;\n�()�/ "
#define MAX_WORD_LENGTH 30
#define MAX_WORD_COUNT 500
#define MAX_FILE_LENGTH 10000
#define len 32
int length;
int* st;
char* v;
char history[STEPS][MAX_FILE_LENGTH];
int currentStep = 0;
FILE* file;
char alfavit[33] = "��������������������������������";
char chastota[33] = "��������������������������������";


void analiz() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* file;
	file = fopen("open3.txt", "r");
	float count[33]; //���-�� ������ ���������� ����� � ������
	int countletter = 0;//����� ���-�� ���� � ������
	char b;
	for (int i = 0; i < 33; i++) {
		count[i] = 0;
	}
	while ((b = fgetc(file)) != EOF) {
		countletter++;
		//b = fgetc(file);
		for (int f = 0; f < 34; f++) {
			if (b == alfavit[f]) {
				count[f]++;
			}
		}
	}
	for (int i = 0; i < 33; i++) {
		count[i] = count[i] / countletter;
	}
	float tmp; char btmp;
	for (int i = 33 - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (count[j] < count[j + 1])
			{
				tmp = count[j];
				count[j] = count[j + 1];
				count[j + 1] = tmp;
				btmp = alfavit[j];
				alfavit[j] = alfavit[j + 1];
				alfavit[j + 1] = btmp;
			}
		}

	}
	for (int i = 0; i < 33; i++) {
		printf("%c", alfavit[i]);
		printf("  ");
		printf("%f", count[i]);
		printf("  ");
		printf("%c\n", chastota[i]);
	}
	fclose(file);
	printf("\n\n");
}

void groupByLen() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int g;
	int wordCount;
	char words[MAX_WORD_COUNT][MAX_WORD_LENGTH];
	char currentString[MAX_FILE_LENGTH];
	strcpy(currentString, history[currentStep]);
	char* word = strtok(currentString, delitels); // ��������� ����� �� ����� � �������� ����� � ������ ����
	for (wordCount = 0; word != NULL; word = strtok(NULL, delitels), wordCount++) {
		strcpy(words[wordCount], word);
	}
	char tmp[MAX_FILE_LENGTH];
	for (int i = wordCount - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (strlen(words[j]) < strlen(words[j + 1]))
			{
				strcpy(tmp, words[j]);
				strcpy(words[j], words[j + 1]);
				strcpy(words[j + 1], tmp);
			}
		}

	}
	int maxlen = strlen(words[0]); int teklen;//������� ����� ������� �� ���������� �����, �������� ����� ������� � ����
	for (int i = 0; i < wordCount; i++) {
		teklen = strlen(words[i]);
		if (teklen == maxlen) {
			printf(words[i]);
			printf(" ");
		}
		else {
			maxlen = teklen;
			printf("\n---------------------------------------------------------\n");
			printf(words[i]);
			printf(" ");
		}
	}
	printf("\n");
}

int checkCryptography(char* str) {
	int count = 0; int i = 0;
	for (int i = 0;; i++) {
		if (!str[i]) return count;
		if (str[i] > '�' && str[i] < '�' || str[i] == '�') count++;
	}
}

void groupByCryptography() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int wordCount; int g;
	char words[MAX_WORD_COUNT][MAX_WORD_LENGTH];
	char currentString[MAX_FILE_LENGTH];
	strcpy(currentString, history[currentStep]);
	char* word = strtok(currentString, delitels); // ��������� ����� �� ����� � �������� ����� � ������ ����
	for (wordCount = 0; word != NULL; word = strtok(NULL, delitels), wordCount++) {
		strcpy(words[wordCount], word);
	}
	char tmp[MAX_FILE_LENGTH];
	for (int i = wordCount - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (checkCryptography(words[j]) > checkCryptography(words[j + 1]))
			{
				strcpy(tmp, words[j]);
				strcpy(words[j], words[j + 1]);
				strcpy(words[j + 1], tmp);
			}
		}

	}
	int maxlen = checkCryptography(words[0]); int teklen;//������� ����� ������� �� ���������� �����, �������� ����� ������� � ����
	for (int i = 0; i < wordCount; i++) {
		teklen = checkCryptography(words[i]);
		if (teklen == maxlen) {
			printf(words[i]);
			printf(" ");
		}
		else {
			maxlen = teklen;
			printf("\n---------------------------------------------------------\n");
			printf(words[i]);
			printf(" ");
		}
	}
	printf("\n");
}

void showCurrentCryptogramState() {
	printf("������� ��������� �������� �������������� ������������ (�������� ����� - �������������, ��������� - ��� �������������):\n"); printf("\n");
	printf(history[currentStep]);
	printf("\n\n");
}

void replace() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char a[2];
	char b[2];
	printf("������� �����, ������� ������ ��������:");
	scanf("%s", &a[0]);
	printf("������� �����, �� ������� ������ ��������(��������):");
	scanf("%s", &b[0]);
	strcpy(history[currentStep + 1], history[currentStep]); //�������� ������� ��� �� �����������
	++currentStep;//����������� �������� �������� ����
	char* newCryptogram = history[currentStep]; //���������� ��, ��� ����� � ��� � ������� ����������
	for (int i = 0; newCryptogram[i] != NULL; i++) {
		if (newCryptogram[i] == a[0]) {
			newCryptogram[i] = b[0];
		}
	}
	showCurrentCryptogramState();
}
void backup() {
	int step;
	printf("������� ����� �� ������ �������?");
	scanf("%d", &step);
	if (step >= currentStep) currentStep = 0;
	else currentStep -= step;
	printf("������� ���: %u\n", currentStep);
	showCurrentCryptogramState();
}

int interaction() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a;
	printf("�������� ��������:\n\
		1.������ �������\n\
		2.����������� �� ���-�� ����\n\
		3.����������� �� ���-�� ���������������� ����\n\
		4.�������� ������������\n\
		5.������ ����\n\
		6.������ ��������\n\
		7.����������\n");
	scanf_s("%d", &a);
	return a;
}

//������������ ��� ���������� 

void Sort(char* mass, int _len)
{
	int i, j;
	char tmp;
	for (i = 0; i < _len; i++)
	{
		for (j = 0; j < _len - i - 1; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				tmp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp;
			}
		}
	}
}

void Initialize(char* _v, int _length)
{
	int i;
	length = _length;
	v = (char*)malloc((length * sizeof(char)) + 1);
	st = (int*)malloc(length * sizeof(int));

	for (i = 0; i < length; i++)
		v[i] = _v[i];
	v[length] = 0;

	for (i = 0; i < length; i++)
		st[i] = 0;
}

void Swap(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}
void Reverse(char* v, int start)
{
	int i;
	for (i = 0; i < (length - start) / 2; i++)
		Swap(&(v[start + i]), &(v[length - 1 - i]));
}
BOOL NextPermutation()
{
	int pos, i;
	if (length < 2) return FALSE;
	pos = length - 2;
	while (pos >= 0)
	{
		if (st[pos] < length - 1 - pos)
		{
			Reverse(v, pos + 1);
			for (i = pos + 1; i < length; )
				st[i++] = 0;
			st[pos]++;
			Swap(&(v[pos]), &(v[pos + st[pos]]));
			return TRUE;
		}
		pos--;
	}
	return FALSE;
}


void avtozamena() {
	FILE* file;
	file = fopen("result.txt", "a+");
	char am[] = "�������������������������������������";
	//char am[] = "����������������";
	char am2[] = "��������������������������������";
	Sort(am, len);
	Initialize(am, len);
	char newtext[MAX_WORD_COUNT];
	int k = 0;
	do {
		strcpy(newtext, history[currentStep]);
		for (int i = 0; newtext[i]!='\0'; i++) {
			for (int j = 0; j < 33; j++) {
				if ((newtext[i]+32) == am2[j]) {
					newtext[i] = v[j];
				}
			}
		}
		fprintf(file, newtext);
		fprintf(file, "\n");
	} while (NextPermutation());
	fclose(file);
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE* file;
	file = fopen("open3.txt", "r");
	char c; int f = 0;
	while ((c = fgetc(file)) != EOF) {
		history[currentStep][f] = c;
		f++;
	}
	history[currentStep][f] = '\0';
	int p = 0;
	while (p != 8) {
		int p = interaction();
		if (p == 1) {
			printf("\n");
			analiz();
		}
		if (p == 2) {
			printf("\n");
			groupByLen();
		}
		if (p == 3) {
			printf("\n");
			groupByCryptography();
		}
		if (p == 4) {
			printf("\n");
			showCurrentCryptogramState();
		}
		if (p == 5) {
			printf("\n");
			replace();
		}
		if (p == 6) {
			printf("\n");
			backup();
		}
		if (p == 7) {
			printf("\n");
			avtozamena();
		}
	}
}
