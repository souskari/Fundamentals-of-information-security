#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("�������� ��������:\n 1. ������������ ����\n 2. ������ ����\n 3. ������� ���� ��� ������ � ������\n 4. ������� ���� ������ ��� ������\n\
 5. ������� ����\n 6. ������ � ����\n 7. ��������� �� �����\n 8. ������������ �����, � ������� ����� ����\n 9. ������� ����� ��� ������ � ������\n");
    wchar_t File_name[] = TEXT("C:/test_folder/new.txt"); //wchar � TEXT ������������ ��� unicode ����� �������� � ����������� �����
    //TEXT ���������� ��������� ������� ��� ������ unicode 
    int p;
    scanf("%d", &p);
    while (p != 12) {
        if (p == 1) {
            if (SetFileAttributes(File_name, FILE_ATTRIBUTE_ARCHIVE)){ //������� ��� ��������� ���������. ���������� true � false. �� ���� ������ � ������� �����
                //� �������, ������� ��� �������
                printf("���� ������� �����������\n");
            }
            else{
                printf("������ ��������� �����\n");
            }

        }
        if (p == 2) {
            int result;
            result= SetFileAttributes(File_name, FILE_ATTRIBUTE_HIDDEN);
            if (result) {
                printf("���� ������� �����!\n");
            }
            else {
                printf("������ ������� �����\n");
            }
        }
        if (p == 3) {
            if (SetFileAttributes(File_name, FILE_ATTRIBUTE_NORMAL)) {
                printf("���� ������ ��� ������ � ������(normal)\n");
            }
            else {
                printf("������ ���������� ������ 3\n");
            }
        }
        if (p == 4) {
            if (SetFileAttributes(File_name, FILE_ATTRIBUTE_READONLY)) {
                printf("�������� ����� ������� ����������� ������ ������(readonly)\n");
            }
            else {
                printf("������ ���������� ������ 4\n");
            }
        }
        if (p == 5) {
            DWORD attributes = GetFileAttributesA("C:\\test_folder");
            /* DWORD - ��� ����������� ����������� 32-������ ��� ������ � Windows.h, ������� ������������
            ��� ��������������� ��������� �������, ������ ������� � ����������� � ������������ ������� Windows. */
            if (attributes & FILE_ATTRIBUTE_ARCHIVE)
                printf("����� ��������\n");
            else {
                FILE* file1;
                file1 = fopen("C:\\test_folder\\new.txt", "w");
                printf("���� ������\n");
                fclose(file1);
            }
        }
        if(p == 6) {
            DWORD attributes = GetFileAttributesA("C:\\test_folder\\new.txt");
            char fileContent[128] = { 0 };
            printf("�������, ��� ����� �������� � ����: ");
            scanf("%s", fileContent);
            if ((attributes) & FILE_ATTRIBUTE_READONLY)
                printf("���� ������ ��� ������\n");
            else if ((attributes) & FILE_ATTRIBUTE_ARCHIVE)
                printf("�������� ����\n");
            else {
                FILE* file2 = fopen("C:/test_folder/new.txt", "w+");
                fputs(fileContent, file2);
                fclose(file2);
                printf("������ ���� ������� �������� � ����!\n");
            }
            SetFileAttributes(File_name, FILE_ATTRIBUTE_NORMAL);
        }
        if (p == 7) {
            char fileContent[1208] = { 0 };
            DWORD attributes = GetFileAttributesA("C:\\test_folder\\new.txt");
            if (attributes & FILE_ATTRIBUTE_ARCHIVE)
                printf("�������� ����\n");
            else {
                FILE* file3 = fopen("C:/test_folder/new.txt", "r");
                int i = 0;
                while (!feof(file3)) {
                    fileContent[i] = fgetc(file3);
                    i++;
                }                
                fileContent[i-1] = '\0';
                printf("����� �� �����: %s\n", fileContent);
            }
        }
        if (p == 8) {
            if (SetFileAttributes(L"C:/test_folder", FILE_ATTRIBUTE_ARCHIVE)) { //������� ��� ��������� ���������. ���������� true � false. �� ���� ������ � ������� �����
                //� �������, ������� ��� �������
                printf("����� ������� ������������\n");
            }
            else {
                printf("������ ��������� �����\n");
            }
        }
        if (p == 9) {
            if (SetFileAttributes(L"C:/test_folder", FILE_ATTRIBUTE_NORMAL)) { //������� ��� ��������� ���������. ���������� true � false. �� ���� ������ � ������� �����
                //� �������, ������� ��� �������
                printf("����� ������� ������� ��� ������ � ������\n");
            }
            else {
                printf("������ �������� ����� � ������ 9\n");
            }
        }
        scanf("%d", &p);

    }
    return 0;

}