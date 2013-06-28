#include<stdint.h>
#include<stdlib.h>

#include"counter.h"

struct Counter *Counter_Create(void)
{
    struct Counter *new;

    new = malloc(sizeof(struct Counter));

    if (new) {
        new->hash = Hash_Create(0);

        if (new->hash) {
            return new;
        } else {
            free(new);
        }
        return NULL;
    }

    return NULL;
}

void Counter_Destroy(struct Counter *c)
{
    Hash_Destroy(c->hash);
    free(c);
    return;
}

void Counter_AddStr(struct Counter *c, char *s)
{
    uintptr_t current;

    current = (uintptr_t)Hash_GetData(c->hash, s);
    Hash_PutData(c->hash, s, (void *)(current + 1));
    return;
}

static void _PrintLine(char *key, void *data, void *_arg)
{
    intptr_t *arg;
    int print_num;
    FILE *fp;

    arg = (intptr_t *)_arg;

    print_num = arg[0];
    fp = (FILE *)arg[1];

    if (print_num) {
        fprintf(fp, "%7ld ", (uintptr_t)data);
    }
    fprintf(fp, "%s\n", key);
    return;
}

void Counter_Print(struct Counter *c, FILE *fp, int print_num)
{
    intptr_t arg[2];
    arg[0] = print_num;
    arg[1] = (intptr_t)fp;
    Hash_ForEach(c->hash, _PrintLine, arg);
    return;
}
