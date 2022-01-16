#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> vecDouble = {34.2,58.6,27.0,12.1,10.1};
    vecDouble.push_back(01.0);
    for(int i=0, i<vecDouble.size(); i++)
    {
        cout << vecDouble[i] << " ";
    }


    //The using of iterator to traverse
    vector<double>::iterator it;    // Get the iterator "it" of type vector<double>, It's a pointer
    for(it=vecDouble.begin(); it!=vecDouble.end(); ++it)
    {
        cout << *it << " ";
    }

    //Sort the vector, be include in <algorithm>
    sort(vecDouble.begin(), vecDouble.end());
    for(it=vecDouble.begin(); it!=vecDouble.end(); ++it)
    {
        cout << *it << " ";
    }

    //Reverse the Vector, be include in <algorithm>
    reverse(vecDouble.begin(), vecDouble.end());
    for(it=vecDouble.begin(); it!=vecDouble.end(); ++it)
    {
        cout << *it << " ";
    }

    return 0;
}