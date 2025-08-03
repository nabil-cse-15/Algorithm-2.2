// TWO SUM Problem.(Binary Search) Giving an array of n integers find the index of which two value sum is k

#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &v, int start, int item)
{
    int low = start, high = v.size() - 1;
    while (high - low > 1)
    {
        int mid = (high + low) / 2;
        if (v[mid] < item)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[low] == item)
        return low;
    else if (v[high] == item)
        return high;
    else
        return -1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < v.size(); i++)
    {
        int s = k - v[i];
        int result = binarySearch(v, i + 1, s);
        if (result != -1)
        {
            cout << i + 1 << " " << result + 1 << endl;
        }
    }
}
