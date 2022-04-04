#include <iostream>

using namespace std;

class Node
{
    public:
        int value;
        Node* next;

        Node(int data)
        {
            this->value = data;
        }
};

Node* revreseList(Node* head)
{
    Node* pre = nullptr;
    Node* next = nullptr;

    while(head != nullptr)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

void printLinst(Node* head)
{
    cout << "The linklist is :";
    while(head->next != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    return 0;
}