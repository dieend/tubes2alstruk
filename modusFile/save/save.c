#include "save.h"

void Save() {
	FILE * processedFile = fopen(pathFile,"w");
	addressCell Cell;
	int i,j;
	for (i=1; i<=MAXWORKSIZE; i++) {
		for (j=1; j<=MAXWORKSIZE;j++) {
			Cell = getCell(i,j);
			if (Tipe(Cell) != EMPTY) {
				fprintf(processedFile, "%s %d : ", indeksKolom(j),i);
				if (Tipe(Cell)==FORMULA) {
					fprintf(processedFile, "%s #\n", Formula(Cell));
				} else
				if (Tipe(Cell)==KALIMAT) {
					fprintf(processedFile, "%s #\n", Kalimat(Cell));
				} else
				if (Tipe(Cell)==REAL) {
					fprintf(processedFile, "%.3lf #\n", Real(Cell));
				} else
				if (Tipe(Cell)==INTEGER) {
					fprintf(processedFile, "%d #\n", Integer(Cell));
				} else
				if (Tipe(Cell)==BOOLEAN) {
					fprintf(processedFile, "%s #\n", Boolean(Cell)?"TRUE":"FALSE");
				};
				
			}
		}
	}
	fprintf(processedFile,"#\n");
	fclose(processedFile);
}
