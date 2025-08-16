#include <bits/stdc++.h>
using namespace std;
int findIndex(vector<int> &v)
{
    int low = 0, high = v.size() - 1;
    int minindex = -1;
    while (low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        if (v[mid1] == v[mid2])
        {
            low = mid1 + 1;
            high = mid2 - 1;
            minindex = mid1;
        }
        else if (v[mid1] < v[mid2])
        {
            high = mid2 - 1;
            minindex = mid1;
        }
        else
        {
            low = mid1 + 1;
            minindex = mid2;
        }
    }
    return minindex;
}
int main()
{
    vector<int> v = {6, 5, 4, 8, 3, 4, 6, 8};
    int idx = findIndex(v);
    cout << idx << endl;
}