#include<stdio.h>
#include<stdlib.h>

#include"counter.h"

const int BUF_LEN = 10000;

int ReadOneLine(FILE *fp_input, char delim, char *out, int len)
{
    /* Read one segment from fd_input. Input is separated by delim char.
     * At the end of input returns 1, otherwise return 0.
     */
    int i;
    int c;

    for (i = 0; i < len; i++) {
        c = fgetc(fp_input);
        if ((int)delim == c) {
            out[i] = '\0';
            return 0;
        } else if (c == EOF) {
            out[i] = '\0';
            return 1;
        }
        out[i] = (char)c;
    }
    fprintf(stderr, "%s: Too long line", "suniq");
    exit(1);
    return 1;
}

int suniq(FILE *fp_input, char delim, int print_num)
{
    char line[BUF_LEN];
    int r;
    struct Counter *c;

    c = Counter_Create();
    if (! c) {
        fprintf(stderr, "%s: Cannot allocate memory", "suniq");
        exit(1);
    }

    r = ReadOneLine(fp_input, delim, line, BUF_LEN);

    while (r == 0) {
        Counter_AddStr(c, line);
        /* printf("%s\n", line); */
        r = ReadOneLine(fp_input, delim, line, BUF_LEN);
    }

    Counter_Print(c, stdout, print_num);
    return 0;
}

int main(int argc, char** argv)
{
    return suniq(stdin, '\n', 1);
}
