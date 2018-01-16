#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int main(int argc, char *argv[]){
	unsigned char buf[0x100] = {0, };
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	printf("This is Simple 64bit pwnable challenge !\n");
	printf("Just generate 64bit shellcode !\n");
	void *rwx_page = mmap(0, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	read(0, buf, 0x100);
	for(int i = 0; i < 0x100; i++){
		buf[i] = buf[i] ^ (rand() & 0xff);
	}
	memcpy(rwx_page, (void *)buf, 0x100);
	((void (*)())rwx_page)();
	return 0;
}
