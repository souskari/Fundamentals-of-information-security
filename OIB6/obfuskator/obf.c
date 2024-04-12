#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 10000

FILE* input;
FILE* output;
char* code;
int l2 = 0;
int l = 0;

void zamena(char* code) {
	l = strlen(code);
	int check;//указатель на то, нашли ли инициализатор для переменной
	FILE* name = fopen("variants_name.txt", "r");
	char* nemas = (char*)malloc(l * sizeof(char));
	int flag = 0;
	char newperemen[15];
	int k = 0; //счётчик для новых имен
	int raznica; //разница между старой и новой длиной имени переменной
	l2 = l;
	for (int i = 0; i < l;)
	{
		/* ЕСЛИ ВСТРЕТИЛАСЬ MAIN, ТО КОПИРУЕМ ЕЕ В НОВЫЙ МАССИВ И УВЕЛИЧИВАЕМ ЗНАЧЕНИЕ УКАЗАТЕЛЯ И FLAG НА 12 СИМВОЛОВ(ДЛИНА СТРОКИ int main()) */
		if (code[i] == 'i' && code[i + 1] == 'n' && code[i + 2] == 't' && code[i + 3] == ' ' && code[i + 4] == 'm' && code[i + 5] == 'a' && code[i + 6] == 'i' && code[i + 7] == 'n' && code[i + 8] == '(' && code[i + 9] == ')')
		{
			for (int j = 0; j <= 10; j++)
			{
				nemas[flag + j] = code[i + j];
			}
			i = i + 12;
			flag = flag + 12;
			check = 1;
		}
		/* ТА ЖЕ ТЕМА С ОСТАЛЬНЫМИ ТИПАМИ В ФАЙЛЕ */
		if (code[i] == 'i' && code[i + 1] == 'n' && code[i + 2] == 't' && code[i + 3] == ' ')
		{
			for (int j = 0; j <= 3; j++)
			{
				nemas[flag + j] = code[i + j];
			}
			i = i + 4;
			flag = flag + 4;
			if (code[i] == '*')
			{
				nemas[flag] = code[i];
				i++;
				flag++;
			}
			check = 1;
		}
		else if (code[i] == 'c' && code[i + 1] == 'h' && code[i + 2] == 'a' && code[i + 3] == 'r' && code[i + 4] == ' ' && (code[i + 6] != '='))
		{
			for (int j = 0; j <= 4; j++)
			{
				nemas[flag + j] = code[i + j];
			}
			i = i + 5;
			flag = flag + 5;
			if (code[i] == '*')
			{
				nemas[flag] = code[i];
				i++;
				flag++;
			}

			check = 1;
		}

		else if (code[i] == 'F' && code[i + 1] == 'I' && code[i + 2] == 'L' && code[i + 3] == 'E' && code[i + 4] == ' ')
		{
			for (int j = 0; j <= 4; j++)
			{
				nemas[flag + j] = code[i + j];
			}
			i = i + 5;
			flag = flag + 5;
			if (code[i] == '*')
			{
				nemas[flag] = code[i];
				i++;
				flag++;
			}
			check = 1;
		}
		/* иначе все переписываем в тупую */
		else
		{
			nemas[flag] = code[i];
			flag++;
			i++;
			check = 0;
		}

		int savei = i;
		int saveflag = flag;
		int razmer = 0;
		char* peremen = (char*)malloc(razmer * sizeof(char));

		if (check == 1) //нашли инициализатор
		{
			k = 0;
			razmer = 0;
			// Перебираем символы в строке до тех пор, пока не встретим символ, означающий конец имени переменной
			while (code[i] != ' ' && code[i] != '[' && code[i] != '(' && code[i] != ',' && code[i] != ';' && code[i] != ')')
			{
				peremen = (char*)realloc(peremen, (razmer + 1) * sizeof(char));
				peremen[razmer] = code[i];
				i++; //перемещаем указатель
				razmer++;
			}
			fgets(newperemen, 15, name); //считываем новое имя переменной из файла
			raznica = 10 - razmer;
			int kontrol;

			nemas = (char*)realloc(nemas, (l + raznica) * sizeof(char)); //новый массив для хранения
			for (int a = 0; a < 10; a++)
			{
				nemas[flag] = newperemen[a]; //замена сама
				flag++;
			}
			k++;

			// Перебираем оставшуюся часть кода и заменяем все вхождения старого имени переменной на новое
			for (int j = i; j <= l; j++)
			{
				kontrol = 0;
				for (int a = 0; a < razmer; a++)
				{
					if (code[j + a] == peremen[a])
					{
						kontrol = 1; //нашли вхождение
					}
					else
					{
						kontrol = 0;
						break;
					}
				}

				if (kontrol == 1 && (code[j + razmer] == ' ' || code[j + razmer] == '[' || code[j + razmer] == '(' || code[j + razmer] == ')' || code[j + razmer] == '+' || code[j + razmer] == ',' || code[j + razmer] == ';' || code[j + razmer] == ']'))
				{
					k++;
					nemas = (char*)realloc(nemas, (l + raznica * k) * sizeof(char));
					for (int a = 0; a < 10; a++)
					{
						nemas[flag] = newperemen[a];
						flag++;
					}
					j = j + razmer - 1;
				}
				else //если не нашли вхождение просто все принтуем дальше
				{
					nemas[flag] = code[j];
					flag++;
				}
			}
			l2 = l + raznica * k;

			memcpy(code, nemas, l2); //копируем новый массив в изначальный code
			l = l2;
		}
		flag = saveflag + razmer;
		i = flag;
	}
	nemas[flag++] = '\0';
	code[flag++] = '\0';
	fclose(name);
}

