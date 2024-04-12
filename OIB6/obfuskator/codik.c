#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>
#include<stdlib.h>
#include<locale.h>
#include <ctype.h>
#include <conio.h> 

FILE* file;
FILE* musr;
FILE* musrf;
int size2 = 0;
int size = 0;
int n = 0;


char* musorf(char* text, int size)
{
	FILE* musorf = fopen("musorf.txt", "r");
	char* newmasi = (char*)malloc(size * sizeof(char));
	int flag = 0;
	n = 0;
	for (int i = 0; i < size;i++)
	{
		if ((text[i] == 'f') && (text[i + 1] == 'i') && (text[i + 2] == 'l') && (text[i + 3] == 'e') && (text[i + 4] == ';')||( (text[i] == 'n') && (text[i + 1] == ' ') && (text[i + 2] == '0') && (text[i + 3] == ';') && (text[i + 4] == '}')))
		{
			n++;
			newmasi[flag] = text[i];
			flag++;
			i++;
			newmasi[flag] = text[i];
			flag++;
			i++;
			newmasi[flag] = text[i];
			flag++;
			i++;
			newmasi[flag] = text[i];
			flag++;
			i++;
			newmasi[flag] = text[i];
			char mu[111] = { 0 };
			for (int j = 0;j < 110;j++)
				mu[j] = fgetc(file);
			
			mu[110] = '\0';
			
			newmasi = (char*)realloc(newmasi, (size + 110 * n) * sizeof(char));

			for (int j = 1; j <= 110; j++)
			{
				newmasi[flag + j] = mu[j - 1];
			}

			flag = flag + 111;
			
		}
		else
		{
			newmasi[flag] = text[i];
			flag++;
			
		}
	}
	size = size + 109 * n;
	newmasi[size] = '\0';

	fclose(musorf);
	return newmasi;

}

char* musorf2(char* text, int size)
{
	FILE* musorf = fopen("musorf2.txt", "r");
	char* newmasi = (char*)malloc(size * sizeof(char));
	int flag = 0;
	n = 0;
	for (int i = 0; i < size;i++)
	{
		if ((text[i+1] == 'v') && (text[i + 2] == 'o') && (text[i + 3] == 'i') && (text[i + 4] == 'd'))
		{
			n++;
			char mu[111] = { 0 };
			for (int j = 0;j < 110;j++)
				mu[j] = fgetc(file);

			mu[110] = '\0';
			

			newmasi = (char*)realloc(newmasi, (size + 110 * n) * sizeof(char));

			for (int j = 1; j <= 110; j++)
			{
				newmasi[flag + j-1] = mu[j - 1];
			}

			flag = flag + 110;
		}
		else
		{
			newmasi[flag] = text[i];
			flag++;
		}

	}
	size = size + 109 * n;
	newmasi[size] = '\0';
	fclose(musorf);
	return newmasi;
}


char* musor(char* text, int size)
{
	FILE* musor = fopen("musorp.txt", "r");
	char* newmas = (char*)malloc(size * sizeof(char));
	int flag = 0;
	n = 0;
	for (int i = 0; i < size;i++)
	{
		if ((text[i] == '{')&&(text[i+1]!='0'))
		{
			n++;
			newmas[flag] = text[i];
			char mu[30];
			fgets(mu, 30, musor);

			newmas = (char*)realloc(newmas, (size + 26 * n) * sizeof(char));

			for (int j = 1; j <= 26; j++)
			{
				newmas[flag + j] = mu[j - 1];
			}

			flag = flag + 26;
		}
		else
		{
			newmas[flag] = text[i];
			flag++;
		}
	}
	size = size + 25 * n-1;
	newmas[size] = '\0';
	fclose(musor);
	return newmas;
}



