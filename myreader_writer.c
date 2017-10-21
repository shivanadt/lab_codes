#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/mman.h>

# define SIZE sizeof(int)
# define run_length 10

int main()
{
	pid_t pid;
	caddr_t shared_memory;
	int i_parent, i_child;
	int value;
	int status;

	shared_memory = mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1 , 0);
	if(shared_memory == (caddr_t) - 1) {
		printf("Error in Shared Memory\n");
		exit(1);
	}
	if((pid = fork()) < 0) {
		printf("Error in opening fork.\n");	
		exit(1);
	}
	if( pid == 0) {
		for(i_child = 1;i_child<= run_length;i_child++) {
			value = *shared_memory;
		 	printf(" child : %d\n",value);
			sleep(1);
		}
		printf("Exiting Child\n");
	} else {
		for(i_parent = 1;i_parent <= run_length;i_parent++) {
			*shared_memory = i_parent*i_parent;
			printf("parent : %d\n", value);
			sleep(1);
		}
		wait(pid);
		printf("Exiting Parent\n");
	}		
	return 0;
}
