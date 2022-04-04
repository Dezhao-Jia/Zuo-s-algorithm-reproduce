#include <iostream>
#include <string>
#include <vector>
#include <numeric>

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

vector<string> getSpace(int num)
{
    string space = " ";
    vector<string> tmp;
    for(int i=0; i<num; i++)
    {
        tmp.push_back(space);
    }
    return tmp;
}

string convert(vector<string> vec)
{
    string tmp;
    tmp = accumulate(vec.begin(), vec.end(), tmp);
    return tmp;
}

void printInOrder(Node* head, int height, string to, int len)
{
    if(head == nullptr)
    {
        return;
    }
    printInOrder(head->right, height+1, "v", len);
    string tmpVal = to_string(head->value);     // 数字转换为字符串
    string val = to + tmpVal + to;      // 字符串拼接
    int lenM = val.length();    // val.length() 返回字符串的长度
    int lenL = (len - lenM)/2;
    int lenR = len - lenM - lenL;
    val = convert(getSpace(lenL)) + val + convert(getSpace(lenR));
    cout << convert(getSpace(height*len)) << val;
    printInOrder(head->left, height+1,"^", len);
}

void printTree(Node* head)
{
    cout << "Binary Tree :" << endl;
    printInOrder(head, 0, "H", 17);
    cout << endl;
}

int main()
{
    Node head(1);
    head.left = new Node(-2222);
    head.right = new Node(3);
    head.left->left = new Node(4);
    head.right->left = new Node(55555);
    head.right->right = new Node(66);
    head.left->left->right = new Node(777);

    printTree(&head);
    return 0;
}