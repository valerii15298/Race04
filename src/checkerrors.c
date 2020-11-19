#include "header.h"

_Bool checkerr(int errnum){
    char *errors[] = {"map does not exist\n", "map error\n", "points are out of map range\n",
                      "entry point cannot be an obstacle\n", "exit point cannot be an obstacle\n",
                      "route not found\n", "error\n"};

    if (errnum != -1){
        write(2, errors[errnum], mx_strlen(errors[errnum]));
        return 1;
        }
    return 0;
}

