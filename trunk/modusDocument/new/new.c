#include "new.h"

void makeNew(command Command){
	char path[50];
	strcpy(path,"./files/");
	strcat(path,Command.param[1]);
	strcat(path,ekstensi);
	FILE * tmp = fopen(path, "w");
	fprintf(tmp, "#\n");
	fclose(tmp);
	transferDirectory();
}
