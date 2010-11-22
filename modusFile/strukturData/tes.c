#include "worksheet.h"

int main() {
	alokasiWorksheet();
	addressCell Cell;
	Integer(getCell(4,2)) = 40;
	Tipe(getCell(4,2)) = INTEGER;
	Cell = getCell(1,1);
	Real(Cell) = 10.5;
	Tipe(Cell) = REAL;
	printf("%d\n",Integer(Cell));
	printf("%s\n", indeksKolom(28));
	printf("%d\n", nomorKolom("AB"));
	showAll(10,10);
	return 0;
	B1:C3
	sum(int a, int b, int c, int d) {
		for (i=a; i<=c; i++) for (j=b; j<=d; j++){
			Cell = getCell(i,j);
			if (Tipe(Cell) != EMPTY) count++;
			
		}
	}
	sum += Integer(Cell);
}
