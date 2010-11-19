#ifndef modusFile_H
#define modusFile_H

#include "../commandProcessing/commandProcessing.h"
#include "strukturData/worksheet.h"
#include "../global/variable.h"

void transferCell(FILE * processedFile);
void doModusFile(FILE * processedFile);

#endif
