#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int len = sqrt(n) + 1;
    vector<int> b(len);
    for (int i = 0; i < n; i++)
    {
        b[i / len] += v[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int sum = 0;
        for (int i = l; i <= r;)
        {
            if (i % len == 0 && i + len - 1 <= r)
            {
                sum += b[i / len];
                i += len;
            }
            else
            {
                sum += v[i];
                i++;
            }
        }
        cout << sum << endl;
    }
}
// Number of query = Q
// Time taken each query = O(root(n))
// Time taken by each query = O(Q*root(n))