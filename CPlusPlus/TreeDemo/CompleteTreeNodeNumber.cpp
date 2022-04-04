#include <iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->value = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};


// 返回值为当前节点最左侧二叉树的层数
int MostLeftLevel(Node* node, int level)
{
    while(node != nullptr)
    {
        level++;
        node = node->left;
    }
    return level-1;
}

// 返回值为当前二叉树的节点总数
// level为当前节点所处层数， height为整棵树的最大高度（在函数中是一个常量，不会改变）
int bs(Node* node, int level, int height)
{
    // 当当前节点为叶结点的时候，结点数返回 1
    if(level == height)
    {
        return 1;
    }

    // 若右子树最大层数等于树高度，则可认为是满二叉树（递归过程）
    // 使用 level+1 是为了使返回层数与 height相齐
    if(MostLeftLevel(node->right, level+1) == height)
    {
        return (1 << (height - level)) + bs(node->right, level+1, height);
    }
    // 若右子树最大层数不等于树高度，则认为非满二叉树，对左子树进行递归操作
    else
    {
        return (1 << (height - level - 1)) + bs(node->left, level+1, height);
    }
}

int NodeNumber(Node* head)
{
    if(head == nullptr)
    {
        return 0;
    }

    return bs(head, 1, MostLeftLevel(head,1));
}

int main()
{
    return 0;
}