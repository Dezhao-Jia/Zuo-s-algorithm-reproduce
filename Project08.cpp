//This project is a structer of forming type game

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    string FatherName;
    cout << "The name of father is :";
    cin >> FatherName;

    string DaughterName;
    cout << "The name of daughter is :";
    cin >> DaughterName;

    int birthMonth;
    cout << "The month of daughter's birthday :";
    cin >> birthMonth;

    int birthDate;
    cout << "The date of daughter's birthday :";
    cin >> birthMonth;

    string daughterConstell;

    string constellName[12][2] = 
    {
        {"山羊座","水瓶座"},   //一月
        {"水瓶座","双鱼座"},   //二月
        {"双鱼座","白羊座"},   //三月
        {"白羊座","金牛座"},   //四月
        {"金牛座","双子座"},   //五月
        {"双子座","巨蟹座"},   //六月
        {"巨蟹座","狮子座"},   //七月
        {"狮子座","处女座"},   //八月
        {"处女座","天秤座"},   //九月
        {"天秤座","天蝎座"},   //十月
        {"天蝎座","射手座"},   //十一月
        {"射手座","山羊座"},   //十二月
    };

    int constellDates[] {20, 19, 21, 20, 21, 22, 23, 23, 23, 24, 23, 22};

    daughterConstell = constellName[birthMonth - 1 ][birthDate / constellDates[birthMonth - 1]];

    cout << "The information daughter : " << endl;
    cout << "Name" << '\t' << DaughterName << endl;
    cout << "constell" << '\t' << daughterConstell << endl;

    //体力、智力、魅力、道德、气质
    int BaseInfos[5];

    if(daughterConstell == "白羊座")
    {
        BaseInfos[0] = 80;
        BaseInfos[1] = 15;
        BaseInfos[2] = 15;
        BaseInfos[3] = 11;
        BaseInfos[4] = 21;
    }
    else if(daughterConstell == "金牛座")
    {
        BaseInfos[0] = 46;
        BaseInfos[1] = 30;
        BaseInfos[2] = 28;
        BaseInfos[3] = 11;
        BaseInfos[4] = 21;
    }
    else if(daughterConstell == "双子座")
    {
        BaseInfos[0] = 50;
        BaseInfos[1] = 35;
        BaseInfos[2] = 23;
        BaseInfos[3] = 11;
        BaseInfos[4] = 21;
    }
    else if(daughterConstell == "巨蟹座")
    {
        BaseInfos[0] = 40;
        BaseInfos[1] = 31;
        BaseInfos[2] = 33;
        BaseInfos[3] = 11;
        BaseInfos[4] = 21;
    }
    else if(daughterConstell == "狮子座")
    {
        BaseInfos[0] = 85;
        BaseInfos[1] = 19;
        BaseInfos[2] = 11;
        BaseInfos[3] = 11;
        BaseInfos[4] = 21;
    }
    else if(daughterConstell == "处女座")
    {
        BaseInfos[0] = 35;
        BaseInfos[1] = 28;
        BaseInfos[2] = 36;
        BaseInfos[3] = 11;
        BaseInfos[4] = 21;
    }
    else if(daughterConstell == "天秤座")
    {
        BaseInfos[0] = 42;
        BaseInfos[1] = 33;
        BaseInfos[2] = 25;
        BaseInfos[3] = 11;
        BaseInfos[4] = 21;
    }
    else if(daughterConstell == "天蝎座")
    {
        BaseInfos[0] = 50;
        BaseInfos[1] = 25;
        BaseInfos[2] = 45;
        BaseInfos[3] = 21;
        BaseInfos[4] = 12;
    }
    else if(daughterConstell == "射手座")
    {
        BaseInfos[0] = 57;
        BaseInfos[1] = 31;
        BaseInfos[2] = 15;
        BaseInfos[3] = 17;
        BaseInfos[4] = 17;
    }
    else if(daughterConstell == "山羊座")
    {
        BaseInfos[0] = 56;
        BaseInfos[1] = 21;
        BaseInfos[2] = 16;
        BaseInfos[3] = 15;
        BaseInfos[4] = 23;
    }
    else if(daughterConstell == "水瓶座")
    {
        BaseInfos[0] = 43;
        BaseInfos[1] = 43;
        BaseInfos[2] = 19;
        BaseInfos[3] = 31;
        BaseInfos[4] = 19;
    }
    else if(daughterConstell == "双鱼座")
    {
        BaseInfos[0] = 66;
        BaseInfos[1] = 19;
        BaseInfos[2] = 34;
        BaseInfos[3] = 27;
        BaseInfos[4] = 31;
    }

    for(int year = 1659; year<=1659+7; year++)
    {
        for(int month = (year==1659) ? 6:1; month<=12; month++)
        {
            if(month == birthMonth)
            {
                cout << "This month have daughter's birthday, do you want to give her a gift?" << endl;
            }
        }
    }

    return 0;
}