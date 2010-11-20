#include "modusDocument.h"


void initDir(){
	transferDirectory();
}

void transferDirectory() {
	int i = 0;
	FILE * akses;
	char tmp[50];
	system("ls -l files > tmp");
	akses = fopen("tmp","r");
	fscanf(akses,"%*[^\n]\n");
	while (fscanf(akses,"%s", tmp) != EOF) {
		fscanf(akses,"%s %s %s",tmp,tmp,tmp);
		fscanf(akses,"%s",Dir.size[i]);
		fscanf(akses,"%s",Dir.date[i]);
		fscanf(akses,"%s",Dir.hour[i]);
		fscanf(akses,"%s",Dir.name[i++]);
	}
	fclose(akses);
	system("du -shS files > tmp");
	akses = fopen("tmp","r");
	fscanf(akses,"%s",Dir.sum);
	Dir.all = i;
	fclose(akses);	
	system("rm tmp");
}

void Find(command Command){
	if (strcmp(Command.param[1],"name")) searchName(Command.param[2]); else
	if (strcmp(Command.param[1],"date")) searchDate(Command.param[2]); else
	if (strcmp(Command.param[1],"size")) searchSize(Command.param[2]);
}


void Open(command Command){
	char path[50];
	FILE * processedFile;
	strcpy(path,"files/");
	strcat(path,Command.param[1]);
	strcat(path,ekstensi);
	processedFile = fopen(path,"r");
	doModusFile(processedFile);
}

void New(command Command) {
	makeNew(Command);
	Open(Command);
}
