#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>

#define PORT_SERVER 5432
#define MAX_LINE 256
#define MAX_REQUEST 5

int main()
{
        struct sockaddr_in sin;
        int s, new_s;
        char buf[MAX_LINE];
        int len;

        bzero((char*)&sin, sizeof(sin));
        sin.sin_family = AF_UNIX;
        sin.sin_addr.s_addr = INADDR_ANY;
        sin.sin_port =htons(PORT_SERVER);

        if((s = socket(AF_UNIX, SOCK_STREAM, 0)) < 0) {
                perror("simplex-talk:socket");
                exit(1);
        }

        if(bind(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
                perror("simplex-talk:bind");
                exit(1);
        }

        listen(s, MAX_REQUEST);

        while(1) {
                if((new_s = accept(s, (struct sockaddr *)&sin, &len)) < 0 )
                        perror("simplex-talk:accept");
                        exit(1);
	}
                                                                                                                              19,1-8        Top
}
