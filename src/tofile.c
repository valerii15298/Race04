#include "header.h"

int tofile(char **arrchar, int x, int y) {
	int dst = open("path.txt", O_WRONLY | O_CREAT, 0666);
	if (dst == -1) {
		return 6;
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			write(dst, &arrchar[i][j], sizeof(char));
		}
		write(dst, "\n", sizeof(char));
	}
	close(dst);
	return -1;
}


