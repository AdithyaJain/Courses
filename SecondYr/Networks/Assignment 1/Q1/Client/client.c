// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{
	while(1)
	{
		struct sockaddr_in address;
		int sock = 0, valread;
		struct sockaddr_in serv_addr;
		char *hello = "Hello";
		char buffer[1024] = {0};
		if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		{
			printf("\n Socket creation error \n");
			return -1;
		}

		memset(&serv_addr, '0', sizeof(serv_addr)); // to make sure the struct is empty. Essentially sets sin_zero as 0
		// which is meant to be, and rest is defined below

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(PORT);


		// Converts an IP address in numbers-and-dots notation into either a 
		// struct in_addr or a struct in6_addr depending on whether you specify AF_INET or AF_INET6.
		if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
		{
			printf("\nInvalid address/ Address not supported \n");
			return -1;
		}
		if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)  // connect to the server address
		{
			printf("\nConnection Failed \n");
			return -1;
		}

		printf("Enter name of file(enter 'exit!' to exit): ");
		char filename[1024];
//Scan filename entered
		scanf("%s",filename);
//If client wants to exit
		if(strcmp(buffer, "exit!") == 0) break;
		else {
			send(sock , filename , strlen(filename) , 0 ); //send file name to server

			valread = read( sock , buffer, 1024);  // receive file back from server, into the buffer 
			FILE *fp;
			fp = fopen(filename, "w+");
			if(fp == NULL)
			{
				perror("file");
				exit(EXIT_FAILURE);
			}
			fwrite(buffer, sizeof(char), sizeof(buffer), fp);
			fclose(fp);
			printf("Buffer: %s\n",buffer);
		}
	}
	return 0;
}