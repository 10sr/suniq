#include"hash.h"

struct Hash *Hash_Create(void)
{
    struct Hash *new;

    new = malloc(sizeof(struct Hash));
    if (! new) {
        return NULL;
    }

    new->len = 0;

    new->a = malloc(sizeof(struct Hash *) * HASH_LEN);
    if (! new->a) {
        free(new);
        return NULL;
    }

    new->keys = NULL;

    return new;
}

void *Hash_GetData(struct Hash *hash, char *key)
{
    int num;
    struct _HashData *d;

    num = _hash(key);

    d = hash->a[num];

    while (d) {
        if (strcmp(d->key, key) == 0) {
            return d->data;
        } else {
            d = d->next;
        }
    }
    return NULL;
}

void Hash_PutData(struct Hash *hash, char *key, void *data)
{
    return;
}