void musor(char* code) {
	FILE* f = fopen("trash_peremennie.txt", "r"); //имена переменных
	int o;
	int cnt_trash_perem = 1;
	while ((o = fgetc(f)) != EOF) {
		if (o == 10) {
			cnt_trash_perem++;
		}
	}
	rewind(f);
	int ind = 0, i = 1;
	while (i < strlen(code) - 4) {
		if (code[i] == ';' && code[i + 1] == '\n' && code[i - 1] != '1' && code[i - 1] != '0' && cnt_trash_perem > 0) {
			ind = i + 1;
			char per0[12] = { 0 };
			fgets(per0, 12, f);
			per0[9] = ';'; per0[10] = '\0'; //считываем из файла имя переменной и добавляем ей ; и завершающий ноль
			char per[15] = { 0 };
			//в массив для создания мусорной перменной закидываем в начало тип (int)
			per[0] = 'i'; per[1] = 'n'; per[2] = 't'; per[3] = ' '; per[4] = '\0';
			//склеиваем 
			strcat(per, per0);
			char* code0 = (char*)calloc(sizeof(char), (strlen(code)));
			int len = strlen(code);
			for (int j = 0; j < len; j++) {
				// Копируем все символы после точки с запятой из code в новую строку code0, а также добавляем имя мусорной переменной вместо точки с запятой в строку code
				code0[j] = code[ind + j];
				if (j < strlen(per) + 1) code[ind + j] = per[j];
			}
			strcat(code, code0);
			// Изменяем переменную i на количество добавленных символов, чтобы продолжить перебор со следующей точки с запятой
			i = i + strlen(per) + 1;
			cnt_trash_perem--;
		}
		i++;
	}
}

