#include <iostream>
#include <stack>
/*
stack.size()    返回栈中元素个数
stack.top()     返回栈顶元素
stack.pop()     从栈中取出并删除元素
stack.push(num) 向栈中添加元素 num
stack.empty()   栈空时返回 true
*/

using namespace std;

class myStack
{
    public:
        myStack()
        {

        }

        void push(int newNum)
        {
            if(this->stackMin.empty())
            {
                this->stackMin.push(newNum);
            }
            else if(newNum <= stackMin.top())
            {
                this->stackMin.push(newNum);
            }
            this->stackData.push(newNum);
        }

        int pop()
        {
            if(this->stackData.empty())
            {
                cout << "Stack is Empty" << endl;
                return NULL;
            }

            int value = this->stackData.top();
            if(value == this->getMin())
            {
                this->stackMin.pop();
            }

            return value;
        }

        int getMin()
        {
            if(this->stackMin.empty())
            {
                cout << "Stack is Empty" << endl;
            }
            return this->stackMin.top();
        }

    private:
        stack<int> stackData;
        stack<int> stackMin;

};

int main()
{
    myStack stackExp;
    stackExp.push(4);
    stackExp.push(3);
    stackExp.push(1);
    stackExp.push(5);

    cout << "The minium number in stack is : " << stackExp.getMin() << endl;

    return 0;
}