/*
    Realtek Semiconductor Corp Sim card reader
    @author : hamza naper
    @site : www.naper.eu

*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>
#include <string.h>
#include <errno.h>

#define DEFAULT_DEVICE		"/dev/sdb"
#define B_LENGHT            7 				/*  from usb sim card instruction*/

void send_cmd(int fd, int cmd)
{
	int retval = 0;

	retval = write(fd, &cmd, 1);
	if (retval < 0)
		fprintf(stderr, "could not send command to fd=%d\n", fd);
}
int read_data(int fd, int data){
	int retval = 0;

	retval = read(fd, &data, B_LENGHT);

	if (retval < 0)
		fprintf(stderr, "could not read command\n");

}
void mount_drive(){
	if (mount(DEFAULT_DEVICE, "/mnt/sd", "vfat", MS_NOATIME, NULL)) {
    	if (errno == EBUSY) {
        	printf("Mountpoint busy");
    	} else {
        	printf("Mount error: %s", strerror(errno));
    	}
	} else {
    	printf("Mount successful");
	}
}
int check_drive(){
	/* if SC drive is plugged using dmesg*/
	FILE * dm = NULL;
	char * data = NULL;
	system("dmesg >> tmp_dmesg");
	dm = fopen("tmp_dmesg","r");
	if(!dm){
		printf("Error while opening tmp_dmesg\n");
	}else{
		fscanf(dm, "%s\n",data);
		if(strstr(data,"plugged")){
			return 1;
		}else{
			return 0;
		}
	}
	fclose(dm);
	return 0;
}
int main(int argc, char *argv[])
{
	char c;
	int fd;
	char *dev = DEFAULT_DEVICE;
	int data;

	printf("Open device %s\n", dev);
	fd = open(dev, O_RDWR);
	if (fd == -1) {
		perror("open");
		exit(1);
	}
	mount_drive();
	read_data(fd, data);
	printf("data %d \n",data);
	
	close(fd);

	return EXIT_SUCCESS;
}