char* ChangeName(char* text, int size)
{
	bool check;
	FILE* name = fopen("variables.txt", "r");
	char* nemas = (char*)malloc(size * sizeof(char));
	int flag = 0;
	char newperemen[15];
	int k = 0;
	int raznica;
	 size2 = size;

	for (int i = 0; i < size;)
	{
		if (text[i] == 'i' && text[i + 1] == 'n' && text[i + 2] == 't' && text[i + 3] == ' ' && text[i + 4] == 'm' && text[i + 5] == 'a' && text[i + 6] == 'i' && text[i + 7] == 'n' && text[i + 8] == '(' && text[i + 9] == ')')
		{
			for (int j = 0; j <= 10; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 12; 
			flag = flag + 12;
			check = 1;
		}

		if (text[i] == 'i' && text[i + 1] == 'n' && text[i + 2] == 't' && text[i + 3] == ' ')
		{
			for (int j = 0; j <= 3; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 4; 
			flag = flag + 4;
			if (text[i] == '*')
			{
				nemas[flag] = text[i];
				i++;
				flag++;
			}
			check = 1;
		}
		else if (text[i] == 'c' && text[i + 1] == 'h' && text[i + 2] == 'a' && text[i + 3] == 'r' && text[i + 4] == ' ')
		{
			for (int j = 0; j <= 4; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 5;
			flag = flag + 5;
			if (text[i] == '*')
			{
				nemas[flag] = text[i];
				i++;
				flag++;
			}
			check = 1;
		}
		
		else if (text[i] == 'F' && text[i + 1] == 'I' && text[i + 2] == 'L' && text[i + 3] == 'E' && text[i + 4] == ' ')
		{
			for (int j = 0; j <= 4; j++)
			{
				nemas[flag + j] = text[i + j];
			}
			i = i + 5;
			flag = flag + 5;
			if (text[i] == '*')
			{
				nemas[flag] = text[i];
				i++;
				flag++;
			}
			check = 1;
		}
		
		else
		{
			nemas[flag] = text[i];
			flag++;
			i++;
			check = 0;
		}

		int savei = i;
		int saveflag = flag;
		int razmer = 0;
		char* peremen = (char*)malloc(razmer * sizeof(char));

		if (check == 1)
		{
			k = 0;
			razmer = 0;
			while (text[i] != ' ' && text[i] != '[' && text[i] != '(' && text[i] != ',' && text[i] != ';' && text[i] != ')')
			{
				peremen = (char*)realloc(peremen, (razmer + 1) * sizeof(char));
				peremen[razmer] = text[i];
				i++;
				razmer++;
			}
			fgets(newperemen, 15, name);
			raznica = 10 - razmer;
			int kontrol;

			nemas = (char*)realloc(nemas, (size + raznica) * sizeof(char));
			for (int a = 0; a < 10; a++)
			{
				nemas[flag] = newperemen[a];
				flag++;
			}
			k++;

			for (int j = i; j < size; j++)
			{
				kontrol = 0;
				for (int a = 0; a < razmer; a++)
				{
					if (text[j + a] == peremen[a])
					{
						kontrol = 1;
					}
					else
					{
						kontrol = 0;
						break;
					}
				}

				if (kontrol == 1 && (text[j + razmer] == ' ' || text[j + razmer] == '[' || text[j + razmer] == '(' || text[j + razmer] == ')' || text[j + razmer] == '+' || text[j + razmer] == ',' || text[j + razmer] == ';' || text[j + razmer] == ']'))
				{
					k++;
					nemas = (char*)realloc(nemas, (size + raznica * k) * sizeof(char));
					for (int a = 0; a < 10; a++)
					{
						nemas[flag] = newperemen[a];
						flag++;
					}
					j = j + razmer - 1;
				}
				else
				{
					nemas[flag] = text[j];
					flag++;
				}
			}
			size2 = size + raznica * k;

			text = (char*)realloc(text, size2 * sizeof(char));
			memcpy(text, nemas, size2);
			size = size2;
		}


		i = savei + razmer;
		flag = saveflag + razmer;
		i = flag;
	}
	nemas[flag]='\0';
	fclose(name);
	return nemas;
}




void tabulyatiya(char* text, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (text[i] == '\t')
			text[i] = '?';
	}
}

void NewLine(char* text, int size)
{

	for (int i = 0; i < size; i++)
	{
		if (text[i] == '\n') 
			text[i] = '?';
	}
}

void probeli(char* text, int size) {

	for (int i = 0; i < size; i++)
	{
		if (text[i] == '?') {
			int num = i;
			int a = 0;
			while (text[num] == '?') {
				a++;
				num++;
			}
			
				int b = i;
				int counter = i + a;
				while (counter < size) {   
					text[b] = text[counter];
					b++;
					counter++;
				}

				while (b < size)
					text[b++] = 0;
			
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (text[i] == ',' || text[i] == '=' || text[i] == ')' || text[i] == '(' || text[i] == '[' || text[i] == ']' || text[i] == '&' || text[i] == '>' || text[i] == '<' || text[i] == '+' || text[i] == '-'  || text[i] == '"') {
			int num = i + 1;
			int a = 0;
			if (text[num] == ' '){
				while (text[num] == ' ') {
					a++;
					num++;
				}

			int b = i + 1;
			int counter = i + a + 1;
			while (counter < size) {
				text[b] = text[counter];
				b++;
				counter++;
			}

			while (b < size)
				text[b++] = 0;
		  }
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (text[i] == ',' || text[i] == '=' || text[i] == ')' || text[i] == '(' || text[i] == '[' || text[i] == ']' || text[i] == '&' || text[i] == '>' || text[i] == '<' || text[i] == '+' || text[i] == '-' || text[i] == '"') {
			int num = i - 1;
			int a = 0;
			if (text[num] == ' ') {
				while (text[num] == ' ') {
					a++;
					num++;
				}

				int b = i - 1;
				int counter = i + a - 1;
				while (counter < size) {
					text[b] = text[counter];
					b++;
					counter++;
				}

				while (b < size)
					text[b++] = 0;
			}
		}
	}
}


void commentarii(char* text, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (text[i] == '/' && text[i + 1] == '/')
		{
			int counter = i;
			while (text[counter] != '\n')
			{
				counter++;
			}

			int b = i;
			while (counter < size) {  
				text[b] = text[counter]; 
				b++;
				counter++;
			}

			while (b < size)
				text[b++] = 0; 
		}

		if (text[i] == '/' && text[i + 1] == '*') 
		{
			int counter = i;
			while (!(text[counter - 1] == '*' && text[counter] == '/')) 
			{
				counter++;
			}
			counter++;

			int buf = i;
			while (counter < size) {
				text[buf] = text[counter];
				buf++;
				counter++;
			}

			while (buf < size)
			{
				text[buf] = 0;
				buf++;
			}
		}
	}
}


int main() {
	file = fopen("open1.txt", "r"); 
	
	if (file == NULL) {
		printf("Error");
		return 0;
	}
	char* text = (char*)malloc(sizeof(char));
	if ((char*)malloc(sizeof(char)) == NULL) {
		printf("Error");
		return 0;
	}
	int i = 0;
	while (!feof(file)) {
		text = (char*)realloc(text, (i + 1) * sizeof(char));
		if ( (char*)realloc(text, (i + 1) * sizeof(char))==NULL) {
			printf("Error");
			return 0;
		}
		text[i] = fgetc(file);
		i++;
	}
	text[i - 1] = '\0';
	 size = i - 1;
	fclose(file);
	commentarii(text, size);
	
	text = ChangeName(text, size);
	size = size2;
	text = musor(text, size);
	size = size + 25 * n;
	text = musorf(text, size);
	size = size + 109 * n;
	text = musorf2(text, size);
	size = size + 109 * n;
	NewLine(text, size);
	tabulyatiya(text, size);
	probeli(text, size);

	
	FILE* finish = fopen("obfuscation.txt", "w");
	int j = 0;
	while (text[j] != '\0')
	{
		printf("%c", text[j]);
		fprintf(finish, "%c", text[j]);
		j++;
	}
	fclose(finish);
	return 0;
}
