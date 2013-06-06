#include<stdio.h>
#include<stdlib.h>

#include"counter.h"

const int BUF_LEN = 10000;

static int _ReadOneLine(FILE *fp_input, char delim, char *out, int len)
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

static int suniq(FILE *fp_input, char delim, int print_num)
{
    char line[BUF_LEN];
    int r;
    struct Counter *c;

    c = Counter_Create();
    if (! c) {
        fprintf(stderr, "%s: Cannot allocate memory", "suniq");
        exit(1);
    }

    r = _ReadOneLine(fp_input, delim, line, BUF_LEN);

    while (r == 0) {
        Counter_AddStr(c, line);
        /* printf("%s\n", line); */
        r = _ReadOneLine(fp_input, delim, line, BUF_LEN);
    }
    Counter_AddStr(c, line);

    Counter_Print(c, stdout, print_num);

    Counter_Destroy(c);
    fclose(stdin);
    return 0;
}

int main(int argc, char** argv)
{
    char *infile = "-";
    /* char *outfile = "-"; */

    if (argc >= 2) {
        /* printf("argc: %d, input: %s\n", argc, argv[1]); */
        infile = argv[1];
        freopen(infile, "r", stdin);
    }

    return suniq(stdin, '\n', 1);
}
