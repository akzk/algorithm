/*
    lintcode 11, 二叉查找树中搜索区间
    中序遍历
*/

#include <vector>

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
public:
    /*
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        // write your code here
        vector<int> result;
        searchRangeHelper(root, k1, k2, result);
        return result;
    }

    void searchRangeHelper(TreeNode* root, int k1, int k2, vector<int> &result)
    {
        if (root) {
            int val = root->val;
            if (val > k2) return;

            searchRangeHelper(root->left, k1, k2, result);
            if (k1 <= val <= k2) {
                result.push_back(val);
            }
            searchRangeHelper(root->right, k1, k2, result);
        }
    }
};