#include <iostream>
#include <string>
#include <math.h>
#include <map>

using namespace std;

class pool
{
    private:
        map<string,int> KeyIndexMap;
        map<int,string> IndexKeyMap;
        int size;
    
    public:
        pool()
        {
            this->size = 0;
            this->KeyIndexMap = KeyIndexMap;
            this->IndexKeyMap = IndexKeyMap;
        }

        void insert(string key)
        {
            if(this->KeyIndexMap.count(key) == 0)
            //if(this->KeyIndexMap.find(key) == this->KeyIndexMap.end())   //若map内不存在 key值
            {
                this->KeyIndexMap.insert(pair<string,int>(key,this->size));
                this->IndexKeyMap.insert(pair<int,string>(this->size,key));
            }

            map<string,int>::iterator iterKIndex;
            for(iterKIndex = this->KeyIndexMap.begin(); iterKIndex != this->KeyIndexMap.end(); iterKIndex++)
            {
                cout << iterKIndex->first << " " << iterKIndex->second << endl;
            }
        }

        void deleteKey(string key)
        {
            if(this->KeyIndexMap.count(key) != 0)
            {
                int deletIndex = this->KeyIndexMap.find(key)->second;
                int lastIndex = --this->size;
                string lastKey = this->IndexKeyMap.find(lastIndex)->second;
                this->KeyIndexMap.insert(pair<string,int>(lastKey,deletIndex));
                this->IndexKeyMap.insert(pair<int,string>(deletIndex,lastKey));
                this->KeyIndexMap.erase(key);
                this->IndexKeyMap.erase(lastIndex);
            }
        }

        string getRandom()
        {
            if(this->size == 0)
            {
                return NULL;
            }
            int randomIndex = (int)(rand()%this->size + 1);
            return this->IndexKeyMap.find(randomIndex)->second;
        }
};

int main()
{
    return 0;
}