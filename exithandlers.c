#include<stdio.h>
#include<stdlib.h>

void my_exit1(void){printf("first exit handler\n");}
void my_exit2(void){printf("escond exit handler\n");}

int main(void){
	if(atexit(my_exit2) != 0)
		perror("can't register my_exit2");
	if(atexit(my_exit1) != 0)
		perror("can't register my_exit1");
	if(atexit(my_exit1) != 0)
		perror("can't register my_exit1");
	printf("main is done\n");
	return 0;
}
