#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
struct TreeNode{
    char *str;
    struct TreeNode *left, *right;
};
struct help{
    int num;
    struct TreeNode *node;
};

struct help pall[SIZE]={};;
int inde =0;
int com(struct help *p1,struct help *p2){
    if(p1->num < p2->num){
        return 1;
    }
    if(p1->num == p2->num){
        if(strlen(p1->node->str) <strlen(p2->node->str))
        {
            return 1;
        }
        if(strlen(p1->node->str) ==strlen(p2->node->str)){
            if(strcmp(p2->node->str,p1->node->str)){
                return 1;
            }
        }
    }
    return 0;
}
struct TreeNode * qsort1(struct help *p, int n ,int k)
{
    struct help h = p[0];
    int i=0,j=n-1,index=0;
    if(n<k) {
         return;
    }
    while(i<j){
        while(i<j && !com(&h,p+j)) j--;

        *(p+i)=*(p+j);

        while(i<j && com(&h,p+i)) i++;
        *(p+j)=*(p+i);

    }
    *(p+i) = h;

    if(i ==(k-1)){

        return (p+i)->node;
    }else if(i >(k-1)){
        return qsort1(p,i,k);
    }else{
        return qsort1(p+i+1,n-i,k-i-1);
    }
}
void inorder(struct TreeNode *node, char *substr)
{
    int *next = (int *)malloc(sizeof(int)*(strlen(substr)+1));
    if(node == NULL){
        return ;
    }
    inorder(node->left,substr);
    int num =findSubNum(node->str,substr,next);
    if(num>0){struct help h = {num,node};
    pall[inde++] = h;}
    printf("%s %d\n",node->str,num);
    inorder(node->right,substr);

}

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

struct TreeNode *findNode(struct TreeNode *node, char *substr,int n){
    inorder(node,substr);
    printf("find node num %d\n",inde);
    int i=0;
    for( i=0;i<inde; i++){
        printf("%s\n",pall[i].node->str);
    }
    qsort1(pall,inde,n);

}
int main()
{

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
    struct TreeNode *left = (struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
    struct TreeNode *right = (struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
    root->left=left;
    root->right =right;
    left->left=NULL;
    left->right=NULL;
    right->left=NULL;
    right->right=NULL;
    root->str="abced";
    left->str="cbcab";
    right->str="babefbaad";
    char *substr = "ab";
    /*struct help p1 = {2,root};
    struct help p2 = {2,left};
    struct help p3 = {3,right};
    //printf("%d",com(&p1,&p2));
    p[0]=p1;p[1]=p2;p[2]=p3;*/
    printf("%s",findNode(root,substr,3)->str);

    printf("%d",strcmp("abced","cdcab"));
    return 0;
   //inorder(root,substr);
}
