#include "commandProcessing.h"

void clean(command * Command){
	int i;
	for (i=0; i<5; i++) {
		strcpy( (*Command).param[i] , "");
	}
}

command readCommand() {
	char tmp[MAXSIZE];
	int i = 0;
	command Command;
	clean(&Command);
	scanf("%s", tmp);
	if (tmp[0] == '=') {
		while (strcmp(tmp,"#")) {
			strcat(Command.param[i], tmp);
			scanf("%s",tmp);
		}
	} else {
		while (strcmp(tmp,"#")) {
			strcpy(Command.param[i++], tmp);
			scanf("%s",tmp);
		}
	}
	return Command;
}

int processCommandDocument(command Command){
	if (!strcmp(Command.param[0],"list")) List();
	else if (!strcmp(Command.param[0],"find")) Find(Command);
	else if (!strcmp(Command.param[0],"delete")) Delete(Command);
	else if (!strcmp(Command.param[0],"new")) New(Command);
	else if (!strcmp(Command.param[0],"open")) Open(Command);
	else if (!strcmp(Command.param[0],"exit")) {
		Exit();
		return 0;
	}
	else printf("Command error\n");
	return 1;
}

int processCommandFile(command Command) {
	if (!strcmp(Command.param[0],"save")) Save(); else
	if (!strcmp(Command.param[0],"display")) Display(Command); else
	if (!strcmp(Command.param[0],"close")) return 0; else
	if (!strcmp(Command.param[0],"write")) Write(Command); else
	if (!strcmp(Command.param[0],"remove")) Remove(Command); else
	if (Command.param[0][1] == '=') Evaluate(Command); else
	printf("Invalid Command!\n");	
	return 0;
}
