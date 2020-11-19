#include "header.h"

int tonumbers(int **mas, int width, char *s) {
    width++;
    for(int i = 0; i < mx_strlen(s); i++) {
    	if ((((i+1) % (width)) == 0) && (s[i] != '\n')) {
    		return 1;
    	} else {
            if (s[i] == '.')
                mas[i/width][i % width] = -2;
            if (s[i] == '#')
                mas[i/width][i % width] = -1;
        }
    }
    return -1;
}

