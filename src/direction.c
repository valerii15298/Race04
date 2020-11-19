#include "header.h"

void direction(int **arr, char **arrchar, int hight, int width, int x, int y, int max) {
	while (arr[y][x] >= 0) {
			arrchar[y][x] = '*';
			if ((y >= 1) && (arr[y][x] - arr[y-1][x] == 1)) {
				y = y-1;
			}
			if ((y < (hight-1)) && (arr[y][x] - arr[y+1][x] == 1)) {
				y = y+1;
			}
			if ((x >= 1) && (arr[y][x] - arr[y][x-1] == 1)) {
				x = x-1;
			}
			if ((x < (width-1)) && (arr[y][x] - arr[y][x+1] == 1)) {
				x = x+1;
			}
		}
		int i;
		int j;
		for (i = 0; i < hight; i++) {
			for (j = 0; j < width; j++) {
				if (arr[i][j] == -1)
                    arrchar[i][j] = '#';
                else if (arr[i][j] == max)
                    arrchar[i][j] = 'D';
                else
                    arrchar[i][j] = '.';
			}
		}
        if (arr[y][x] == max)
            arrchar[y][x] = 'X';
}

