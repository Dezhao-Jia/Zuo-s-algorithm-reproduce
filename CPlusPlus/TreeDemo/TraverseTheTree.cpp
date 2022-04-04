// recursive : 递归     traverse : 遍历     inorder traverse : 中序遍历
#include <iostream>
#include <stack>

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
        }
};

// 递归前序遍历
void PreOrderRecur(Node* head)
{
    if(head == nullptr)
    {
        return;
    }
    cout << head->value << " ";
    PreOrderRecur(head->left);
    PreOrderRecur(head->right);
}

// 递归中序遍历
void InOrderRecur(Node* head)
{
    if(head == nullptr)
    {
        return;
    }
    InOrderRecur(head->left);
    cout << head->value << " ";
    InOrderRecur(head->right);
}

// 递归后序遍历
void PosOrderRecur(Node* head)
{
    if(head == nullptr)
    {
        return;
    }
    PosOrderRecur(head->left);
    PosOrderRecur(head->right);
    cout << head->value << " ";
}

// 非递归前序遍历
void PreOrderUnRecure(Node* head)
{
    cout << "PreOrderUnRecure :";
    stack<Node> tmp;
    if(head != nullptr)
    {
        tmp.push(*head);
        while(!tmp.empty())
        {
            *head = tmp.top();
            cout << head->value << " ";
            tmp.pop();
            if(head->right != nullptr)
            {
                tmp.push(*head->right);
            }
            if(head->left != nullptr)
            {
                tmp.push(*head->left);
            }
        }
    }
    cout << endl;
}

// 非递归中序遍历
void InOrderUnRecure(Node* head)
{
    cout << "InOrderUnRecure :";
    stack<Node> tmp;
    if(head != nullptr)
    {
        while(!tmp.empty() || head != nullptr)
        {
            if(head != nullptr)
            {
                tmp.push(*head);
                head=head->left;
            }
            else
            {
                *head = tmp.top();
                tmp.pop();
                cout << head->value << " ";
                head = head->right;
            }
        }
    }
    cout << endl;
}

// 非递归后序遍历
void PosOrderUnRecure(Node* head)
{
    cout << "PosOrderUnRecure :";
    stack<Node> tmp;
    stack<Node> help;
    if(head != nullptr)
    {
        tmp.push(*head);
        while(!tmp.empty())
        {
            *head = tmp.top();
            tmp.pop();
            help.push(*head);
            if(head->left != nullptr)
            {
                tmp.push(*head->left);
            }
            if(head->right != nullptr)
            {
                tmp.push(*head->right);
            }
        }
        while(!help.empty())
        {
            cout << help.top().value << " ";
            help.pop();
        }
    }
    cout << endl;
}

int main()
{
    return 0;
}