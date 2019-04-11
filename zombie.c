#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

int main(void){
	pid_t pid;
	int i;

	for(i=0;i<5;i++){
		if((pid =fork())<0){
			perror("fork error");
		}else if(pid == 0){
			printf("hi from child %d: %d\n", i, getpid());
			exit(0);
		}
	}
	sleep(100);
 
	printf("hi from parent\n");
	return(0);
}
