// https://blog.csdn.net/weixin_35479108/article/details/90210029?spm=1001.2014.3001.5502
// 给你一个数组arr，和一个整数aim，如果可以任意选择arr中的数字，能不能累加得到aim,返回true或者false

#include <iostream>
#include <vector>

using namespace std;

bool RecurProcess(vector<int> arr, int i, int sum, int aim)
{
    if(sum == aim)
    {
        return true;
    }
    if(i == arr.size())
    {
        return false;
    }
    return RecurProcess(arr, i+1, sum, aim) || RecurProcess(arr, i+1, sum+arr[i], aim);
}

bool isSum(vector<int> arr, int aim)
{
    RecurProcess(arr, 0, 0, aim);
}

// 动态规划版本
bool isSumDynamic(vector<int> arr, int aim)
{
    int length = arr.size();

    // res多出来的一行作为终止位置行
    vector<vector<bool>> res(length+1);

    for(int i=0; i<=length; i++)
    {
        // 从 0~aim 列（每行设置 aim+1列）
        res[i].resize(aim+1);
    }
    for(int i=0; i<res.size(); i++)
    {
        res[i][aim] = true;
    }

    for(int i=arr.size()-1; i>=0; i--)
    {
        for(int j=aim-1; j>=0; j--)
        {
            res[i][j] = res[i+1][j];
            if(j + arr[i] <= aim)
            {
                res[i][j] = res[i][j] || res[i+1][j+arr[i]];
            }
        }
    }

    return res[0][0];
}

int main()
{
    return 0;
}