#include "write.h"

void Write(command Command){
	char ckolom[20],cbaris[20];
	int baris,kolom,i,j;
	addressCell Cell;
	i=0,j=0;
	while ('A'<= Command.param[1][i] && Command.param[1][i] <='Z') {
		ckolom[j] = Command.param[1][i];
		i++; j++;
	}
	ckolom[j] = '\0';
	j = 0;
	while ('0'<= Command.param[1][i] && Command.param[1][i] <='9') {
		cbaris[j] = Command.param[1][i];
		i++; j++;
	}
	cbaris[j] = '\0';
	kolom = nomorKolom(ckolom);
	sscanf(cbaris, "%d",&baris);
	Cell = getCell(baris,kolom);
	insert(Cell, Command.param[2]);
}
