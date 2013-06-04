#include<stdio.h>
#include<stdlib.h>

#include"hash.h"

void PrintData(char *key, void *data, void *arg)
{
    printf("%s : %s\n", key, (char *)data);
    (*(int *)arg)++;
    return;
}

int test_hash(void)
{
    struct Hash *h;
    int len;
    h = Hash_Create();
    if (! h) {
        fprintf(stderr, "%s: Cannot allocate memory", "test_hash");
        exit(1);
    }

    Hash_PutData(h, "abcde", "efghi");
    Hash_PutData(h, "aaaaa", "bbbbb");

    printf("%s\n", (char *)Hash_GetData(h, "abcde"));
    printf("%s\n", (char *)Hash_GetData(h, "aaaaa"));

    len = 0;
    Hash_ForEach(h, PrintData, &len);
    printf("Len : %d\n", len);
    return 0;
}


int main(void)
{
    return test_hash();
}
