#include "header.h"

void cmp(int **arr, int a, int b, int a2, int b2, int w, int h){
    if ((a2>=0) && (b2>=0) && (a2<h) && (b2<w))
        if (arr[a2][b2]!=-1){
            if (arr[a2][b2] == -2)
                arr[a2][b2] = arr[a][b] + 1;
            else if ((arr[a][b] + 1)<arr[a2][b2])
                arr[a2][b2] = arr[a][b] + 1;
        }
}

int go(int **arr, int x, int y, int h, int w){
    arr[x][y] = 0;
    _Bool bl = 1;
    int max;
    for (int i = 0;bl;i++){
        bl = 0;
        for (int a = 0; a<h; a++)
            for (int b = 0; b<w; b++)
                if (arr[a][b] == i){
                    cmp(arr, a, b, a-1, b  , w, h);
                    cmp(arr, a, b, a  , b-1, w, h);
                    cmp(arr, a, b, a+1, b  , w, h);
                    cmp(arr, a, b, a  , b+1, w, h);
                    bl = 1;
                    max = i;
                }
    }
    return max;
}

