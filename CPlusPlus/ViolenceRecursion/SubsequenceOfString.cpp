// 打印一个字符串的所有子序列

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> StringToChar(string str)
{
    vector<char> res;
    if(str.size() == 0)
    {
        return res;
    }
    for(int i=0; i<str.size(); i++)
    {
        res.push_back(str[i]);
    }
    return res;
}

string CharToString(vector<char> charArr)
{
    string res = "";
    if(charArr.size() == 0)
    {
        return res;
    }
    for(int i=0; i<charArr.size(); i++)
    {
        res = res + charArr[i];
    }
    return res;
}

void process(vector<char> charArr, int i)
{
    if(i == charArr.size())
    {
        string res = CharToString(charArr);
        cout << res << endl;
        return ;
    }
    process(charArr, i+1);
    char tmp = charArr[i];
    charArr[i] = ' ';
    process(charArr, i+1);
    charArr[i] = tmp;
}

void PrintSubString(string str)
{
    if(str.size() == 0)
    {
        return;
    }

    vector<char> charArr = StringToChar(str);
    process(charArr, 0);
}

int main()
{
    string str = "abc";
    PrintSubString(str);

    return 0;
}