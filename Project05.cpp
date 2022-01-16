#include <iostream>

using namespace std;

int main()
{
    int nums[] {8,4,1,53,78,13};
    int numsLen = sizeof(nums) / sizeof(int);   //get the length of array
    int sum = 0;

    for(int i=0; i<numsLen; i++)
    {
        cout << nums[i] << '\t';
    }
    cout << endl;

    //Get the sum of num[i]
    for(int i=0; i<numsLen; i++)
    {
        sum += nums[i];
    }
    cout << "The sum of nums is :" << sum << '\t'
         << "The mean of nums is :" << sum / numsLen << endl;

    //Get the minium and maxium of nums
    int max = nums[0], min = nums[0];
    for(int i=1; i<numsLen; i++)
    {
        max = max > nums[i] ? max : nums[i];
        min = min < nums[i] ? min : nums[i];
    }
    cout << "The maxium number in nums is :" << max << '\t'
         << "The minium number in nums is :" << min << endl;

    //Get the count of odd number and even number
    int oddCount = 0, evenCount = 0;
    for(int i=0; i<numsLen; i++)
    {
        if(nums[i] % 2 == 0)
        {
            evenCount++;
        }            
        else if(nums[i] % 2 == 1)
        {
            oddCount++;
        }            
    }
    cout << "The number of even number in nums is :" << evenCount << '\t'
         << "The number of odd number in nums is :"  << oddCount << endl;

    return 0;
}