#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    vector<int> b(len,INT_MIN);
    
    // Build sqrt decomposition array: minimum in each block
    for (int i = 0; i < n; i++)
    {
        b[i / len] = max(b[i / len], v[i]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;r--;
        int ans = INT_MIN;
        for (int i = l; i <= r;)
        {
            if (i % len == 0 && i + len - 1 <= r)
            {
                ans = max(ans, b[i / len]);
                i += len;
            }
            else
            {
                ans = max(ans, v[i]);
                i++;
            }
        }
        cout << ans << endl;
    }
}
