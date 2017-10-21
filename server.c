#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>

#define PORT1_SERVER 5584
#define PORT2_SERVER 5585
#define MAX_LINE 256
#define MAX_REQUEST 5

int main()
{
	struct sockaddr_in sin1, sin2;
	int s1, s2, new_s1, new_s2;
	char buf[2];
	int len;
	char x;
	int yes = 1;
// Code for connecting with client 1
	bzero((char*)&sin1, sizeof(sin1));
	sin1.sin_family = AF_UNIX;
	sin1.sin_addr.s_addr = INADDR_ANY;
	sin1.sin_port =htons(PORT1_SERVER);
	
	if((s1 = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
		perror("simplex-talk:socket");
		exit(1);
	}

	if(bind(s1, (struct sockaddr *)&sin1, sizeof(sin1)) < 0) {
		perror("simplex-talk:bind");
		exit(1);
	}
	
	listen(s1, MAX_REQUEST);
	if((new_s1 = accept(s1, (struct sockaddr *)&sin1, &len)) < 0 ) {
                 perror("simplex-talk:accept");
                 exit(1);
        }

// Code for connecting with client 2
bzero((char*)&sin2, sizeof(sin2));
        sin2.sin_family = AF_UNIX;
        sin2.sin_addr.s_addr = INADDR_ANY;
        sin2.sin_port =htons(PORT2_SERVER);

        if((s2 = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
                perror("simplex-talk:socket");
                exit(1);
        }

        if(bind(s2, (struct sockaddr *)&sin2, sizeof(sin2)) < 0) {
                perror("simplex-talk:bind");
                exit(1);
        }

        listen(s2, MAX_REQUEST);
        if((new_s2 = accept(s2, (struct sockaddr *)&sin2, &len)) < 0 ) {
                 perror("simplex-talk:accept");
                 exit(1);
        }
	
//code for receiving data from client 1
	while(len = recv(new_s1, buf, sizeof(buf), 0)){
		//fputs(buf, stdout);
		x = buf[0];
		buf[0] = 
		send(new_s2, buf, sizeof(buf), 0);
	}
	close(new_s1);
	close(s1);
	close(new_s2);
	close(s2);
	if (setsockopt(new_s1,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof yes) == -1) {
		perror("setsockopt");
		exit(1);
	}

	if (setsockopt(new_s2,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof yes) == -1) {
		perror("setsockopt");
		exit(1);
	}

	return 0;
}
