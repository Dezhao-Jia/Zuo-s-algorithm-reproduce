// 在具有父节点指针的二叉树中寻找后继节点
/*
    后继节点 ： 在二叉树中序遍历中，一个节点后的那个节点便是其后继节点
    前驱节点 ： 在二叉树中序遍历中，一个结点前的那个节点便是其前驱节点
    知识公理 ：
        若一个节点有右子树，则其后继节点必为其右子树上的最左节点
        若一个节点没有右子树，则一直向上查找至当前节点为其父亲结点的左孩子时，则此时所获得的父节点为原始节点的后继节点
        若一个节点有左子树，则其前驱节点必为其左子树上的最右节点
        若一个节点没有左子树，则一直向上查找至当前节点为其父亲节点的右孩子时，则此时所获得的父亲节点为原结点的前驱节点
*/
#include <iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node* left;
        Node* right;
        Node* parent;

        Node(int data)
        {
            this->value = data;
        }
};

Node* getMostLeft(Node* node)
{
    if(node == nullptr)
    {
        return node;
    }
    while(node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

Node* getSuccessorNode(Node* node)
{
    if(node == nullptr)
    {
        return node;
    }
    if(node->right != nullptr)
    {
        return getMostLeft(node->right);
    }
    else
    {
        Node* parent = node->parent;
        while(parent != nullptr && parent->left != node)
        {
            node = parent;
            parent = node->parent;
        }
        return node;
    }
}

int main()
{
    return 0;
}