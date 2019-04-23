#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void ch(char *str){
	char *ptr;
	int c;
	setbuf(stdout, NULL);
	for(ptr = str; (c = *ptr++) != 0;)
		putc(c, stdout);
}
int main(void){
	pid_t pid;
	if((pid = fork()) < 0) perror("fork error");
	else if(pid == 0){
		ch("output from child\n");
	}else{
		ch("output from parent\n");
	}
	return(0);
}
