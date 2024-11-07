#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main() {
    int fd;
    fd = open("/dev/led1", O_WRONLY);
    char cmd;
    do {
        printf("Input \'1\' to turn on the LED1, \'0\' to turn off, \'2\' to exit.\n");
        scanf(" %c", &cmd);
        printf("Inputted \'%c\'.\n", cmd);
        if (cmd == '2') break;
        write(fd, &cmd, 1);
    } while (1);
    close(fd);
    exit(EXIT_SUCCESS);
} 
