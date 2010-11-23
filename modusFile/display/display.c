#include "display.h"

void Display(command Command) {

	int i,j;
	addressCell Cell;
	printf("%-10s","");
	for (i=1; i<=MAXWORKSIZE; i++) {
		printf("%-10s", indeksKolom(i));
	}
	printf("\n");
	for (i=1; i<=MAXWORKSIZE; i++) {
		printf("%-10d", i);
		for (j=1; j<=MAXWORKSIZE;j++) {
			Cell = getCell(i,j);
			if (Tipe(Cell) == KALIMAT) {
				printf("%-10s", Kalimat(Cell)+1);
			} else
			if (Tipe(Cell) == INTEGER) {
				printf("%-10d", Integer(Cell));
			} else
			if (Tipe(Cell) == REAL) {
				printf("%-10.2lf", Real(Cell));
			} else
			if (Tipe(Cell) == FORMULA) {
				printf("%-10s", Formula(Cell));
			} else          
			if (Tipe(Cell) == BOOLEAN) {
				printf("%-10s", Boolean(Cell)?"TRUE":"FALSE");
			} else 
			if (Tipe(Cell) == EMPTY) {
				printf("%-10s","##");          
			}
			
		}
		printf("\n");
	}

//	showAll(MAXWORKSIZE,MAXWORKSIZE);
}
