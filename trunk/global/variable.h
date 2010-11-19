#ifndef variable_H
#define variable_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "boolean.h"
#define DEBUG printf("OK")

#define ekstensi ".xcl"

#define MAXSIZE 50
#define Nil NULL

typedef struct {
	char param[5][MAXSIZE];
} command;

typedef struct {
	char date[20][12];
	char hour[20][7];
	char size[20][20];
	char name[20][50];
	char sum[20];
	int all;
} directory;


extern FILE * FXINT;
extern directory Dir;

#endif
