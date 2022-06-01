// 在数据流中，随时取得中位数

#include <iostream>
#include <queue>
#include <time.h>

using namespace std;

class MaxHeapComparator
{
    public:
        bool operator()(int o1, int o2)
        {
            return o1 < o2;
        }
};

class MinHeapComparator
{
    public:
        bool operator()(int o1, int o2)
        {
            return o1 > o2;
        }
};

class MedianHolder
{
    public:
        // priority_queue<int, vector<int>, MaxHeapComparator> maxHeap;
        // priority_queue<int, vector<int>, MinHeapComparator> minHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int, vector<int>, less<int>> maxHeap;

        void addNumber(int num)
        {
            if(this->maxHeap.empty())
            {
                this->maxHeap.push(num);
                return;
            }
            if(this->maxHeap.top() >= num)
            {
                this->maxHeap.push(num);
            }
            else
            {
                if(this->minHeap.empty())
                {
                    this->minHeap.push(num);
                    return;
                }
                if(this->minHeap.top() > num)
                {
                    this->maxHeap.push(num);
                }
                else
                {
                    this->minHeap.push(num);
                }
            }
            modifyTwoHeapsSize();
        }

        int getMedian()
        {
            int maxHeapSize = this->maxHeap.size();
            int minHeapSize = this->minHeap.size();
            if((maxHeapSize + minHeapSize) == 0)
            {
                return NULL;
            }

            int maxHeapHead = this->maxHeap.top();
            int minHeapHead = this->minHeap.top();
            if(((maxHeapSize + minHeapSize) & 1) == 0)
            {
                return (maxHeapHead + minHeapHead)/2;
            }

            return maxHeapSize > minHeapSize ? maxHeapHead : minHeapHead;
        }

    private:
        void modifyTwoHeapsSize()
        {
            if(this->maxHeap.size() == this->minHeap.size()+2)
            {
                this->minHeap.push(this->maxHeap.top());
                this->maxHeap.pop();
            }
            if(this->minHeap.size() == this->maxHeap.size()+2)
            {
                this->maxHeap.push(this->minHeap.top());
                this->minHeap.pop();
            }
        }
};

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


int getMedianOfArray(int arr[], int len)
{
    int newArr[len];
    for(int i=0; i<len; i++)
    {
        newArr[i] = arr[i];
    }
    bubbleSort(newArr, len);
    int mid = (len - 1)/2;
    if((len & 1) == 0)
    {
        return (newArr[mid] + newArr[mid + 1]) / 2;
    }
    else
    {
        return newArr[mid];
    }
}

int main()
{
    int len, value, epochs;

    cout << "Input the epochs of code :";
    cin >> epochs;

    cout << "Input the len of array :" ;
    cin >> len;

    cout << "Input the value of array :";
    cin >> value;

    for(int i=0; i<epochs; i++)
    {
        vector<int> vec = generateRandomVector(len, value);
        int arr[len];
        convert(vec, arr);

        MedianHolder medianHold;
        for(int i=0; i<len; i++)
        {
            medianHold.addNumber(arr[i]);
        }
        if(medianHold.getMedian() != getMedianOfArray(arr, len))
        {
            cout << "This is an error ." << endl;
            break;
        }
    }

    return 0;
}