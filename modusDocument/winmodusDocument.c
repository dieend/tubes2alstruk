#include "modusDocument.h"


void initDir(){
	transferDirectory();
}

void transferDirectory() {
	int i = 0;
	FILE * akses;
	char tmp[50];
	system("dir \"./files/\" /a-d > tmp");
	akses = fopen("tmp","r");
	fscanf(akses,"%*[^\n]\n");
	fscanf(akses,"%*[^\n]\n");
	fscanf(akses,"%*[^\n]\n");
	fscanf(akses,"%s", tmp);
	while (strlen(tmp) == 10) {
		strcpy(Dir.date[i],tmp);
		fscanf(akses,"%s",Dir.hour[i]);
		fscanf(akses,"%s",Dir.size[i]);
		fscanf(akses,"%s",Dir.name[i++]);
		fscanf(akses,"%s", tmp);
	}
	fscanf(akses,"%s %s",tmp, Dir.sum);
	Dir.all = i;
	fclose(akses);	
	system("del tmp");
}

void Find(command Command){
	if (strcmp(Command.param[1],"name")) searchName(Command.param[2]); else
	if (strcmp(Command.param[1],"date")) searchDate(Command.param[2]); else
	if (strcmp(Command.param[1],"size")) searchSize(Command.param[2]);
}


void Open(command Command){
	char path[50];
	strcpy(path,"files/");
	strcat(path,Command.param[1]);
	strcat(path,ekstensi);
	doModusFile(path);
}

void New(command Command) {
	makeNew(Command);
	Open(Command);
}
