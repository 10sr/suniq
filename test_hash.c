#include<stdio.h>
#include<stdlib.h>

#include"hash.h"

void PrintData(char *key, void *data, void *arg)
{
    printf("%s : %s\n", key, (char *)data);
    return;
}

int test_hash(void)
{
    struct Hash *h;
    h = Hash_Create();
    if (! h) {
        fprintf(stderr, "%s: Cannot allocate memory", "test_hash");
        exit(1);
    }

    Hash_PutData(h, "abcde", "efghi");
    Hash_PutData(h, "aaaaa", "bbbbb");

    printf("%s\n", (char *)Hash_GetData(h, "abcde"));
    printf("%s\n", (char *)Hash_GetData(h, "aaaaa"));

    Hash_ForEach(h, PrintData, NULL);
    return 0;
}


int main(void)
{
    return test_hash();
}
