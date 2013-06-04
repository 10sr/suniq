#include<stdio.h>

#include"counter.h"

int test_counter(void)
{
    struct Counter *c;

    c = Counter_Create();

    Counter_AddStr(c, "abc");
    Counter_AddStr(c, "abc");
    Counter_AddStr(c, "abcde");
    Counter_AddStr(c, "eeeeeeee");
    Counter_AddStr(c, "abcde");
    Counter_AddStr(c, "abc");
    Counter_AddStr(c, "abcde");
    Counter_AddStr(c, "abcde");
    Counter_AddStr(c, "eeeeeeee");
    Counter_AddStr(c, "abc");
    Counter_AddStr(c, "abc");

    Counter_Print(c, stdout, 1);

    Counter_Destroy(c);
    return 0;
}

int main(void){
    return test_counter();
}
