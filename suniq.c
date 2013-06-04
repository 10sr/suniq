#include<stdio.h>

#include"counter.h"

char *ReadOneLine(int fd_input, char delim)
{
    /* Read one segment from fd_input. Input is separated by delim char.
     * At the end of input NULL is returned.
     */
    return NULL;
}

int suniq(int fd_input, char delim)
{
    char *line;
    line = ReadOneLine(fd_input, delim);
    
    while (line) {
        
}

int main(int argc, char** argv)
{
    return suniq(stdin, '\n');
}
