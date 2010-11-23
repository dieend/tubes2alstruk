#ifndef modusFile_H
#define modusFile_H

#include "../commandProcessing/commandProcessing.h"
#include "strukturData/worksheet.h"
#include "../global/variable.h"
#include "save/save.h"	
#include "display/display.h"
#include "write/write.h"
#include "remove/remove.h"
extern char pathFile[50];
boolean adaKoma(char cek[]);
boolean angkaSemua(char cek[]);
void transferCell();
void doModusFile(char path[50]);
void insert(addressCell Cell, char isi[]);
void Evaluate(command Command);

#endif
