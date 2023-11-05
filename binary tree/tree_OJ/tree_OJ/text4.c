#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
//144. 二叉树的前序遍历
//https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
int TreeSize(struct TreeNode* root) {
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _preorder(struct TreeNode* root, int* a, int* i) {
    if (root == NULL)
        return;
    a[(*i)++] = root->val;
    _preorder(root->left, a, i);
    _preorder(root->right, a, i);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(*returnSize * sizeof(int));
    int i = 0;
    _preorder(root, a, &i);
    return a;
}

//94. 二叉树的中序遍历
//https://leetcode.cn/problems/binary-tree-inorder-traversal/
int TreeSize(struct TreeNode* root) {
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _inorder(struct TreeNode* root, int* a, int* i) {
    if (root == NULL)
        return;
    _inorder(root->left, a, i);
    a[(*i)++] = root->val;
    _inorder(root->right, a, i);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(*returnSize * sizeof(int));
    int i = 0;
    _inorder(root, a, &i);
    return a;
}
//145. 二叉树的后序遍历
//https://leetcode.cn/problems/binary-tree-postorder-traversal/
int TreeSize(struct TreeNode* root) {
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
void _postorder(struct TreeNode* root, int* a, int* i) {
    if (root == NULL)
        return;
    _postorder(root->left, a, i);
    _postorder(root->right, a, i);
    a[(*i)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* a = (int*)malloc(*returnSize * sizeof(int));
    int i = 0;
    _postorder(root, a, &i);
    return a;
}
