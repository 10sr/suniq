/* hash.h --- Hash for strings. */

#ifndef _HASH_H_
#define _HASH_H_

struct _HashData {
    char *key;
    void *data;
    struct _HashData *next;
};

struct Hash {
    struct _HashData **a;
    int len;
};

/* Create new hash. Return NULL if fails.
 * hash_len is size of hash array.
 */
struct Hash *Hash_Create(int hash_len);

void Hash_Destroy(struct Hash *hash);

/* Get data of s. If none return NULL.
 * So this hash cannot distinguish "no key" and "null value".
 */
void *Hash_GetData(struct Hash *hash, char *key);

/* Put data of key. Data referenced by data is used without copying it so you
 * must care about lifetimes of referenced spaces.
 * Keys are duplicated.
 * Return 0 if suceeded, non-zero otherwise.
 */
int Hash_PutData(struct Hash *hash, char *key, void *data);

/* Apply func for each data in hash. func must accept three argument,
 * char *key and void *data and void *arg. Returned values are ignored.
 */
void Hash_ForEach(struct Hash *hash,
                  void (*func)(char *key, void *data, void *arg),
                  void *arg);

#endif
