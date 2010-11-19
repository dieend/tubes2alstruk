#ifndef command_H
#define command_H

#include "../modusDocument/modusDocument.h"
#include "../modusFile/modusFile.h"


void clean(command * Command);
/* Inisiasi Command menjadi kosong */

command readCommand();
/* Memparsing input menjadi Command dengan parameternya */

int processCommandDocument(command Command);
/* Memproses Command */

int processCommandFile(command Command);

#endif
