#ifndef command_H
#define command_H

#include "../modusDocument/modusDocument.h"


void clean(command * Command);
/* Inisiasi Command menjadi kosong */

command readCommand();
/* Memparsing input menjadi Command dengan parameternya */

int processCommandDocument(command Command);
/* Memproses Command */

#endif
