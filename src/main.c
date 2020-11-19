#include "header.h"


int main(int argc, char *argv[]) {

    if (argc != 6) {
        write(2, "usage: ./race04 [file_name] [x1] [y1] [x2] [y2]\n", 42);
        return 0;
    }

    char *s;

    if (checkerr(mx_tostring(argv[1], &s)))
        return 0;

    int hight = mx_hight(s);
    int width = (mx_strlen(s) / hight) - 1;

    int **arr = malloc(sizeof(int*)*hight);
    for (int i = 0;i<hight;i++)
        arr[i] = malloc(sizeof(int)*width);

    if (checkerr(tonumbers(arr, width, s)))
        return 0;



    int points[4];
    for (int i = 2;i<6;i++){
        points[i-2] = mx_atoi(argv[i]);
        if (points[i-2] == -1)
            if (checkerr(6))
                return 0;
        }

    int r = points[0];
    points[0] = points[1];
    points[1] = r;

    r = points[2];
    points[2] = points[3];
    points[3] = r;

    if (checkerr(pvalid(arr, hight, width, points)))
        return 0;

    int dist = go(arr, points[0], points[1], hight, width);

    int ext = arr[points[2]][points[3]];

    if (ext == -2)
        if (checkerr(5))
            return 0;

    char **arrchar = malloc(sizeof(int*)*hight);
    for (int i = 0;i<hight;i++)
        arrchar[i] = malloc(sizeof(int)*width);

    direction(arr, arrchar, hight, width, points[2], points[3], dist);

    for (int i = 0;i<hight;i++)
        free(arr[i]);
    free(arr);


    if (checkerr(tofile(arrchar, width, hight)))
        return 0;

    write(1, "dist=", 5);
    mx_printint(dist);
    write(1, "\n", 1);

    write(1, "exit=", 5);
    mx_printint(ext);
    write(1, "\n", 1);
}

