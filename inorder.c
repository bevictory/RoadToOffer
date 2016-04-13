#include <stdio.h>
#include <stdlib.h>
struct TreeNode{
    char *str;
    struct TreeNode *left, *right;
};
void inorder(struct TreeNode *node)
{
    if(node == NULL){
        return ;
    }
    inorder(node->left);
    printf("%s\n",node->str);
    inorder(node->right);

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
    root->str="abc";
    left->str="abefab";
    right->str="baefbaad";
    inorder(root);

}
