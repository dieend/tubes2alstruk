#include "worksheet.h"

worksheet Worksheet;

addressHeader alokasiHeader(int x) {
	addressHeader Header;
	Header = (addressHeader) malloc (1*sizeof(header));
	if (Header == Nil) {
		printf("ALOKASI GAGAL!!\n");
		return Nil;
	}
	Header->Nomor = x;
	Header->firstElmt = Nil;
	Header->next = Nil;
	return Header;
}

addressCell alokasiCell() {
	addressCell Cell;
	Cell = (addressCell) malloc(1*sizeof(cell));
	if (Cell == Nil) {
		printf("ALOKASI CELL GAGAL!!!\n");
		return Nil;
	};
	Tipe(Cell) = EMPTY;
	NextR(Cell) = Nil;
	NextC(Cell) = Nil;
	return Cell;
}

void alokasiWorksheet(){
	int i,j;
	addressHeader Header;
	addressCell Cell;
	Worksheet.hBaris = alokasiHeader(1);
	Header = Worksheet.hBaris;
	for (i=2; i<MAXWORKSIZE+10; i++) {
		Header->firstElmt = alokasiCell();
		Cell = Header->firstElmt;
		for (j=1; j<MAXWORKSIZE+1;j++) {
			NextC(Cell) = alokasiCell();
			Cell = NextC(Cell);
//			printf("%d\n",j);
		}
		Header->next = alokasiHeader(i);
		Header = Header->next;
	}
	
	Worksheet.hKolom = alokasiHeader(1);
	Header = Worksheet.hKolom;
	for (i=0; i<MAXWORKSIZE+1; i++) {
//		printf("%d\n",i);
		Header->next = alokasiHeader(i+2);
		for (j=0; j<MAXWORKSIZE; j++) {
			Cell = getCell(i,j);
			NextR(Cell) = getCell(i+1,j);
		}
		Header = Header->next;
	}
}

addressCell getCell(int r, int c) {
	int i,j;
	addressCell Cell;
	addressHeader Header = Worksheet.hBaris;
	for (i=0; i<r; i++) {
		Header = Header->next;
	}
	Cell = Header->firstElmt;
	for (j=0; j<c; j++) {
		Cell = NextC(Cell);
	}
	return Cell;
}

void showAll(int r, int c) {
	int i,j;
	addressCell Cell;
	for (i=1; i<=r; i++) {
		for (j=1; j<=c; j++) {
			Cell = getCell(i,j);
			if (Tipe(Cell) == EMPTY) {
				printf("%-5s","##");
			} else if (Tipe(Cell) == INTEGER) {
				printf("%-5d",Integer(Cell));
			} else if (Tipe(Cell) == REAL) {
				printf("%-5.2lf",Real(Cell));
			}
		}
		printf("\n");
	}
}

void inverse(char inver_a[],int j)
{
   int i,temp,x;
   x = j;
   j--;
   for(i=0;i<(x/2);i++)
   {
      temp=inver_a[i];
      inver_a[i]=inver_a[j];
      inver_a[j]=temp;
      j--;
   }
}

char * indeksKolom(int n) {
	char* indeks;
	n--;
	indeks = (char*) malloc(20*sizeof(char));
	int chr,len = 0;
	char tmp[2];
	strcpy(indeks,"");
	strcpy(tmp,"A");
	chr = n%26;
	tmp[0]=(char)(chr+('A'));
	strcat(indeks,tmp);
	len++;
	n/=26;
	while (n>0) {
		n--;
		chr = n%26;
		tmp[0]=(char)(chr+('A'));
		strcat(indeks,tmp);
		len++;
		n/=26;
	}
	inverse(indeks, len);
	return indeks;
}

int nomorKolom(char kolom[]) {
	int n,len,mult;
	mult = 1;
	n=0;
	len = strlen(kolom)-1;
//	printf("%s\n",kolom);
	while (len>=0) {
		n += (int) (kolom[len]-'A'+1) * mult;
//		printf("%d\n",n);
//		printf("%d",len);
		mult*=26;
		len--;
	}
	return n;
}
