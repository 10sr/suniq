/* hash.h --- Hash for strings. */

#ifndef _HASH_H_
#define _HASH_H_

#include<limits.h>

#define HASH_LEN 100000

struct _HashData {
    char *key;
    void *data;
    struct _HashData *next;
};

struct Hash {
    struct _HashData **a;
    char **keys;
    int len;
};

struct Hash *Hash_Create(void);

void Hash_Destroy(struct Hash *h);

/* Get data of s. If none return NULL.
 * This hash cannot distinguish "no key" and "null value".
 */
void *Hash_GetData(struct Hash *hash, char *key);

/* Put data of s. Pointer data is used directly so you must care about lifetime
 * of referenced space.
 * Keys are duplicated.
 * Return 0 if suceeded, non-zero otherwise.
 */
int Hash_PutData(struct Hash *hash, char *key, void *data);

#endif
