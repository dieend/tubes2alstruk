#include "find.h"
#include "../../global/variable.h"

void searchName(char* Name) {
	int i;
	for (i=0; i<Dir.all; i++) {
		if (isSubString(Dir.name[i], Name)) {
			printf("%s\n",Dir.name[i]);
		}
	}
}

void searchDate(char* Date){
	int i;
	for (i=0; i<Dir.all; i++) {
		if (isSubString(Dir.date[i],Date)) {
			printf("%-10s %s\n",Dir.name[i], Dir.date[i]);
		}
	}
}

void searchSize(char* Size){
	int i;
	for (i=0; i<Dir.all; i++) {
		if (isSubString(Dir.size[i],Size)) {
			printf("%-10s %s\n",Dir.name[i], Dir.size[i]);
		}
	}
}
