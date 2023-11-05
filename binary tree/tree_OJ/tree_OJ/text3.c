#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
//101. ¶Ô³Æ¶þ²æÊ÷
//https://leetcode.cn/problems/symmetric-tree/description/
bool _isSymmetric(struct TreeNode* leftRoot, struct TreeNode* rightRoot) {
    if (leftRoot == NULL && rightRoot == NULL)
        return true;
    if (leftRoot == NULL || rightRoot == NULL)
        return false;
    if (leftRoot->val != rightRoot->val)
        return false;
    return _isSymmetric(leftRoot->left, rightRoot->right) && _isSymmetric(leftRoot->right, rightRoot->left);
}

bool isSymmetric(struct TreeNode* root) {
    return _isSymmetric(root->left, root->right);
}