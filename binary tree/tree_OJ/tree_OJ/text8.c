#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

//110. Æ½ºâ¶þ²æÊ÷
//https://leetcode.cn/problems/balanced-binary-tree/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}