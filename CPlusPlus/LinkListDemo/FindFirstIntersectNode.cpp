#include <iostream>
#include <math.h>

// math.h 库常用函数
/*
    fabs() : 取绝对值
    ceil() : 向上取整
    floor() : 向下取整
    pow(a, b) : a的 b次方
    sqrt() : 开平方根
    log() : 取对数（以自然对数为底）
    round() : 四舍五入函数
*/

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

Node* getLoopNode(Node* head)   //寻找链表环入口节点函数，使用了拓扑学知识
{
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
    {
        return nullptr;
    }

    Node* n1 = head->next;    // n1 -> slow
    Node* n2 = head->next->next;    // n2 -> fast

    while(n1 != n2)
    {
        if(n2->next == nullptr || n2->next->next == nullptr)
        {
            return nullptr;
        }

        n2 = n2->next->next;
        n1 = n1->next;
    }

    n2 = head;
    while(n1 != n2)
    {
        n1 = n1->next;
        n2 = n2->next;
    }

    return n1;
}

Node* noLoop(Node* head1, Node* head2)
{
    if( head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }

    Node* cur1 = head1;
    Node* cur2 = head2;

    int n = 0;
    while(cur1->next != nullptr)
    {
        n++;
        cur1 = cur1->next;
    }
    while(cur2->next != nullptr)
    {
        n--;
        cur2 = cur2->next;
    }
    if(cur1 != cur2)    // cur1 与 cur2都位于各自链表最后节点时，若非共同节点，则证明两个链表无共同节点
    {
        return nullptr;
    }

    cur1 = n > 0 ? head1 : head2;
    cur2 = cur1 == head1 ? head2 : head1; 
    n= fabs(n);
    while(n != 0)
    {
        // 两语句是否可以交换顺序尚未证明
        n--;
        cur1 = cur1->next;
    }
    while(cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2)
{
    Node* cur1 = nullptr;
    Node* cur2 = nullptr;

    if(loop1 == loop2)
    {
        cur1 = head1;
        cur2 = head2;

        int n = 0;
        while(cur1 != loop1)
        {
            n++;
            cur1 = cur1->next;
        }
        while(cur2 != loop2)
        {
            n--;
            cur2 = cur2->next;
        }

        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n = fabs(n);
        while(n != 0)
        {
            n--;
            cur1 = cur1->next;
        }
        while(cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }

        return cur1;
    }
    else
    {
        cur1 = loop1->next;
        while(cur1 != loop1)
        {
            if(cur1 == loop2)
            {
                return loop1;
            }
            cur1 = cur1->next;
        }
        return nullptr;
    }
}

Node* getIntersectNode(Node* head1, Node* head2)
{
    if(head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }

    Node* loop1 = getLoopNode(head1);
    Node* loop2 = getLoopNode(head2);

    if(loop1 == nullptr && loop2 == nullptr)
    {
        return noLoop(head1, head2);
    }
    if(loop1 != nullptr && loop2 != nullptr)
    {
        return bothLoop(head1, loop1, head2, loop2);
    }
    return nullptr;
}

int main()
{
    return 0;
}