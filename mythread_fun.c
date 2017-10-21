#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sum ;

void *thread_func(void *num);
void *thread_func(void *num)
{
        int n = atoi(num);
	int i;
        if(n < 0) {
                printf("Error\n");
                return;
        } else {
                for(i = 0;i<= n;i++)
                sum = sum + i;
        }
        pthread_exit(0);

}


int main(int argc, char *argv[]) {
	pthread_t t1;
	int n;
	if(argc != 2) {
	printf("ERROR!!!\n");
	exit(1);
	}
	if(atoi(argv[1]) < 0) {
		printf("ERROR!!");
		exit(1);
	}
	pthread_create(&t1, NULL, thread_func, argv[1]);
	pthread_join(t1, NULL);
	printf("%d\n",sum);
	printf("Exiting thread\n");
	return 0;

}

