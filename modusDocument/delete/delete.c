#include "delete.h"

void Delete(command Command){
	int i;
	char act[50];
	char fileDelete[50];
	boolean adaFile = false, deleteAll = false;
	
	strcpy(fileDelete,Command.param[1]);
	strcat(fileDelete,ekstensi);
	if (strlen(Command.param[1]) == 0) {
		deleteAll = true;
	}
	if (deleteAll) {
		printf("Are you sure to delete all files? (y/n) :  ");
		scanf("%s",act);
		if (act[0]=='n') return;
		strcpy(act,"del files\\*");
		strcat(act,ekstensi);
		strcat(act," > tmp");
		i = system(act);
		system("del tmp");
		transferDirectory();
		strcpy(Dir.sum,"0");	
	} else {	
		for (i=0; i<Dir.all; i++) {
			if (!strcmp(fileDelete,Dir.name[i])) {
				adaFile = true;
				break;
			}
		}
		
		if (adaFile) {
			strcpy(act,"del files\\");
			strcat(act,Command.param[1]);
			strcat(act,ekstensi);
			strcat(act,"> tmp");
			system(act);
			system("del tmp");
			transferDirectory();
		} else {
			printf("Can't found file!\n");
		}
	}
}


