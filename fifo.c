#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    char* fifo="./test.fifo";
    umask(0);
    int ret=mkfifo(fifo,0664);
    if(ret<0){
        if(errno !=EEXIST){
        perror("mkfifo error");
        return -1;
        }
    }
    printf("-----start open----\n");
    int fd=open(fifo,O_RDONLY);
    printf("-----end open------\n");
    if(fd<0){
        perror("open error");
        return -1;
    }
    close(fd);
    return 0;
}
