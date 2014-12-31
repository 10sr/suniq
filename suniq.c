#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<getopt.h>

#include"counter.h"
#include"config.h"

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

void suniq_help(char* cmdname)
{
    fprintf(stderr, "%s: usage: %s [-h|--help] [-c|--count] [<filename>]",
            cmdname, cmdname);
    return;
}

int main(int argc, char** argv)
{
    char *cmdname = argv[0];
    int option;
    struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"count", no_argument, NULL, 'c'},
        {0, 0, 0, 0}
    };

#ifndef __CYGWIN__
    extern char *optarg;
    extern int optind, opterr;
#endif

    int f_count = 0;

    char *infile = "-";
    /* char *outfile = "-"; */

    while (1) {
        option = getopt_long(argc, argv, "ch", long_options, NULL);
        if (option == -1) {
            break;
        }

        switch (option) {
        case 'h':
            suniq_help(cmdname);
            return 0;
        case 'c':
            f_count = 1;
            break;
        }
    }

    argc -= optind;
    argv += optind;

    if (argc > 0) {
        infile = argv[0];
        freopen(infile, "r", stdin);
    }

    return suniq(stdin, '\n', f_count);
}
