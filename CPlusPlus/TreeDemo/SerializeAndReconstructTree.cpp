// Serialize : 使···成为序列    Reconstruct : 重新够建
// 以 #代表 nullptr     以 _代表节点之间的间隔
#include <iostream>
#include <string>
#include <numeric>  // 包含 to_string()函数
#include <queue>
#include <vector>

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

// 将序列化字符串中的“_”抹掉
string split(string str1)
{
    string str2;
    int len = str1.length();
    for(int i=0; i<len; i++)
    {
        if(str1[i] != '_')
        {
            str2.push_back(str1[i]);
        }
    }
    return str2;
}

// 前序序列方式序列化二叉树
string SerialByPre(Node* head)
{
    if(head == nullptr)
    {
        return "#_";
    }

    string val = to_string(head->value);
    string res = val + "_";
    res += SerialByPre(head->left);
    res += SerialByPre(head->right);
    return res;
}

// 前序序列方式反序列化字符串步骤2
Node* ReconPreOrder(queue<char> queueStr)
{
    char value = queueStr.front();
    queueStr.pop();

    if(value == '#')
    {
        return nullptr;
    }
    Node head(value);
    head.left = ReconPreOrder(queueStr);
    head.right = ReconPreOrder(queueStr);
    return &head;
}

// 前序序列方式反序列化字符串步骤1
Node* reconByPreString(string preStr)
{
    string values = split(preStr);
    queue<char> queueStr;
    for(int i=0; i!=values.length(); i++)
    {
        queueStr.push(values[i]);
    }

    return ReconPreOrder(queueStr);
}

// 层次遍历方式序列化二叉树
string serialByLevel(Node* head)
{
    if(head == nullptr)
    {
        return "#_";
    }

    string res = to_string(head->value) + '_';
    queue<Node> NodeQueue;
    NodeQueue.push(*head);

    while(!NodeQueue.empty())
    {
        *head = NodeQueue.front();
        NodeQueue.pop();
        if(head->left != nullptr)
        {
            res += to_string(head->left->value) + '_';
            NodeQueue.push(*head->left);
        }
        else
        {
            res += '#_';
        }
        if(head->right != nullptr)
        {
            res += to_string(head->right->value) + '_';
            NodeQueue.push(*head->right);
        }
        else
        {
            res += '#_';
        }
    }

    return res;
}


// 层次遍历方式反序列化字符串步骤2
Node* generateNodeByString(char val)
{
    if(val == '#')
    {
        return nullptr;
    }
    Node tmp(val);
    return &tmp;
}

// 层次遍历方式反序列化字符串步骤1
Node* reconByLevelString(string levelStr)
{
    string values = split(levelStr);
    int index = 0;
    Node* head = generateNodeByString(values[index++]);
    queue<Node> tmp;
    
    if(head != nullptr)
    {
        tmp.push(*head);
    }

    Node* node;
    while(!tmp.empty())
    {
        node = &tmp.front();
        tmp.pop();
        node->left = generateNodeByString(values[index++]);
        node->right = generateNodeByString(values[index++]);
        if(node->left != nullptr)
        {
            tmp.push(*node->left);
        }
        if(node->right != nullptr)
        {
            tmp.push(*node->right);
        }
    }

    return head;
}

int main()
{
    return 0;
}