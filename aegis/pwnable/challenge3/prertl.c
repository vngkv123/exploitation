#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dlfcn.h>

void vuln(char *_buf){
	char msg[100];
	memcpy(msg, _buf, 0x100);
	printf("msg : %s\n", msg);
}

int main(int argc, char *argv[]){
	unsigned long address;
	char buf[0x100];
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	printf("Simple Retun-To-Libc Challenge\n");
	void *handle = dlopen("libc.so.6", RTLD_LAZY);
	printf("Library base address ( libc_base ) : %#lx\n", *(unsigned long *)handle);
	printf("Leave message");
	read(0, buf, 0x100);
	vuln(buf);
	return 0;
}
