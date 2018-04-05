/*
    剑指offer 7, lintcode 73, 重建二叉树
*/
#include <vector>
using namespace std;

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
}

class Solution {
    /**
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return buildTreeHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* buildTreeHelper(vector<int> &preorder, vector<int> &inorder, int i1, int j1, int i2, int j2) {
        if (i1 > j1) return NULL;

        int val = preorder[i1];
        TreeNode* node = new TreeNode(val);
        
        if (i1 < j1) {
            int middle = i2;
            while (inorder[middle] != val) middle++;
            int left_size = middle-i2;
            int right_size = j2-middle;
            node->left = buildTreeHelper(preorder, inorder, i1+1, i1+left_size, i2, i2+left_size-1);
            node->right = buildTreeHelper(preorder, inorder, i1+left_size+1, j1, i2+left_size+1, j2);
        }

        return node;
    }
};
