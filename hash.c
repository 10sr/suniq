#include"hash.h"

#include<string.h>
#include<stdlib.h>

/* http://www.tokumaru.org/techterm/hash.html */

long _hash(char *s)
{
    int i;
    int long h;
    int L = strlen(s);

    h = 0;
    for (i = 0; i < L; i++) {
        h = h * 37 + s[i];
    }
    return labs(h);
}

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

    num = _hash(key) % HASH_LEN;

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

struct _HashData *_HashData_Create(char *key, void *data)
{
    /* Duplicate key and make _HashData. Return NULL when fails. */
    struct _HashData *new;
    new = malloc(sizeof(struct _HashData));
    if (new) {
        new->key = strdup(key);
        if ( new->key ) {
            new->data = data;
            new->next = NULL;
            return new;
        } else {
            free(new);
            return NULL;
        }
    } else {
        return NULL;
    }
}

int Hash_PutData(struct Hash *hash, char *key, void *data)
{
    int num;

    num = _hash(key) % HASH_LEN;

    if (hash->a[num]) {
        struct _HashData *current;
        current = hash->a[num];
        while (1) {
            if (strcmp(key, current->key) == 0) {
                /* key already exists */
                current->data = data;
                return 0;
            } else if (current->next) {
                /* another key exists in num */
                current = current->next;
            } else {
                /* key not exists yet */
                struct _HashData *new;
                new = _HashData_Create(key, data);
                if (new) {
                    current->next = new;
                    return 0;
                } else {
                    return 1;
                }
            }
        }
    } else {
        struct _HashData *d;
        d = _HashData_Create(key, data);
        if (d) {
            hash->a[num] = d;
            return 0;
        } else {
            return 1;
        }
    }
    return 1;
}

void Hash_ForEach(struct Hash *hash,
                  void (*func)(char *key, void *data, void *arg),
                  void *arg)
{
    int i;
    struct _HashData *current;

    for (i = 0; i < HASH_LEN; i++) {
        current = hash->a[i];
        while (current) {
            (*func)(current->key, current->data, arg);
            current = current->next;
        }
    }
    return;
}
