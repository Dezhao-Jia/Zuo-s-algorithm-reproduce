#include <iostream>
#include <stack>
#include <queue>
/*
queue<Type> M   定义一个 queue变量
queue.empty()   若队列为空返回 true
queue.push(num) 从已有元素后面增加元素
queue.size()    输出现有元素个数
queue.front()   显示第一个元素
queue.back()    显示最后一个元素
queue.pop()     清楚第一个元素
*/

using namespace std;

class StackToQueue
{
    public:
        void push(int pushNum)
        {
            stackPush.push(pushNum);
        }

        int poll()
        {
            if(stackPop.empty() && stackPush.empty())
            {
                cout << "Queue is Empty " << endl;
            }
            else if(stackPop.empty())
            {
                while(!stackPush.empty())
                {
                    stackPop.push(stackPush.top());
                    stackPush.pop();
                }
            }
            return stackPop.top();
        }

        int peek()
        {
            if(stackPop.empty() && stackPush.empty())
            {
                cout << "Queue is Empty " << endl;
            }
            else if(stackPop.empty())
            {
                while(!stackPush.empty())
                {
                    stackPop.push(stackPush.top());
                    stackPush.pop();
                }
            }
            return stackPop.top();
        }


    private:
        stack<int> stackPush;
        stack<int> stackPop;

};

class QueueToStack
{
    public:
        void push(int pushNum)
        {
            queueUse.push(pushNum);
        }

        int peek()
        {
            if(queueUse.empty())
            {
                cout << "Stack is Empty" << endl;
            }

            while(queueUse.size() != 1)
            {
                help.push(queueUse.front());
                queueUse.pop();
            }

            int remain = queueUse.front();
            help.push(remain);
            queueUse.pop();

            swap();

            return remain;
        }

        int pop()
        {
            if(queueUse.empty())
            {
                cout << "Stack is Empty" << endl;
            }

            while(queueUse.size() > 1)
            {
                help.push(queueUse.front());
                queueUse.pop();
            }

            int remain = queueUse.front();
            help.push(remain);
            queueUse.pop();

            swap();

            return remain;
        }

        void swap()
        {
            queue<int> tmp;
            tmp = help;
            help = queueUse;
            queueUse = tmp;
        }

    private:
        queue<int> queueUse;
        queue<int> help;

};

int main()
{
    return 0;
}