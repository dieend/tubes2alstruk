#include "delete.h"

void Delete(command Command){
	int i;
	char act[50];
	char fileDelete[50];
	boolean adaFile = false, deleteAll = false;
	
	sstrcpy(fileDelete,Command.param[1]);
	sstrcat(fileDelete,ekstensi);
	if (sstrlen(Command.param[1]) == 0) {
		deleteAll = true;
	}
	if (deleteAll) {
		printf("Are you sure to delete all files? (y/n) :  ");
		scanf("%s",act);
		if (act[0]=='n') return;
		sstrcpy(act,"rm files/*");
		sstrcat(act," > tmp");
		system(act);
		system("rm tmp");
		transferDirectory();
		sstrcpy(Dir.sum,"0");	
	} else {	
		for (i=0; i<Dir.all; i++) {
			if (!sstrcmp(fileDelete,Dir.name[i])) {
				adaFile = true;
				break;
			}
		}
		
		if (adaFile) {
			sstrcpy(act,"rm files/");
			sstrcat(act,Command.param[1]);
			sstrcat(act,ekstensi);
			sstrcat(act,"> tmp");
			system(act);
			system("rm tmp");
			transferDirectory();
		} else {
			printf("Can't found file!\n");
		}
	}
}
