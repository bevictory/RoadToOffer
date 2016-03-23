#include <stdio.h>
#include <stdlib.h>
struct TreeNode{
    char *str;
    struct TreeNode *left, *right;
};
struct help{
    int num;
    struct TreeNode *node;
};
#define SIZe 100
int com(struct help *p1,struct help *p1){
    return 1;
}
int qsort(struct help *p, int n ,int k)
{
    struct help* h = p[n-1];
    int i=0,index=0;
    for(i=0;i<n-1; i++)
    {
        if(com(h,p+i))
        {
            struct help tmp = *(p+index);
            *(p+index)=*(p+i);
            *(p+i)=tmp;
            index++;
        }

    }
    *(p+index) = *h;
    if(index ==k){
        return index;
    }else if(index >k){
        qsort(p,index-1,k);
    }else{
        qsort(p+index+1,n-index-1,k-index);
    }
}
int main()
{
    struct help *p= (struct help*)malloc(sizeof(struct help)*SIZE);


}
