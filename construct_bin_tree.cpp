/*
    剑指offer 7，给出前序、中序，重建二叉树
    根据前中序的特点，利用递归重建，每次递归里为前序首值建节点，左右子节点各交给下一次递归
*/

#include <iostream>
using namespace std;

struct BinTreeNode
{
    int num;
    BinTreeNode* left;
    BinTreeNode* right;
};

BinTreeNode* constructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{

    // 前序遍历中第一个为根节点
    BinTreeNode* root = new BinTreeNode();
    root->num = startPreorder[0];
    root->left = nullptr;
    root->right = nullptr;

    if (startPreorder == endPreorder) return root;

    // 在中序遍历中找到根节点的位置
    int* rootInorder = startInorder;
    while (*rootInorder != root->num) {
        rootInorder++;
    }

    int leftLength = rootInorder-startInorder;

    // 左分支
    if (rootInorder != startInorder)
    {
        root->left = constructCore(startPreorder+1, startPreorder+leftLength, startInorder, rootInorder-1);
    }

    // 右分支
    if (rootInorder != endInorder)
    {
        root->right = constructCore(startPreorder+leftLength+1, endPreorder, rootInorder+1, endInorder);
    }

    return root;
}

BinTreeNode* construct(int* preOrder, int* inOrder, int length)
{
    if (preOrder == nullptr || inOrder == nullptr || length <= 0) return nullptr;

    return constructCore(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
}

int main()
{
    int preOrder[] = {1,2,4,7,3,5,6,8};
    int inOrder[] = {4,7,2,1,5,3,8,6};

    construct((int*)preOrder, (int*)inOrder, 8);
}
