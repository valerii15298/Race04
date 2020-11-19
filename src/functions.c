#include "header.h"

bool mx_isdigit(int c){
	return ((47<c && c<58) ? (true) : (false));
}

bool mx_isspace(char c){
	return (c=='\t' || c=='\n' || c=='\v' || c=='\f' || c=='\r' || c==' ');
}

int mx_atoi(const char *str){
    int i = -1, h = 1, rez = 0;
	while(mx_isspace(str[++i]));
	if (mx_isdigit(str[i]) && i>0)
		return -1;
	else if (str[i] == '-'){
		return -1;
	} else if (str[i] == '+')
		i++;
	while(mx_isdigit(str[i]))
		rez = 10 * rez + h*(int)(str[i++] - '0');
	if (str[i] != '\0')
		return -1;
	return rez;
}

int pvalid(int **arr, int h, int w, int points[]){
    for (int i = 0;i<4;i++)
        if (points[i]<0)
            return 2;
    if ((points[0]>=w) || (points[2]>=w) || (points[1]>=h) || (points[3]>=h))
        return 2;
    if (arr[points[0]][points[1]]==-1)
        return 3;
    if (arr[points[2]][points[3]]==-1)
        return 4;
    return -1;
}


int mx_hight(char *str) {
	int b = 0;
	for (int i = 0; i < mx_strlen(str); i++) {
	if (str[i] == '\n')
		b++;
	}
	return b;
}

int mx_strlen(const char *s) {
  int i = -1;
  while(s[++i]);
  return i;
}

void mx_printint(int n){
	if (n==0)
		write(1, "0", 1);
	else if (n==-2147483648)
		write(1, "-2147483648", 11);
	else if (n<0){
		write(1, "-", 1);
		n=-n;
	}
	if (n>0){
		int r = 1;
		for (;(n/r)>=10;r*=10);
		for (;r!=0;r=r/10){
			char t = '0'+(n/r)%10;
			write(1, &t, 1);
		}
	}
}
