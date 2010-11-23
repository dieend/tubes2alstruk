#include "new.h"

void makeNew(command Command){
	char path[50];
	sstrcpy(path,"./files/");
	sstrcat(path,Command.param[1]);
	sstrcat(path,ekstensi);
	FILE * tmp = fopen(path, "w");
	fprintf(tmp, "#\n");
	fclose(tmp);
	transferDirectory();
}
