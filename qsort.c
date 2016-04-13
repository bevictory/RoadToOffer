#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TreeNode{
    char *str;
    struct TreeNode *left, *right;
};
struct help{
    int num;
    struct TreeNode *node;
};
#define SIZE 100
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
    if(n<=k) {
         if(n==k)   return (p+k-1)->node;
         else return;
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
int main()
{
    struct help *p= (struct help*)malloc(sizeof(struct help)*SIZE);
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
    struct TreeNode *left = (struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
    struct TreeNode *right = (struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
    root->left=left;
    root->right =right;
    left->left=NULL;
    left->right=NULL;
    right->left=NULL;
    right->right=NULL;
    root->str="abc";
    left->str="cbc";
    right->str="baefbaad";
    struct help p1 = {2,root};
    struct help p2 = {2,left};
    struct help p3 = {3,right};
    //printf("%d",com(&p1,&p2));
    p[0]=p1;p[1]=p2;p[2]=p3;
    printf("%s",qsort1(p,3,2)->str);
}
