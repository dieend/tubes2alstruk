#include "modusFile.h"

void transferCell(FILE * processedFile) {
	char tmp[50];
	fscanf(processedFile,"%s", tmp);
}

void doModusFile(FILE * processedFile){
	alokasiWorksheet();
	transferCell(processedFile);
	do{
		printf(">>");
	} while (processCommandFile(readCommand()));
}

void Save(){
}

void Display(command Command){
}

void Write(command Command){
}
void Remove(command Command){
}
void Evaluate(command Command){
}
