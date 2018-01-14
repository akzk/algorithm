/*
    剑指offer，un_test，给出一颗二叉树与其中一个节点，求中序遍历的下一个节点
    该节点中序遍历的下一个节点的位置只有两种可能性，1. 右节点的最左节点；2. 父系节点中最近的是父节点的左节点的节点。1优先于2
*/
#include <iostream>
using namespace std;

struct BinTreeNode
{
    int num;
    BinTreeNode* left;
    BinTreeNode* right;
    BinTreeNode* parent;
};

BinTreeNode* GetNext(BinTreeNode* node)
{
    if (node == nullptr) return nullptr;

    BinTreeNode* pNext = nullptr;
    if (node->right != nullptr)
    {
        node = node->right;
        while (node->left != nullptr) node = node->left;
        pNext = node;
    } else if (node->parent != nullptr) {
        BinTreeNode* pCurrent = node;
        BinTreeNode* pParent = node->parent;
        while (pParent != nullptr && pCurrent == pParent->right)
        {
            pCurrent = pParent;
            pParent = pParent->parent;
        }
    }
    return pNext;
}

int main() {
    
}
