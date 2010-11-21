#ifndef modusFile_H
#define modusFile_H

#include "../commandProcessing/commandProcessing.h"
#include "strukturData/worksheet.h"
#include "../global/variable.h"
#include "save/save.h"	
extern char pathFile[50];
boolean adaKoma(char cek[]);
boolean angkaSemua(char cek[]);
void transferCell();
void doModusFile(char path[50]);

void Display(command Command);
void Write(command Command);
void Remove(command Command);
void Evaluate(command Command);

#endif
