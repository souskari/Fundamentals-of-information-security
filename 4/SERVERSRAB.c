#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <dos.h>
#define IPV4 "10.0.2.15" //"31.134.188.101" //"192.168.56.1" 

#pragma comment(lib, "ws2_32.lib")

int main() {
	WSADATA wsdata;
	WSAStartup(MAKEWORD(2, 2), &wsdata);
	SOCKET start;
	start = socket(AF_INET, SOCK_STREAM, 0);
	if (start == INVALID_SOCKET) {
		printf("Invalid socket\n");
		return 0;
	}
	else {
		printf("WinSock initialization is OK\n");
	}
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(9002);
	//servAddr.sin_addr.s_addr = inet_addr(IPV4);

	bind(start, &servAddr, sizeof(servAddr));
	listen(start, 1);

	SOCKADDR_IN klient_adr;
	int klient_size = sizeof(klient_adr);

	SOCKET klient_socket;

	printf("Waiting for connection...\n");

	char file_name[90];//массив для имени файла
	for (int i = 0; i < 50; i++)
		file_name[i] = 0;

	if (klient_socket = accept(start, (struct sockaddr*)&klient_adr, &klient_size))// ожидается входящее соединение
	{
		printf("Connection established\n\nEnter file name:\n");
		scanf("%s", file_name);
		send(klient_socket, file_name, sizeof(file_name), 0); // отправка имени файла клиенту 
	}
	printf("File delited\n");
	return EXIT_SUCCESS;
}