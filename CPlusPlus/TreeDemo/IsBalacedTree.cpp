#include <iostream>
#include <math.h>

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

int getHeight(Node* head, int level, bool res[])
{
    if(head == nullptr)
    {
        return level;
    }
    
    int LeftHeight = getHeight(head->left, level+1, res);
    if(!res[0]) // 若二叉树不平衡则返回当前高度
    {
        return level;
    }
    int RightHeight = getHeight(head->right, level+1, res);
    if(!res[0]) // 若二叉树不平衡则返回当前高度
    {
        return level;
    }
    if(fabs(LeftHeight - RightHeight) > 1)  // 若当前二叉树左右高度差大于 1，怎证明该二叉树不平衡
    {
        res[0] = false;
    }
    return max(LeftHeight, RightHeight);    // 返回值为二叉树左右枝杈的最大高度，即为本二叉树的高度

}

bool isBalance(Node* head)
{
    bool res[1] = {true};   // res[0]代指二叉树是否平衡，初始状态假定为平衡二叉树
    cout << "The value of res array is :" << res[1] << endl;
    getHeight(head, 1, res);
    return res[0];

}

int main()
{
    return 0;
}