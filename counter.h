#ifndef _COUNTER_H_
#define _COUNTER_H_

#include<stdio.h>

#include"hash.h"

struct Counter {
    struct Hash *hash;
};

struct Counter *Counter_Create(void);

void Counter_Destroy(struct Counter *c);

void Counter_AddStr(struct Counter *c, char *s);

void Counter_Print(struct Counter *c, FILE *fp, int print_num);

#endif
