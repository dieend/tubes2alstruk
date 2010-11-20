#ifndef modusFile_H
#define modusFile_H

#include "../commandProcessing/commandProcessing.h"
#include "strukturData/worksheet.h"
#include "../global/variable.h"


void transferCell(FILE * processedFile);
void doModusFile(FILE * processedFile);

void Save();
void Display(command Command);
void Write(command Command);
void Remove(command Command);
void Evaluate(command Command);

#endif
