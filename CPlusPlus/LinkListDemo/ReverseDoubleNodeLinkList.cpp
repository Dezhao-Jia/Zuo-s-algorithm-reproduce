#include <iostream>

using namespace std;

class DoubleNode
{
    public:
        int value;
        DoubleNode* last;
        DoubleNode* next;

        DoubleNode(int data)
        {
            this->value = data;
        }
};

DoubleNode* revreseList(DoubleNode* head)
{
    DoubleNode* pre = nullptr;
    DoubleNode* next = nullptr;
    while(head != nullptr)
    {
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    }

    return pre;
}

void printDoubleNodeLinkList(DoubleNode* head)
{
    DoubleNode* end = nullptr;
    cout << "The double linklist is :";

    while(head != nullptr)
    {
        cout << head->value << " ";
        end = head;
        head = head->next;
    }
    cout << endl;

    while(end != nullptr)
    {
        cout << end->value << " ";
        end = end->last;
    }
    cout << endl;
}

int main()
{
    
    return 0;
}