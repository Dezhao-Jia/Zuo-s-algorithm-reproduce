#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

vector<int> generateRandomVector(int size, int value)
{
    srand((int)time(NULL));     //为随机数生成器产生随机种子

    //分配随机大小的数组，产生随机数的范围公式
    // number = (rand() % (maxvalue - minvalue + 1)) + minvalue
    vector<int> result(rand() % (size + 1));
    for(int i = 0; i < result.size(); i++)
    {
        result[i] = rand() % (value + 1);
    }

    return result;
}

int merge(int arr[], int left, int mid, int right)
{
    int tempLen = right - left + 1;
    int temp[tempLen];
    int i = 0, p1 = left, p2 = mid + 1;
    int res = 0;

    while(p1 <= mid && p2 <= right)
    {
        res += arr[p1] < arr[p2] ? (right - p2 + 1) * arr[p1] : 0;
        temp[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
    }

    while(p1 <= mid)
    {
        temp[i++] = arr[p1++];
    }

    while(p2 <= right)
    {
        temp[i++] = arr[p2++];
    }

    for(i = 0; i < sizeof(temp)/sizeof(temp[0]); i++)
    {
        arr[left + i] = temp[i];
    }

    return res;
}

int mergeSortProcess(int arr[], int left, int right)
{
    if(left == right)
    {
        return 0;
    }

    int mid = (right + left) / 2;
    return mergeSortProcess(arr, 0, mid) + mergeSortProcess(arr, mid + 1, right) + merge(arr, left, mid, right);
}

int smallSum(int arr[], int len)
{
    if(arr == NULL || len < 2)
    {
        return 0;
    }

    return mergeSortProcess(arr, 0, len-1);
}

int* convert(vector<int> vec, int arr[])
{
    copy(vec.begin(), vec.end(), arr);
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
    int res = smallSum(arr, len);

    cout << "The smallSum of arr is :" << res << endl;
    return 0;
}