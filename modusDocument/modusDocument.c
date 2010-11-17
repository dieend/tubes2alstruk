#include "modusDocument.h"

void initDir(){
	int i = 0;
	char dum[10];
	fscanf(FXINT,"%*[^\n]\n");
	fscanf(FXINT,"%s", Dir.name[i]);
	while (strcmp(Dir.name[i],"#")) {
		printf("%s\n",Dir.name[i]);
		fscanf(FXINT,"%s %s %s %s",Dir.date[i],Dir.hour[i],Dir.size[i],dum);
		printf("%s %s %s %s\n",Dir.date[i],Dir.hour[i],Dir.size[i],dum);
		i++;
		fscanf(FXINT,"%s", Dir.name[i]);
	}
	Dir.all = i;
}

void transferDirectory() {
	system("dir \"./files/\" /a-d > tmp.txt");
	FILE * akses = fopen("tmp.txt","r");
	int i = 0;
	char tmp[50];
	fscanf(akses,"%*[^\n]\n");
	fscanf(akses,"%*[^\n]\n");
	fscanf(akses,"%*[^\n]\n");
//	fscanf(akses,"%*[^\n]\n");
//	fscanf(akses,"%*[^\n]\n");
	fscanf(akses,"%s", tmp);
	while (strlen(tmp) == 10) {
		strcpy(Dir.date[i],tmp);
		fscanf(akses,"%s",Dir.hour[i]);
		fscanf(akses,"%s",Dir.size[i]);
		fscanf(akses,"%s",Dir.name[i++]);
		fscanf(akses,"%s", tmp);
	}
	Dir.all = i;
	fclose(akses);	
//	system("del tmp.txt");
}

void List(){
	double sum = 0;
	int i;
	printf("files\n");
	for (i=0; i<Dir.all; i++) {
		printf("%s %s %s %.2lf\n", Dir.name[i], Dir.date[i], Dir.hour[i], Dir.size[i]);
	}
	printf("Banyaknya file = %d\n", Dir.all);
	printf("Ukuran directory = %.2lf\n", sum);
}

void Find(command Command){
}

void Delete(command Command){
	int i;
	char act[50];
	boolean ada = false;
	
	if (strlen(Command.param[1]) == 0) {
		system("cd files");
		strcpy(act,"del ");
		strcat(act,"*.*");
		strcat(act,"\"");
		system(act);
		system("cd ..");
		transferDirectory();
		return;
	}
	
	for (i=0; i<Dir.all; i++) {
		if (!strcmp(Command.param[1],Dir.name[i])) {
			ada = true;
			break;
		}
	}
	if (ada) {
		system("cd files");
		strcpy(act,"del ");
		strcat(act,Command.param[1]);
		system(act);
		system("cd ..");
		transferDirectory();
	} else {
		printf("Can't found file!\n");
	}
}

void New(command Command){
	char path[50];
	strcpy(path,"./files/");
	strcat(path,Command.param[1]);
	strcat(path,ekstensi);
	FILE * tmp = fopen(path, "w");
	fprintf(tmp, "#\n");
	fclose(tmp);
	transferDirectory();
	Open(Command);
}

void Open(command Command){
}

void Exit(){
	int i;
	fprintf(FXINT,"files #\n");
	for (i=0; i<Dir.all; i++) {
		fprintf(FXINT,"%s %s %s %s #\n", Dir.name[i], Dir.date[i], Dir.hour[i], Dir.size[i]);
	}
	fprintf(FXINT,"#\n");
	fclose(FXINT);
}
