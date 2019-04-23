#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAXLINE 1024
int main(void){
	int n, fd[2];
	pid_t pid;
	char line[MAXLINE];

	if(pipe(fd) < 0)
		perror("pipe error");
	if((pid = fork()) < 0){
		perror("fork error");
	}else if(pid > 0){
		close(fd[0]);
		write(fd[1], "Hello, World!\n", 14);
	}else{
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);
	}
	return 0;
}
