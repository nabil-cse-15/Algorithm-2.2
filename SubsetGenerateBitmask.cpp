//if  There are at most 8 elements then this will be efficient
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    vector<int> arr = {2, 4, 5};
    int n = arr.size();
    int total_subset = (1 << n);
    for (int mask = 0; mask < total_subset; mask++) // 2^n
    {
        vector<int> subset;
        for (int i = 0; i < n; i++) // n
        {
            if (mask & (1 << i)) // if i-th bit is set
                subset.push_back(arr[i]);
        }

        // Print the subset
        for (int pr : subset)
            cout << pr << " ";
        cout << endl;
    }

    return 0;
}
// time complexity : O(n * 2^n)
