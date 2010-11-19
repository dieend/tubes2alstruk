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
	showAll(10,10);
	return 0;
}
