#include "header.h"

int mx_tostring(char *nameoffile, char **string) {
    int counter = 0, src = open(nameoffile, 'r');
    char buf;
    if (src<0)
        return 0;

    int nbytes = read(src , &buf, sizeof(char));
    if (nbytes == 0){
        close(src);
    	return 0;
        }

    while(nbytes > 0) {
        if (buf == '.' || buf == '#') {
            counter++;
            nbytes = read(src , &buf, sizeof(char));
        	if (buf == '\n' || buf == ',') {
                if (buf == '\n')
                    counter++;
            } else {
                close(src);
                return 1;
            }
        	nbytes = read (src, &buf, sizeof(char));
        } else {
        	close(src);
        	return 1;
        }
    }

    close(src);
    src = open(nameoffile, 'r');
    *string = (char *)malloc(sizeof(char) * counter + 1);
    nbytes = read(src, &buf, sizeof(char));
    for(int i = 0; (i < counter);) {
        if (buf == '.' || buf == '#' || buf == '\n')
        	(*string)[i++] = buf;
        nbytes = read(src, &buf, sizeof(char));
    }
    (*string)[counter] = '\0';
    close(src);
    return -1;
}

