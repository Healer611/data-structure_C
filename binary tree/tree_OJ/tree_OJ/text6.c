#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//¶þ²æÊ÷±éÀú
//https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
#include <stdio.h>
#include <stdlib.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
    BTDataType data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;
BTNode* BuyNode(BTDataType x)
{
    BTNode* node = (BTNode*)malloc(sizeof(BTNode));
    if (node == NULL) {
        perror("malloc fail");
        return NULL;
    }
    node->data = x;
    node->left = node->right = NULL;
    return node;
}
BTNode* CreateTree(char* a, int* i)
{
    if (a[*i] == '#') {
        (*i)++;
        return NULL;
    }
    BTNode* root = BuyNode(a[*i]);
    (*i)++;
    root->left = CreateTree(a, i);
    root->right = CreateTree(a, i);
    return root;
}
void InOrder(BTNode* root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}
int main() {
    char a[1000];
    scanf("%s", a);
    int i = 0;
    BTNode* root = CreateTree(a, &i);
    InOrder(root);
    printf("\n");
    return 0;
}