#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;  // sockaddr_in - references elements of the socket address. "in" for internet
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)  // creates socket, SOCK_STREAM is for TCP. SOCK_DGRAM for UDP
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // This is to lose the pesky "Address already in use" error message
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) // SOL_SOCKET is the socket layer itself
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;  // Address family. For IPv6, it's AF_INET6. 29 others exist like AF_UNIX etc. 
    address.sin_addr.s_addr = INADDR_ANY;  // Accept connections from any IP address - listens from all interfaces.
    address.sin_port = htons( PORT );    // Server port to open. Htons converts to Big Endian - Left to Right. RTL is Little Endian

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Port bind is done. You want to wait for incoming connections and handle them in some way.
    // The process is two step: first you listen(), then you accept()
    

    while(1)
    {
//listen
        if (listen(server_fd, 3) < 0) // 3 is the maximum size of queue - connections you haven't accepted
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }

//accept: returns a brand new socket file descriptor to use for this single accepted connection. Once done, use send and recv
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                           (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        memset(buffer, 0, sizeof(buffer));
//Client requests filename in buffer
        read( new_socket , buffer, 1024);
//If client wants to exit
        if(strcmp(buffer, "exit!") == 0) break;
        else
        {
            printf("Filename: %s\n",buffer);
    //Open particular file
            FILE *fp = NULL;
    //If file doesnt exist
            if(!(fp = fopen(buffer, "rb"))){
                send(new_socket , "404 Not found" , strlen("404 Not found") , 0 );
            }
    //File found
            else{
                char file[1024];
                int index = 0;
                while(!feof(fp)) file[index++] = fgetc(fp);
                file[index-1] = '\0';
                printf("File: \n%s",file);
                send(new_socket , file , strlen(file) , 0 );  // use sendto() and recvfrom() for DGRAM
                printf("File sent\n\n");
                fclose(fp);
            }
        }
    }
    return 0;
}