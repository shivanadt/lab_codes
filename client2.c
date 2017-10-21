#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<netdb.h>

#define SERVER_PORT 5585
#define BACKLOG 5

int main(int argc, char* argv[])
{
	int s, new_s;
	char *host;
	char message[2];
	int len;
	struct hostent* hp;
	struct sockaddr_in sin;

	//Checking for invalid input
	if(argc != 2){
		printf("Invalid input:client2\n");
		exit(1);	
	}
	host  = argv[1];	
	hp = gethostbyname(host);

	// Addressing for the socket
	bzero((char*)&sin, sizeof(sin));
	sin.sin_family = AF_UNIX;
	bcopy(hp->h_addr, (char*)&sin.sin_addr,hp->h_length); 
	sin.sin_port = htons(SERVER_PORT);

	//Creating a socket
	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
		printf("Socket:client2\n");
		exit(1);
	}
	
	// connecting the socket with a server
	if((connect(s, (struct sockaddr*)&sin, sizeof(sin)) )< 0) {
		printf("Connect:client2\n");
		exit(1);
	}
	
	// receiving the packet from the server
	while(1) {
		if(len  = recv(s, message, sizeof(message), 0)){
			fputs(message, stdout);
		}
	}
	return 0;
}

