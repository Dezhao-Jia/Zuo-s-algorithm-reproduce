// https://blog.csdn.net/weixin_35479108/article/details/90289855

#include <iostream>
#include <string.h>

using namespace std;

class TrieNode
{
    public:
        string word;
        int path;   // 该字符被划过多少次，用以统计一该字符串为前缀的字符串的个数
        int end;    // 以该字符为结尾的字符串的数目
        TrieNode* nexts[26];

        TrieNode()
        {
            word = "";
            path = 0;
            end = 0;
            *nexts = new TrieNode[26];  // 后续指向的 26字母中的某一个位置
        }
};

class TrieTree : public TrieNode
{
    private:
        TrieNode* root;

    public:
        TrieTree()
        {
            root = new TrieNode();
        }

        // 析构函数，删除节点，释放空间，但需要考虑节点出现的次数
        ~TrieTree()
        {
            destory(root);
        }

        // 根据不同情况考虑不同的方式删除节点
        void destory(TrieNode* root)
        {
            if(root == nullptr)
            {
                return;
            }
            for(int i=0; i<26; i++) // 把本节点对应的后续节点全部删除
            {
                destory(root->nexts[i]);
            }
            delete root;    // 删除本节点
            root = nullptr; // 本节点指空
        }

        // 向前缀树中插入字符串
        void insert(string str)
        {
            if(str == "")
            {
                return;
            }
            char buf[str.size()];   // 以单个字符的形式存储字符串内所有内容
            strcpy(buf, str.c_str());   // c_str()就是将C++的string转化为C的字符串数组     char *strcpy(char *dest, const char *src) 把 src 所指向的字符串复制到 dest
            TrieNode* node = root;
            int index = 0;
            for(int i=0; i<strlen(buf); i++)
            {
                index = buf[i] - 'a';
                if(node->nexts[index] == nullptr)   // 未曾插入 buf[i]所代表的字母时插入新字母
                {
                    node->nexts[index] = new TrieNode();
                }
                node = node->nexts[index];
                node->path++;
            }
            node->end++;
            node->word = str;
        }

        // 查找字符串 str出现的次数
        int search(string str)
        {
            if(str == "")
            {
                return 0;
            }
            char buf[str.size()];
            strcpy(buf, str.c_str());
            TrieNode* node = root;
            int index = 0;
            for(int i=0; i<strlen(buf); i++)
            {
                index = buf[i] - 'a';
                if(node->nexts[index] == nullptr)
                {
                    return 0;
                }
                node = node->nexts[index];
            }
            if(node != nullptr)
            {
                return node->end;
            }
            else
            {
                return 0;
            }
        }

        // 删除字符串 str（一次）
        void deleteStr(string str)
        {
            if(str == "")
            {
                return;
            }
            char buf[str.size()];
            strcpy(buf, str.c_str());

            TrieNode* node = root;
            TrieNode* tmp;
            int index = 0;
            for(int i=0; i<str.size(); i++)
            {
                index = buf[i] - 'a';
                tmp = node->nexts[index];
                if(--node->nexts[index]->path == 0)
                {
                    delete node->nexts[index];
                }
                node = tmp;
            }
            node->end--;
        }

        // 输出以该字符串为前缀的数目
        int prefixNumbers(string str)
        {
            if(str == "")
            {
                return 0;
            }
            char buf[str.size()];
            strcpy(buf, str.c_str());
            TrieNode* node = root;
            int index = 0;
            for(int i=0; i<strlen(buf); i++)
            {
                index = buf[i] - 'a';
                if(node->nexts[index] == nullptr)
                {
                    return 0;
                }
                node = node->nexts[index];
            }
            return node->path;
        }

        void printPre(string str)
        {
            if(str == "")
            {
                return;
            }
            char buf[str.size()];
            strcpy(buf,str.c_str());
            TrieNode* node = root;
            int index = 0;
            for(int i=0; i<strlen(buf); i++)
            {
                index = buf[i] - 'a';
                if(node->nexts[index] == nullptr)
                {
                    return;
                }
                node = node->nexts[index];
            }
            Print(node);
        }

        void Print(TrieNode* node)
        {
            if(node == nullptr)
            {
                return;
            }
            if(node->word != "")
            {
                cout << node->word << " " << node->path << endl;
            }
            for(int i=0; i<26; i++)
            {
                Print(node->nexts[i]);
            }
        }

        void printAll()
        {
            Print(root);
        }

};

int main()
{
    cout << "Hello World !" << endl;
    TrieTree tire;

    string str = "Jia";
    cout << tire.search(str) << endl;
    tire.insert(str);
    cout << tire.search(str) << endl;
    tire.deleteStr(str);
    cout << tire.search(str) << endl;
    tire.insert(str);
    cout << tire.search(str) << endl;

    tire.insert(str);
    cout << tire.search(str) << endl;

    return 0;
}