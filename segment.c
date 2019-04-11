#include<stdio.h>
#include<stdlib.h>

int magic = 42;
char crap[1024];

void func(int arg){
	printf("stack segment near \t%p\n", &arg);
}
int main(int argc, char **argv){
	char *ptr;
	ptr = malloc(1);
	func(42);
	printf("heap segment near\t%p\n", ptr); //start address of the allocated memort (100 bytes) int the heap segment by malloc()
	printf("bss segment near\t%p\n", crap);
	printf("text segment near\t%p\n", &magic);

	free(ptr);
	exit(EXIT_SUCCESS);
}
