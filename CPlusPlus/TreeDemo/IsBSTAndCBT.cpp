//  BST : 搜索二叉树    CBT ： 完全二叉树
#include <iostream>
#include <queue>

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

// 搜索二叉树的判断函数
bool isBST(Node* head)
{
    // 若传入节点为空，则必为搜索二叉树
    if(head == nullptr)
    {
        return true;
    }

    bool res = true;
    Node* pre = nullptr;
    Node* cur1 = head;
    Node* cur2 = nullptr;

    // 莫瑞斯遍历
    /*
    使用场景 ： 遍历二叉树，要求时间复杂度 O(n),空间复杂度O(1)
    算法流程 ：
        当前节点记为 cur, 若 cur无左孩子， 则 cur向右移动， cur = cur->right
        若 cur有左孩子，则找到左子树上最右的节点，记为 mostRight
        1）若 mostRight的右指针指向空，则让其指向 cur，此时 cur向左移动， cur = cur->left
        2）若 mostRight的右指针指向 cur，则让其指向空，cur向右移动， cur = cur->right
        (cur 结点的前驱节点的右指针指向cur)
    */
    while(cur1 != nullptr)
    {
        cur2 = cur1->left;
        if(cur2 != nullptr)
        {
            while(cur2->right != nullptr && cur2->right != cur1)
            {
                cur2 = cur2->right;
            }
            if(cur2->right == nullptr)
            {
                cur2->right = cur1;
                cur1 = cur1->left;
                continue;
            }
            else
            {
                cur2->right = nullptr;
            }         
        }
        if(pre != nullptr && pre->value > cur1->value)
        {
            res = false;
        }
        pre = cur1;
        cur1 = cur1->right;
    }
    return res;
}

// 完全二叉树判断函数
bool isCBT(Node* head)
{
    if(head == nullptr)
    {
        return true;
    }
    queue<Node> temp;
    bool lefa = false;  // 是否开启了判断后续节点是否为叶节点的阶段，初始默认判断阶段未开启
    Node* left = nullptr;
    Node* right = nullptr;
    temp.push(*head);

    while(!temp.empty())
    {
        head = &temp.front();
        temp.pop();

        left = head->left;
        right = head->right;

        if((lefa && (left != nullptr || right != nullptr)) || (left == nullptr && right != nullptr))
        {
            return false;
        }
        if(left != nullptr)
        {
            temp.push(*left);
        }
        if(right != nullptr)
        {
            temp.push(*right);
        }
        else
        {
            lefa = true;
        }
    }
    return true;
}

int main()
{
    return 0;
}