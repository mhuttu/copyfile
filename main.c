#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    //FILE *inp, *outp;
    int inp, outp;

    ssize_t nr;
    char buf[BUFFER_SIZE];

    if (argc != 3) {
        puts("Usage: copy1 INFILE OUTFILE");
        exit(1);
    }
    inp = open(argv[1], O_RDONLY);
    if (!inp) {perror("Could not open infile for reading\n");
        exit(2);
        }
        outp = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR |S_IWUSR);
        if ( outp == -1) {
        perror("Could not open outfile for writing\n");
        exit(2);
        }
        while ((nr = read(inp, buf, BUFFER_SIZE)) > 0 )
            if(write(outp, buf, nr)!=nr)
                 perror("Problem writing to file");

    close(outp);
    close(inp);
    return 0;
}
