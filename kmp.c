#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void getnext(char *str, int next[])
{
    next[0] = next[1] = 0;
    int length = strlen(str);
    int i =0,j=0 ;
    for( i = 1; i < length ; i++){
        while(j>0&&(*(str+i)) != (*(str+j)))
              j = next[j];
        if((*(str+i)) == (*(str+j))) j++;
        next[i+1] = j;
    }
}
int findSubNum(char *str, char *substr,int next[])
{
    getnext(substr,next);
    int length = strlen(substr);
    int i=0,j=0,num=0;
    for(i = 0; i< strlen(str); i++)
    {
        while(j>0&&((*(str+i))!=(*(substr+j))))
            j=next[j];
        if((*(str+i))==(*(substr+j)) ) j++;
        if(j == length){
            num++;
            j = next[j];
        }

    }
    return num;
}
int main()
{
    char* str  ="abefabeabcdabe";
    char *substr="ab";
    int *next = (int *)malloc(sizeof(int)*(strlen(substr)+1));
    printf("%d",findSubNum(str,substr,next));
    return 0;
}
