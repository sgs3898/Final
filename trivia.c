#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
	pid_t pid;

	if ((pid = fork()) < 0){
		perror("fork error");
	}else if(pid == 0){
		if ((pid = fork()) < 0)
			perror("fork error");
		else if(pid > 0)
			return 0;
		sleep(2);
		printf("2nd child, parent pid = %d\n", getppid());
		return 0;
	}
	if(waitpid(pid, NULL, 0) != pid)
		perror("waitpid error");
	return 0;
}
