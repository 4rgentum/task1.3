#include "view.h"
#include <stdio.h>

void menu() {
	printf("0) Exit\n");
	printf("1) Init Array\n");
	printf("2) Insert Element by Index\n");
	printf("3) Delete Element by Index\n");
	printf("4) Get Array of Simple Numbers\n");
	printf("5) Print Array\n");
	printf("--->\n");
}

void print_array(const int *array, int size) {
	if (size == 0) {
		printf("There Is Nothing\n");
	} else {
		printf("{");
		for (int i = 0; i < size; i++) {
			printf("%d", array[i]);
			if (i < size - 1) {
				printf(" ");
			}
		}
		printf("}\n");
	}
}

