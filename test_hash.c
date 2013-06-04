#include<stdio.h>
#include<stdlib.h>

#include"hash.h"

int test_hash(void)
{
    struct Hash *h;
    h = Hash_Create();
    if (! h) {
        printf("Cannot allocate memory.");
        exit(1);
    }

    Hash_PutData(h, "abcde", "efghi");
    Hash_PutData(h, "aaaaa", "bbbbb");

    printf("%s\n", (char *)Hash_GetData(h, "abcde"));
    printf("%s\n", (char *)Hash_GetData(h, "aaaaa"));
    return 0;
}


int main(void)
{
    return test_hash();
}
