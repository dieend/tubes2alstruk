#include "list.h"

void List(){
	int i;
	printf("files\n");
	for (i=0; i<Dir.all; i++) {
		printf("%-20s %10s %6s %s bytes\n", Dir.name[i], Dir.date[i], Dir.hour[i], Dir.size[i]);
	}
	printf("Banyaknya file = %d\n", Dir.all);
	printf("Ukuran directory = %s\n", Dir.sum);
}
