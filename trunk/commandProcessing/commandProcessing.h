#ifndef command_H
#define command_H

#include "../modusDocument/modusDocument.h"
#include "../modusFile/modusFile.h"


void clean(command * Command);
/* Inisiasi Command menjadi kosong */

command readCommand();
/* Memparsing input menjavoid makeEmpty(area Area);di Command dengan argumen-argumennya */

int processCommandDocument(command Command);
/* Memproses Command untuk modus Document */

int processCommandFile(command Command);
/* Memproses Command untuk modus File */

#endif
