#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>

#define DEF_PAGER "/bin/more"
#define MAXLINE 1024
int main(int argc, char *argv[]){
	int n, fd[2];
	pid_t pid;
	char *pager, *argv0;
	char line[MAXLINE];
	FILE *fp;

	if(argc !=2)
		perror("Usage: pagere-pipe FILE");
	if((fp = fopen(argv[1], "r")) == NULL)
		perror("fopen error");
	if(pipe(fd) < 0)
		perror("pipe error");
	if((pid = fork()) < 0)
		perror("fork error");
	else if(pid > 0){
		close(fd[0]);
		while(fgets(line, MAXLINE, fp) != NULL)
			perror("write error");
	}
	if(ferror(fp))
		perror("fgets error");
	close(fd[1]);
	if(waitpid(pid, NULL, 0) < 0)
		perror("waitpid error");
}
		
