
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>

int main(int argc, char* argv[]) {
	int fd;	
	int DTR_flag = TIOCM_DTR ; 
	if (argc < 2) {
		printf("Specify serial device");
		return 1;
	}

	fd = open(argv[1],O_RDWR | O_NOCTTY );
                                       
	if(fd == -1) {
		printf("Error Opening serial.\n");
	} else {
		printf("Serial Opened Successfully.\n");
	}

	ioctl(fd,TIOCMBIC,&DTR_flag);
	printf("Set DTR 1\n");
}
