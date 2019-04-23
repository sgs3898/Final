#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

char *cmd = "grep zack /etc/passwd | cut -f 5 -d:";

int main(void){
	int status;
	if((status = system(cmd)) == -1)
		perror("ststem error");
	exit(status);
	if(WIFEXITED(status))
		printf("normal termination, exit status = %d\n",
				WEXITSTATUS(status));
	else if(WIFSGNALED(status))
		printf("abnormal termaination, signal number = %d\n",
				WTERMSIG(status));
	return 0;
}
