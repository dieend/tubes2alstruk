#ifndef modusDocument_H
#define modusDocument_H

#include "find/find.h"
#include "list/list.h"
#include "exit/exit.h"
#include "new/new.h"
#include "delete/delete.h"
#include "../modusFile/modusFile.h"

void transferDirectory();
/* Memparsing dari system("dir") menjadi variable Dir */

void initDir();
/* Menginisiasi Dir dengan kosong, atau sesuai file input program */

void Find(command Command);
/* Melaksanakan command Find */

void Open(command Command);
/* Melaksanakan command Open */

void New(command Command);

#endif
