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

int* swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int* portion(int arr[], int left, int right, int num)
{
    int less = left - 1, more = right;

    while(left < more)
    {
        if(arr[left] < num)
        {
            swap(arr, ++less, left++);
        }
        else if(arr[left] > num)
        {
            swap(arr, --more, left);
        }
        else
        {
            left++;
        }
    }

    return arr;
}

void print(int arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    portion(arr, 0, len, 5);
    print(arr, len);

    return 0;
}