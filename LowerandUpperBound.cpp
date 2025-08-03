//built in : int idx = lower_bound(v.begin(), v.end(), target) - v.begin();
#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &v, int element)
{
    int lo = 0, high = v.size() - 1;
    int mid;
    while (high - lo > 1)
    {
        mid = (high + lo) / 2;
        if (v[mid] < element)
        {
            lo = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[lo] >= element)
        return lo;
    else if (v[high] >= element)
        return high;
    else
        return -1;
}

int upperBound(vector<int> &v, int element)
{
    int lo = 0, high = v.size() - 1;
    int mid;
    while (high - lo > 1)
    {
        mid = (high + lo) / 2;
        if (v[mid] <= element)
        {
            lo = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[lo] > element)
        return lo;
    else if (v[high] > element)
        return high;
    else
        return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int element;
    cin >> element;
    int lb = lowerBound(v, element);
    cout << "lower bound: ";
    cout << "index: " << lb << " " << "value: " << v[lb] << endl;
    cout << "upper bound: ";
    int ub = upperBound(v, element);
    cout << "index: " << ub << " " << "value: " << v[ub] << endl;
}