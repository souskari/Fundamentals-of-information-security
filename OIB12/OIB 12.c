#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("Выберите действие:\n 1. Архивировать файл\n 2. Скрыть файл\n 3. Открыть файл для чтения и записи\n 4. Открыть файл только для чтения\n\
 5. Создать файл\n 6. Запись в файл\n 7. Прочитать из файла\n 8. Архивировать папку, в которой лежит файл\n 9. Открыть папку для чтения и записи\n");
    wchar_t File_name[] = TEXT("C:/test_folder/new.txt"); //wchar и TEXT используется для unicode чтобы работать с библиотекой винды
    //TEXT определяет строковой литерал как строку unicode 
    int p;
    scanf("%d", &p);
    while (p != 12) {
        if (p == 1) {
            if (SetFileAttributes(File_name, FILE_ATTRIBUTE_ARCHIVE)){ //функция для изменения атрибутов. Возвращает true и false. На вход строка и сименем файла
                //и атрибут, который ему передаём
                printf("Файл успешно архивирован\n");
            }
            else{
                printf("ОШИБКА архивации файла\n");
            }

        }
        if (p == 2) {
            int result;
            result= SetFileAttributes(File_name, FILE_ATTRIBUTE_HIDDEN);
            if (result) {
                printf("Файл успешно скрыт!\n");
            }
            else {
                printf("ОШИБКА скрытия файла\n");
            }
        }
        if (p == 3) {
            if (SetFileAttributes(File_name, FILE_ATTRIBUTE_NORMAL)) {
                printf("Файл открыт для записи и чтения(normal)\n");
            }
            else {
                printf("ОШИБКА выполнения пункта 3\n");
            }
        }
        if (p == 4) {
            if (SetFileAttributes(File_name, FILE_ATTRIBUTE_READONLY)) {
                printf("Атрибуты файла успешно установлены только чтения(readonly)\n");
            }
            else {
                printf("ОШИБКА выполнения пункта 4\n");
            }
        }
        if (p == 5) {
            DWORD attributes = GetFileAttributesA("C:\\test_folder");
            /* DWORD - это стандартный беззнаковый 32-битный тип данных в Windows.h, который используется
            для манипулирования двоичными данными, целыми числами и указателями в операционной системе Windows. */
            if (attributes & FILE_ATTRIBUTE_ARCHIVE)
                printf("Папка архивная\n");
            else {
                FILE* file1;
                file1 = fopen("C:\\test_folder\\new.txt", "w");
                printf("Файл создан\n");
                fclose(file1);
            }
        }
        if(p == 6) {
            DWORD attributes = GetFileAttributesA("C:\\test_folder\\new.txt");
            char fileContent[128] = { 0 };
            printf("Введите, что нужно записать в файл: ");
            scanf("%s", fileContent);
            if ((attributes) & FILE_ATTRIBUTE_READONLY)
                printf("Файл только для чтения\n");
            else if ((attributes) & FILE_ATTRIBUTE_ARCHIVE)
                printf("Архивный файл\n");
            else {
                FILE* file2 = fopen("C:/test_folder/new.txt", "w+");
                fputs(fileContent, file2);
                fclose(file2);
                printf("Данные были успешно записаны в файл!\n");
            }
            SetFileAttributes(File_name, FILE_ATTRIBUTE_NORMAL);
        }
        if (p == 7) {
            char fileContent[1208] = { 0 };
            DWORD attributes = GetFileAttributesA("C:\\test_folder\\new.txt");
            if (attributes & FILE_ATTRIBUTE_ARCHIVE)
                printf("Архивный файл\n");
            else {
                FILE* file3 = fopen("C:/test_folder/new.txt", "r");
                int i = 0;
                while (!feof(file3)) {
                    fileContent[i] = fgetc(file3);
                    i++;
                }                
                fileContent[i-1] = '\0';
                printf("Текст из файла: %s\n", fileContent);
            }
        }
        if (p == 8) {
            if (SetFileAttributes(L"C:/test_folder", FILE_ATTRIBUTE_ARCHIVE)) { //функция для изменения атрибутов. Возвращает true и false. На вход строка и сименем файла
                //и атрибут, который ему передаём
                printf("Папка успешно архивирована\n");
            }
            else {
                printf("ОШИБКА архивации папки\n");
            }
        }
        if (p == 9) {
            if (SetFileAttributes(L"C:/test_folder", FILE_ATTRIBUTE_NORMAL)) { //функция для изменения атрибутов. Возвращает true и false. На вход строка и сименем файла
                //и атрибут, который ему передаём
                printf("Папка успешно открыта для чтения и записи\n");
            }
            else {
                printf("ОШИБКА открытия папки в пункте 9\n");
            }
        }
        scanf("%d", &p);

    }
    return 0;

}