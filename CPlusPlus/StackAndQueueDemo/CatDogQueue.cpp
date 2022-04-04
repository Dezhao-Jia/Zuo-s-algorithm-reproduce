#include <iostream>
#include <string.h>
#include <queue>    //元素从队尾入队，从队头出队

using namespace std;

class pet
{
    public:
        pet(string type)
        {
            this->type = type;
        }

        string getType()
        {
            return this->type;
        }

    private:
        string type;

};

class cat : public pet
{
    public:
        cat() : pet("cat")
        {
            cout << "Cat ." << endl;
        }

    private:

};

class dog : public pet
{
    public:
        dog() : pet("dog")
        {
            cout << "Dog ." << endl;
        }
    
    private:
    
};

class petEnter : public pet
{
    public:
        petEnter(pet p, long count) : pet(p)
        {
            this->p = p;
            this->count = count;
        }

        pet getPet()
        {
            return this->p;
        }

        long getCount()
        {
            return this->count;
        }

        string getEnterp()
        {
            return this->p.getType();
        }

    private:
        pet p;
        long count;
};

class CatDogQueue : public petEnter
{
    public:
        CatDogQueue()
        {
            count = 0;
        }

        void push(pet p)
        {
            if(p.getType() == "dog")
            {
                dogQ.push(petEnter(p, ++count));
            }
            else if(p.getType() == "cat")
            {
                catQ.oush(petEnter(p, ++count));
            }
            else
            {
                cout << "Error in push Cat/Dog !" << endl;
            }
        }

        bool isEmpty()
        {
            if(dogQ.empty() && catQ.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isCatEmpty()
        {
            if(catQ.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        bool isDogEmpty()
        {
            if(dogQ.empty())
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        pet pollAll()
        {
            if(!isEmpty())
            {
                if(dogQ.front().getCount() < catQ.front().getCount())
                {
                    pet tmp = dogQ.front.getPet();
                    dogQ.pop();
                    return tmp;
                }
                else
                {
                    pet tmp = catQ.front.getPet();
                    catQ.pop();
                    return tmp;
                }
            }
            else if(!catQ.empty())
            {
                pet tmp = catQ.front.getPet();
                catQ.pop();
                return tmp;
            }
            else if(!dogQ.empty())
            {
                pet tmp = dogQ.front.getPet();
                dogQ.pop();
                return tmp;
            }
        }

        pet pollDog()
        {
            if(!isDogEmpty())
            {
                pet tmp = dogQ.front.getPet();
                dogQ.pop();
                return tmp;
            }
            else
            {
                cout << "Dog Queue is Empty !" << endl;
            }
        }

        pet pollCat()
        {
            if(!isCatEmpty())
            {
                pet tmp = catQ.front.getPet();
                catQ.pop();
                return tmp;
            }
            else
            {
                cout << "Cat Queue is Empty !" << endl;
            }
        }

    private:
        queue<petEnter> catQ;
        queue<petEnter> dogQ;
        long count;
    
};

int main()
{
    CatDogQueue CatDogQue;
    if(CatDogQue.isCatEmpty())
    {
        cout << "Cat Queue is Empty !(main function)" << endl;
    }
    if(CatDogQue.isDogEmpty())
    {
        cout << "Dog Queue is Empty !(main function)" << endl;
    }

    for(int i=0; i<3; i++)
    {
        CatDogQue.push(dog());
        CatDogQue.push(cat());
        CatDogQue.push(cat());
    }

    cout << "PollAll :" << CatDogQue.pollAll().getType() << endl;
    cout << "PollCat :" << CatDogQue.pollCat().getType() << endl;
    cout << "PollDog :" << CatDogQue.pollDog().getType() << endl;

    cin.get()
    if(CatDogQue.isEmpty())
    {
        cout << "Both Cat and Dog Queue is Empty !" << endl;
        cin.get();
    }

    return 0;
}