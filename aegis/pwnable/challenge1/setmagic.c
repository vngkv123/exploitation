#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void auth(){
	unsigned char key[] = "M4k1ng_A3gis_t0p_security_Research_Group";
	unsigned char cipher[] = {10, 112, 41, 110, 95, 20, 0, 44, 92, 20, 29, 44, 47, 68, 71, 67, 45, 21, 16, 15, 42, 6, 6, 68, 21, 0, 59, 11, 44, 17, 9, 23, 60, 31, 48, 53, 30, 11, 84, 81};
	int fd = open("/dev/urandom", O_RDONLY);
	if( fd < 0 ){
		perror("open");
		exit(-1);
	}
	unsigned int password, secret;
	read(fd, &secret, 4);
	scanf("%u", &password);

	if( password == secret ){
		for( int i = 0; i < 40; i++ ){
			printf("%c", cipher[i] ^ key[i]);
		}
	}

	else{
		printf("Wrong !\n");
		exit(-1);
	}
}

int main(int argc, char *argv[]){
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
	printf("Simple pwn challenge 1\n");
	auth();
	return 0;
}