void musorfunction() {
	FILE* fp_in, * fp_out, * fp_junk;
	char buffer[MAX_SIZE]; // буфер для считывания строк из файлов
	fp_in = fopen("f_out.txt", "r");
	fp_out = fopen("fppp_out.txt", "w");
	fp_junk = fopen("trash_function.txt", "r");
	while (fgets(buffer, MAX_SIZE, fp_in)) {
		if (strstr(buffer, "#include") || strstr(buffer, "#define")) {
			fprintf(fp_out, "%s", buffer); // записываем строку с include или define в файл вывода
		}
		else {
			while (fgets(buffer, MAX_SIZE, fp_junk)) {
				fprintf(fp_out, "%s", buffer); // добавляем мусорные функции в файл вывода
			}
		}
	}
	fclose(fp_in);
	fp_in = fopen("f_out.txt", "r");
	char b;
	b = fgets(buffer, MAX_SIZE, fp_in);
	while (!feof(fp_in)) {
		if ((strstr(buffer, "#include")) || (strstr(buffer, "#define"))) {
			b = fgets(buffer, MAX_SIZE, fp_in);
		}
		else {
			fprintf(fp_out, "%s", buffer);  //записываем оставшуюся часть кода в файл
			b = fgets(buffer, MAX_SIZE, fp_in);
		}

	}

	fclose(fp_in);
	fclose(fp_out);
	fclose(fp_junk);
	fp_out = fopen("fppp_out.txt", "r");
	int e; int i = 0;
	char* txt = (char*)calloc(100000, sizeof(char));
	while (!feof(fp_out)) {
		e = fgetc(fp_out);
		if (e == -1) {
			txt[i] = '}';
			i++;
			continue;
		}
		txt[i] = e;
		i++;
	}
	txt[i] = '\0';
	code = txt;

}

void tabul(char* code) {
	for (int i = 0; i < strlen(code); i++)
	{
		if (code[i] == '\t')
			code[i] = '?';
	}
}

void new(char* code){

	for (int i = 0; i < strlen(code); i++)
	{
		if (code[i] == '\n')
			code[i] = '?';
	}
}

void comment(char* code)
{
	int l = strlen(code);
	int flag = 0;
	for (int i = 0; i < l - 1; i++)
	{
		if (flag < 2 && code[i] == '\"') flag++;
		if (flag < 2 && code[i] == '\'') flag++;
		if (flag == 2) flag = 0; // Если нашли закрывающую кавычку или апостроф, сбрасываем счетчик flag
		if (flag == 0) { // Если счетчик flag равен 0, значит мы находимся вне строковых литералов
			if (code[i] == '/' && code[i + 1] == '/') // Если нашли комментарий "//", то удаляем его и все символы до конца строки
			{
				int counter = i;
				while (code[counter] != '\n')
				{
					counter++;
				}

				int b = i;
				while (counter < l) {
					code[b] = code[counter];
					b++;
					counter++;
				}

				while (b < l)
					code[b++] = 0;
			}

			if (code[i] == '/' && code[i + 1] == '*') // Если нашли комментарий "/*", то удаляем его и все символы до закрывающего комментария "*/"
			{
				int counter = i;
				while (!(code[counter - 1] == '*' && code[counter] == '/'))
				{
					counter++;
				}
				counter++;

				int buf = i;
				while (counter < l) {
					code[buf] = code[counter];
					buf++;
					counter++;
				}

				while (buf < l)
				{
					code[buf] = 0;
					buf++;
				}
			}
		}
	}
}

void result(char* code) {
	int len = strlen(code);
	char* res = (char*)malloc(sizeof(char) * len+10);
	int j = 0;
	char b = ' ';
	for (int i = 0; i <= len; i++) {
		if (code[i] != '?') res[j++] = code[i];
		if (code[i] == '?') res[j++] = b;
		if ((code[i - 2] == 'y' && code[i - 1] == ' ' && code[i] == '5') || (code[i] == 'S' && code[i - 1] == 'G') || code[i] == '>') res[j++] = '\n';
	}
	res[j++] = '\0';
	puts(res);
}

void main() {
	input = fopen("password_orig.txt", "r");
	char c;
	code = (char*)calloc(100000, sizeof(char)); int i = 0;
	while ((c = fgetc(input)) != EOF) {
		code[i] = c;
		i++;
	}
	i++;
	code[i] = '\0';
	l = i;
	zamena(code);
	l = l2;
	musor(code);
	FILE* f_out;
	f_out = fopen("f_out.txt", "w");
	int v = 0;
	while (code[v] != '\0') {
		fprintf(f_out, "%c", code[v]);
		v++;
	}
	v++;
	if (code[v] == '\0') {
		fprintf(f_out, "%c", code[v]);
	}
	fclose(f_out);
	musorfunction();
	comment(code);
	tabul(code);
	new(code);
	result(code);
}