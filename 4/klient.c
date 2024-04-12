#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <dos.h>
#define IPSERV "192.168.56.1"//"31.134.188.101"//"192.168.31.178"

#pragma comment(lib, "ws2_32.lib")

int main() {
	WSADATA wsdataklient;
	int res=1;
	WSAStartup(MAKEWORD(2, 2), &wsdataklient);
	SOCKET sk = socket(AF_INET, SOCK_STREAM, 0);
	if (sk == INVALID_SOCKET) {
		printf("Invalid socket\n");
		return;
	}
	else {
		printf("WinSock initialization is OK\n");
	}
	SOCKADDR_IN str;
	memset(&str, 0, sizeof(str));
	str.sin_family = AF_INET;
	str.sin_port = htons(9002);
	str.sin_addr.S_un.S_addr = inet_addr(IPSERV); 
	//res = connect(sk, &str, sizeof(str));
	while (res) {
		res = connect(sk, &str, sizeof(str));
		printf("Connection is FAILED.... WAIT\n");
		Sleep(10);
		continue;
	}
	if (res == 0) {
		printf("Connection to Server is OK!!\n");
	}
	else {
		printf("Connection is FAILED\n");
	}
	char filename[100];
	memset(filename, 0, sizeof(filename));
	recv(sk, filename, sizeof(filename), 0);
	printf("%s\n", filename);
	if (_unlink(filename))
	{
		printf("File error!\n");
		return 0;
	}
	return EXIT_SUCCESS;

}
