#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int data)
    {
        this->value = data;
    }
};

bool isPalindrome1(Node *head)
{
    stack<Node> stackTmp;
    Node *cur = head;

    while (cur != nullptr)
    {
        stackTmp.push(*cur);
        cur = cur->next;
    }
    while (head != nullptr)
    {
        if (head->value != stackTmp.top().value)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}

bool isPalindrom2(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node *right = head->next;
    Node *cur = head;

    while (cur->next != nullptr && cur->next->next != nullptr)
    {
        right = right->next;
        cur = cur->next->next;
    }

    stack<Node> stackTmp;
    while (right != nullptr)
    {
        stackTmp.push(*right);
        right = right->next;
    }
    while (!stackTmp.empty())
    {
        if (head->value != stackTmp.top().value)
        {
            return false;
        }
        head = head->next;
    }
    return true;
}

bool isPalindrom3(Node *head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return true;
    }

    Node* node1 = head;
    Node* node2 = head;
    while(node2->next != nullptr && node2->next->next != nullptr)
    {
        // To find mid node
        node1 = node1->next;    // node1 is mid
        node2 = node2->next->next; // node2 is end
    }

    // After this part, node1 is the last of linklist, node2 and node3 are in nullptr
    node2 = node1->next;    // node2 -> right part first node
    node1->next = nullptr;  // mid -> next = nullptr
    Node* node3 = nullptr;
    while(node2 != nullptr)
    {
        // Right part convert
        node3 = node2->next;    // node3 -> save next node
        node2->next = node1;    // next of right node convert
        node1 = node2;  // node1 move
        node2 = node3;  // node2 move
    }

    // After this part, node1 and node2 are in the mid of linklist, node3 is the last of linklist
    node3 = node1;  // node3 -> savelast node
    node2 = head;
    bool res = true;
    while(node1 != nullptr && node2 != nullptr)
    {
        //check palindrome
        if(node1->value != node2->value)
        {
            res = false;
            break;
        }
        node1 = node1->next;    // left to mid
        node2 = node2->next;    // right to mid
    }

    // Recover the linklist
    node1 = node3->next;
    node3->next = nullptr;
    while(node1 != nullptr)
    {
        node2 = node1->next;
        node1->next = node3;
        node3 = node1;
        node1 = node2;
    }

    return res;
}

void printLinkList(Node* head)
{
    cout << "Link List :";
    while(head != nullptr)
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