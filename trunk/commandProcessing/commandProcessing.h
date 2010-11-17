#ifndef command_H
#define command_H

#include "../modusDocument/modusDocument.h"


void clean(command * Command);

command readCommand();

int processCommandDocument(command Command);


#endif
