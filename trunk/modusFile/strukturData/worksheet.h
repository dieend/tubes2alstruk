#ifndef worksheet_H
#define worksheet_H

#include "../../global/variable.h"
#define MAXWORKSIZE 10


enum tipe {
	EMPTY, REAL, KALIMAT, FORMULA, INTEGER, BOOLEAN, FAIL
};


typedef struct tcell * addressCell;
typedef struct tcell{
	union {
		double REAL;
		char KALIMAT[100];
		char FORMULA[100];
		int INTEGER;
		boolean BOOLEAN;
	};
	enum tipe tipeData;
	addressCell NextRow;
	addressCell NextCol;
} cell;

/** Selektor Cell **/
/* c bertipe address Cell */
#define Tipe(c) (c)->tipeData
#define Real(c) (c)->REAL
#define Formula(c) (c)->FORMULA
#define Integer(c) (c)->INTEGER
#define Kalimat(c) (c)->KALIMAT
#define Boolean(c) (c)->BOOLEAN
#define NextR(c) (c)->NextRow
#define NextC(c) (c)->NextCol

typedef struct tHeader* addressHeader;
typedef struct tHeader{
	int Nomor;
	addressCell  firstElmt;
	addressHeader next;
} header;

typedef struct {
	addressHeader hBaris;
	addressHeader hKolom;
} worksheet;

typedef struct {
	int rUL,cUL, rLR, cLR;
} area;

addressHeader alokasiHeader(int x);
addressCell alokasiCell() ;
void alokasiWorksheet();
addressCell getCell(int r, int c);
void showAll(int r, int c);
void inverse(char inver_a[],int j);
char * indeksKolom(int n);
int nomorKolom(char kolom[]);
boolean isArea(char Cek[]);
area makeArea(char Area[]);
extern worksheet Worksheet;

#endif
