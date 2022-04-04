#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<string,string> tempMap;
    
    tempMap.insert(pair<string,string>("Zuo","31"));
    tempMap.insert(pair<string,string>("Jia","18"));
    map<string,string>::iterator iter;
    iter = tempMap.find("Zuo");
    cout << iter->first << " " << iter->second << endl;
    cout << "======================================" << endl;

    /*
    // 无所查找键，则函数不会有任何输出
    iter = tempMap.find("chengyun");
    cout << iter->first << "  " << iter->second << endl;
    cout << "======================================" << endl;
    */

    if(tempMap.empty())
    {
        cout << "The map is empty" << endl;
    }
    else
    {
        cout << "The size of map is :" << tempMap.size() << endl;
    }
    for (iter = tempMap.begin(); iter != tempMap.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << "======================================" << endl;

    tempMap.erase("Zuo");
    iter = tempMap.find("Zuo");
    if(tempMap.empty())
    {
        cout << "The map is empty" << endl;
    }
    else
    {
        cout << "The size of map is :" << tempMap.size() << endl;
    }
    for (iter = tempMap.begin(); iter != tempMap.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << "======================================" << endl;

    return 0;
}