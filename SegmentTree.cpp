// Max value finding in a range
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> v(N);
vector<int> seg(4 * N);
void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = v[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int query(int ind, int low, int high, int l, int r)
{
    // Complete overlap
    if (low >= l && high <= r)
        return seg[ind];

    // No overlap
    if (high < l || low > r)
        return INT8_MIN;
        
    // Partial overlap
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    build(0, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << " ";
    }
}