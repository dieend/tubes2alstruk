#include "remove.h"

void makeEmpty(area Area){
	int i,j;
	addressCell Cell;
	for (i=Area.rUL; i<Area.rLR; i++) {
		for (j=Area.cUL;j<Area.cLR; j++) {
			Cell = getCell(i,j);
			Tipe(Cell) = EMPTY;
		}
	}
}

void Remove(command Command){
	int i,j;
	int baris,kolom;
	char cindeks[50];
	area Area;
	addressCell Cell;
	if (isArea(Command.param[1])) {
		Area = makeArea(Command.param[1]);
		makeEmpty(Area);
	} else {
		i=0; j=0;
		while ('A' <=Command.param[1][i] && Command.param[1][i] <= 'Z') {
			cindeks[j] = Command.param[1][i];
			i++; j++;
		}
		cindeks[j] = '\0';
		kolom = nomorKolom(cindeks);
		j=0;
		while ('0' <= Command.param[1][i] && Command.param[1][i] <= '9') {
			cindeks[j] = Command.param[1][i];
			i++; j++;
		}
		sscanf(cindeks, "%d",&baris);
		printf("%d %d\n", baris, kolom);
		Cell = getCell(baris,kolom);
		Tipe(Cell) = EMPTY;
	}
}
