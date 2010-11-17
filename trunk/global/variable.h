#ifndef variable_H
#define variable_H

#include <stdio.h>
#include <string.h>
#include "boolean.h"
#define ekstensi ".xcl"


#define MAXSIZE 50
typedef struct {
	char param[5][MAXSIZE];
} command;

typedef struct {
	char date[20][12];
	char hour[20][7];
	char size[20][20];
	char name[20][50];
	int all;
} directory;

extern FILE * FXINT;
extern directory Dir;
#endif
