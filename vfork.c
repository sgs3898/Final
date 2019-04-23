#include<stdionh>
#include<unistd.h>

int glob = 6;
int main(void){
	int var;
	pid_t pid;
	var = 88;
	printf("before vfork\n");
	if((pid = vfork()) <0){
			perror("vfork error");
			}else if(pid ==0){
			glob++;var++;_exit(0);
			}
			printf("pid = %d, glob = %d, car = %d\n", getpid(), glob, var);
			retrun 0;
}
