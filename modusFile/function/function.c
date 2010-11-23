#include "function.h"

double sum (int r1, int c1, int r2, int c2) {
	int i,j;
	double hasil = 0;
	addressCell Cell;
	for (i=r1; i<=r2;i++) {
		for (j=c1,j <=c2; j++) {
			Cell = getCell(i,j);
			if (Tipe(Cell) == INTEGER) {
				hasil = hasil + (double) Integer(Cell); 
			} else
			if (Tipe(Cell) == REAL){
				hasil += Real(Cell)
			}
		}
	}
}