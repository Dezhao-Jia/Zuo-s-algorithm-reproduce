#include <iostream>
#include <math.h>

using namespace std;

class arrayStack
{
    public:
        arrayStack(int initSize)
        {
            if(initSize < 0)
            {
                cout << "Error Parameter.";
                return ;
            }

            arr = new int[initSize];
            index = 0;
            capcity = initSize;
        }

        int peek(int arr[])
        {
            if(index == 0)
            {
                return NULL;
            }

            return arr[index - 1];
        }

        void push(int obj)
        {
            if(index == capcity)
            {
                cout << "Stack is full !" << endl;
            }
            else
            {
                arr[index++] = obj;
            }
        }

        int pop()
        {
            if(index == 0)
            {
                cout << "Stack is empty !" << endl;
            }
            else
            {
                return arr[--index];
            }
        }

    private:
        int index;
        int capcity;
        int *arr;

};

class arrayQueue
{
    public:
        arrayQueue(int initSize)
        {
            if(initSize < 0)
            {
                cout << "Error Parameter .";
                return ;
            }

            arr = new int[initSize];
            index = 0;
            first = 0;
            last = 0;
            capcity = initSize;
        }

        int peek()
        {
            if(index == 0)
            {
                cout << "Queue is Empty" << endl;
                return NULL;
            }
            return arr[first];
        }

        void push(int obj)
        {
            if(index == capcity)
            {
                cout << "Queue is Full" << endl;
            }
            
            index++;
            arr[last] = obj;
            last = last == capcity - 1 ? 0 : last + 1;
        }

        int poll()
        {
            if(index == 0)
            {
                cout << "Queue is Empty" << endl;
                return NULL;
            }
            index--;
            int tmp = first;
            first = first == capcity - 1 ? 0 : first + 1;
            return arr[tmp];
        }

    private:
        int *arr;
        int index;
        int first;
        int last;
        int capcity;
    
};

int main()
{
    return 0;
}