// 给定一个字符串类型的数组strs，找到一种拼接方式，使得把所有字符串拼起来之后形成的字符串具有最低的字典序

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareStrings(string str1, string str2)
{
    return (str1 + str2) < (str2 + str1);
}

string MinOrder(vector<string> strs)
{
    if(strs.size() <= 0)
    {
        return "";
    }
    sort(strs.begin(), strs.end(), compareStrings);

    string res = "";
    for(int i=0; i<strs.size(); i++)
    {
        res += strs[i];
    }
    return res;
}

int main()
{
    vector<string> strs = {"b", "ba", "abcd", "dad", "bird"};
    string result = MinOrder(strs);
    cout << result << endl;
    
    strs = {};
    result = MinOrder(strs);
    cout << result << endl;
    return 0;
}