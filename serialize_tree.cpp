/*
    lintcode 7, 序列化与反序列化二叉树
    序列化：中序遍历，NULL值记'#'
    反序列化：中序遍历重建
    重点：ostringstream, istringstream, &
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        // 中序遍历即可
        ostringstream os;
        serializeHelper(root, os);
        return os.str();
    }

    void serializeHelper(TreeNode* root, ostringstream &os)
    {
        if (!root) {
            os << "# ";
        } else {
            os << root->val << " ";
            serializeHelper(root->left, os);
            serializeHelper(root->right, os);
        }
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        istringstream is;
        is.str(data);
        TreeNode* root = NULL;
        deserializeHelper(root, is);
        return root;
    }

    void deserializeHelper(TreeNode* &root, istringstream &is)
    {
        while (is.peek() == ' ')
            is.ignore();
            
        if (is.peek() == '#')
        {
            root = NULL;
            is.ignore();
        } else {
            int val;
            is >> val;
            root = new TreeNode(val);
            deserializeHelper(root->left, is);
            deserializeHelper(root->right, is);
        }
    }
};