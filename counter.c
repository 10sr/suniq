#include<stdint.h>
#include<stdlib.h>

#include"counter.h"

struct Counter *Counter_Create(void)
{
    struct Counter *new;

    new = malloc(sizeof(struct Counter));

    if (new) {
        new->hash = Hash_create();

        if (new->hash) {
            return new;
        } else {
            free(new);
    }

    return NULL;
    }

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
