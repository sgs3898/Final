#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(void){
	pid_t pid;

	printf("before fork(): %d\n", getpid());
	if((pid = fork())<0){
		perror("error from pork");
	}else if(pid == 0){/* child*/
		printf("hi from child! %d\n",
				getpid());
	}else{  /*parent */
		printf("hi form parent! %d\n", getpid());
	}
	printf("bye %d\n", getpid());
	exit(EXIT_SUCCESS);
}
