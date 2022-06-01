// https://blog.csdn.net/weixin_35479108/article/details/90210029?spm=1001.2014.3001.5502

#include <iostream>
#include <vector>

using namespace std;

// 最短路径
int ProcessMinPath(vector<vector<int>> arr, int i, int j)
{
    int rows = arr.size();
    int cols = arr[0].size();
    int res = arr[i][j];

    if(i == rows-1 && j == cols-1)
    {
        return res;
    }
    if(i == rows-1 && j != cols-1)
    {
        return res + ProcessMinPath(arr, i ,j+1);
    }
    if(i != rows-1 && j == cols-1)
    {
        return res + ProcessMinPath(arr, i+1, j);
    }

    return res + min(ProcessMinPath(arr, i+1, j), ProcessMinPath(arr, i, j+1));
}

// 根据递归是心啊思路修改动态规划（逆推过程）
int MinPathDynamic(vector<vector<int>> arr)
{
    int rows = arr.size();
    int cols = arr[0].size();
    // result数组中每个位置的元素值都是该位置到达右下角的路径长度
    vector<vector<int>> result(rows);

    // 初始化二维数组
    for(int i=0; i<rows; i++)
    {
        result[i].resize(cols);
    }
    result[rows-1][cols-1] = arr[rows-1][cols-1];

    // 填充只依赖下面位置最短路径的最后一列
    for(int i=rows-2; i>=0; i--)
    {
        result[i][cols-1] = result[i+1][cols-1] + arr[i][cols-1];
    }

    // 填充只依赖右面位置最短路径的最后一行
    for(int j=cols-2; j>=0; j--)
    {
        result[rows-1][j] = result[rows-1][j+1] + arr[rows-1][j];
    }

    //填充中间位置的最短路径
    for(int i= rows-2; i>=0; i--)
    {
        for(int j=cols-2; j>=0; j--)
        {
            result[i][j] = arr[i][j] + min(result[i][j+1], result[i+1][j]);
        }
    }
    return result[0][0];
}

int main()
{
    return 0;
}