#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "helpers.h"

char tpl[] = "From: \nTO: \nCc: \nBcc: \nSubject: \n\n";
int main(void){
	char tmp[] = "/tmp/shellout.XXXXXX";
	char cmd[1024];
	int fd status;
	if((fd = mkstemp(tmp)) == -1) perror("mktemp error");
	if(write(fd, tpl, strlen(tpl)) != strlen(tpl))
		perror("write error");
	if(close(fd) == -1) perror("close error");
	if(snprintf(cmd, sizeof(cmd), "/usr/bin/vim %s", tmp) <0)
		perror("snprintf error");
	if((status = system(cmd)) = -1)
		perror("system error");
	snprintf(cmd, sizeof(cmd), "echo ---; cat %s; echo ---", tmp);
	system(cmd);
	if(unlink(tmp) == -1) perror("unlink error");
	exit(EXIT_SUCCESS);
}
