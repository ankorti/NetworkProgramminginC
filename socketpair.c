#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char ** argv)
{
    int z;                               // to store the return code from the socketpair function 
    int socket_fileDescriptor[2];      //Pair of sockets 
    z=socketpair(AF_LOCAL,SOCK_STREAM,0,socket_fileDescriptor);
    if(z==-1)
    {
        fprintf(stderr,"%s: socketpair(AF_LOCAL,SOCK_STREAM,0)\n",strerror(errno));
        return 1; 
    }
    printf("socket_fileDescriptor[0] = %d \n",socket_fileDescriptor[0]);
    printf("socket_fileDescriptor[1] = %d \n",socket_fileDescriptor[1]);
    system("netstat --unix -p");
    return 0;
}