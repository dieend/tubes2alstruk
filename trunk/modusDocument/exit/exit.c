#include "exit.h"

void Exit(){
	int i;
	fprintf(FXINT,"files #\n");
	for (i=0; i<Dir.all; i++) {
		fprintf(FXINT,"%s %s %s %s #\n", Dir.name[i], Dir.date[i], Dir.hour[i], Dir.size[i]);
	}
	fprintf(FXINT,"#\n");
	fclose(FXINT);
}
