#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int pid, pid2;
	int status;
	int status1;
	pid = fork();
	if(pid  == 0) {
		pid2 = fork();
		if(pid2 == 0) {
			printf("We are in child process with pid = %d\n",getpid());
			sleep(3);
			exit(0);
		} else {
			printf("We are in parent process with pid = %d\n",getpid());
			pid2 = wait(&status);
			printf("%d\n",pid2);
		}
	} else {
		pid = wait(&status1);
		execlp("ls","",NULL);
	
	}
	return 0;
}
