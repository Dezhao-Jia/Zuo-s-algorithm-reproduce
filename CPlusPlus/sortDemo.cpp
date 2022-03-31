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

bool isEqual(int arr1[], int arr2[], int len)
{
    if((arr1 == NULL && arr2 != NULL) || (arr1 != NULL && arr2 ==NULL))
    {
        return false;
    }

    if(arr1 == NULL && arr2 == NULL)
    {
        return false;
    }

    for(int i = 0; i < len; i++)
    {
        if(arr1[i] != arr2[i])
        {
            return false;
        }
    }

    return true;
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

void bubbleSort(int arr[], int len)
{
    if(arr == NULL || len < 2)
    {
        return;
    }

    for(int end = len - 1; end > 0; end--)
    {
        for(int i = 0; i < end; i++)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i],arr[i+1]);
            }
        }
    }

}

void selectSort(int arr[], int len)
{
    if(arr == NULL || len < 2)
    {
        return;
    }

    for(int i = 0; i < len - 1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j < len; j++)
        {
            if(arr[minIndex] > arr[j])
            {
                swap(arr[minIndex], arr[j]);
            }
        }
    }
}

void insertSort(int arr[], int len)
{
    if(arr == NULL || len < 2)
    {
        return;
    }

    for(int i = 1; i < len - 1; i++)
    {
        for(int j = i -1; j >= 0 && arr[j] > arr[j + 1]; j--)
        {
            swap(arr[j], arr[j + 1]);
        }
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int tempLen = right - left + 1;
    int temp[tempLen];
    int i = 0, p1 = left, p2 = mid + 1;

    while(p1 <= mid && p2 <= right)
    {
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
}

void mergeSortProcess(int arr[], int left, int right)
{
    if(left == right)
    {
        return;
    }

    int mid = (right + left) / 2;
    mergeSortProcess(arr, 0, mid);
    mergeSortProcess(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(int arr[], int len)
{
    if(arr == NULL || len < 2)
    {
        return;
    }

    mergeSortProcess(arr, 0, len-1);
}

int* partition(int arr[], int left, int right)
{
    int less = left - 1, more = right + 1;
    while(left < more)
    {
        if(arr[left] < arr[right])
        {
            swap(arr, ++less, left++);
        }
        else if(arr[left] > arr[right])
        {
            swap(arr, --more, left);
        }
        else
        {
            left++;
        }
    }
}

void quickSort(int arr[], int left, int right)
{
    if(left < right)
    {
        partition(arr, left, right);
        right--;
        quickSort(arr, left, right);
    }
}

void heapInsert(int arr[], int index)
{
    while(arr[index] > arr[(index - 1) / 2])
    {
        swap(arr, index, (index - 1)/2);
        index = (index - 1) / 2;
    }
}

void heapify(int arr[], int index, int heapSize)
{
    // index处数值变小，大根堆更新过程
    int left = index * 2 + 1;
    while(left < heapSize)
    {
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        largest = arr[largest] > arr[index] ? largest : index;

        if(largest == index)
        {
            break;
        }

        swap(arr, largest, index);
        index = largest;
        left = index * 2 + 1;
    }
}

void heapSort(int arr[], int len)
{
    if(arr == NULL || len < 2)
    {
        return;
    }

    for(int i = 0; i < len; i++)
    {
        heapInsert(arr, i);
    }

    //每次获得堆中最大元素，将剩余元素再次堆排序选择最大元素
    swap(arr, 0 , --len);
    while(len > 0)
    {
        heapify(arr, 0, len);
        swap(arr, 0, --len);
    }
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
    int len, value, epochs;

    cout << "Input the spochs of code :";
    cin >> epochs;

    cout << "Input the len of array :" ;
    cin >> len;

    cout << "Input the value of array :";
    cin >> value;

    for(int i = 0; i < epochs; i++)
    {
        vector<int> vec1 = generateRandomVector(len,value);
        vector<int> vec2(vec1);

        int arr1[len], arr2[len], arr3[len];
        convert(vec1, arr1);
        convert(vec2, arr2);
        convert(vec1, arr3);

        bubbleSort(arr1, len);
        quickSort(arr2, 0, len - 1);
        if(!isEqual(arr1,arr2, len))
        {
            cout << "The method have some errors ." << endl;
            break;
        }
    }
    

    return 0;  
}
