#include "modusFile.h"

char  pathFile[50];

boolean adaKoma(char cek[]) {
	int len = strlen(cek);
	int i;
	for (i=0; i<len; i++){
		if (cek[i] =='.') return true;
		if ('0' <= cek[i] && cek[i] <='9') continue;
		return false;
	}
	return false;
}

boolean angkaSemua(char cek[]) {
	int len = strlen(cek);
	int i;
	for (i=0; i<len; i++) {
		if (!('0' <= cek[i] && cek[i] <='9')) return false;
	}
	return true;
}

void transferCell() {
	FILE * processedFile = fopen(pathFile,"r");
	char kol[50],isi[100];
	int baris;
	addressCell Cell;
	fscanf(processedFile,"%s",kol);
	while (strcmp(kol,"#")) {
		fscanf(processedFile,"%d : %s",&baris,isi);
		Cell = getCell(baris,nomorKolom(kol));
		printf("%s\n",isi);
		if (isi[0] == '=') {
			Tipe(Cell) = FORMULA;
			strcpy(Formula(Cell),isi);
		} else if (isi[0] == '\'') {
			Tipe(Cell) = KALIMAT;
			strcpy(Kalimat(Cell),isi);
		} else if (adaKoma(isi)) {
			Tipe(Cell) = REAL;
			sscanf(isi, "%lf",&Real(Cell));
		} else if (angkaSemua(isi)) {
			Tipe(Cell) = INTEGER;
			sscanf(isi, "%d", &Integer(Cell));
		} else if ((!strcmp(isi,"TRUE") || !strcmp(isi,"FALSE"))) {
			Tipe(Cell) = BOOLEAN;
			Boolean(Cell) = (strcmp(isi,"TRUE")?false:true);
		} else {
			printf("Data tidak valid di %s%d\n",kol,baris);
		}
		fscanf(processedFile,"%*s");
		fscanf(processedFile,"%s",kol);
	}
	fclose(processedFile);
}

void doModusFile(char path[50]){
	alokasiWorksheet();
	strcpy(pathFile,path);
	transferCell();
	do{
		printf(">>");
	} while (processCommandFile(readCommand()));
}


void Write(command Command){
}
void Remove(command Command){
}
void Evaluate(command Command){
}
