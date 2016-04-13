#include <stdio.h>
int main(){
    char str[] ="hello world";
    char *p = &str[0];
    printf("%d\n",strlen(p));
    printf("%c",*(p+1));
    return 0;
}
