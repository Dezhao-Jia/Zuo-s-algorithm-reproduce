#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<int> generateRandomVector(int size, int value)
{
    srand((int)time(NULL));     //为随机数生成器产生随机种子

    //分配随机大小的数组，产生随机数的范围公式
    // number = (rand() % (maxvalue - minvalue + 1)) + minvalue
    vector<int> result(size);
    for(int i = 0; i < result.size(); i++)
    {
        result[i] = rand() % (value + 1);
    }

    return result;
}

int* convert(vector<int> vec, int arr[])
{
    copy(vec.begin(), vec.end(), arr);
}

void print(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getMin(int arr[], int len)
{
    int min = arr[0];
    for(int i=1; i<len; i++)
    {
        min = min < arr[i] ? min : arr[i];
    }

    //cout << "The min value in array is :" << min << endl;
    return min;
}

int getMax(int arr[], int len)
{
    int max = arr[0];
    for(int i=1; i<len; i++)
    {
        max = max > arr[i] ? max : arr[i];
    }

    //cout << "The max value in array is :" << max << endl;
    return max;
}

int bucket(long num, long len, long min, long max)  //  确定某个数字来自于哪个桶
{
    return (int)((num - min)*len / (max - min));
}

int maxGap(int arr[], int len)
{
    if(arr == NULL || len < 2)
    {
        return 0;
    }
    
    int min = getMin(arr, len);
    int max = getMax(arr, len);

    if(max == min)
    {
        return 0;
    }

    bool hasNum[len + 1] = {false}; //此处若是不定义，bool数组默认值为 ture,会导致结果错误
    int maxs[len + 1] = {0};    //此处必须初始化
    int mins[len + 1] = {0};    //此处必须初始化
    int bid = 0;

    for(int i=0; i<len; i++)
    {
        bid = bucket(arr[i], len, min, max);

        if(hasNum[bid] != true)
        {
            mins[bid] = arr[i];
            maxs[bid] = arr[i];
        }
        else
        {
            mins[bid] = mins[bid] < arr[i] ? mins[bid] : arr[i];
            maxs[bid] = maxs[bid] > arr[i] ? maxs[bid] : arr[i];
        }

        hasNum[bid] = true;
    }

    int res = 0;
    int lastMax = maxs[0];
    int i = 1;

    for(; i<=len; i++)
    {
        if(hasNum[i])
        {
            int tmp = mins[i] - lastMax;
            if(res < tmp)
            {
                res = tmp;
            }
            lastMax = maxs[i];
        }
    }

    return res;
}

int main()
{
    int len, value;

    cout << "Input the len of array :" ;
    cin >> len;

    cout << "Input the value of array :";
    cin >> value;

    vector<int> vec = generateRandomVector(len,value);
    int arr[len];

    convert(vec, arr);
    print(arr, len);

    int maxGapVal = maxGap(arr, len);

    cout << "The max gap value of array is :" << maxGapVal << endl;
    
    return 0;
}