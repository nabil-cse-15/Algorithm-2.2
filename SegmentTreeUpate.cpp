// Update value at node k to +u and find max value between l and r. If v[k] = 5 u = 3 then after update v[k] = 8
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
    if (low >= l && high <= r)
        return seg[ind];
    if (high < l || low > r)
        return INT_MIN;
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}
void pointUpdate(int ind, int low, int high, int node, int val)
{
    if (low == high)
        seg[ind] += val;
    else
    {
        int mid = (low + high) / 2;
        if (node <= mid && node >= low)
            pointUpdate(2 * ind + 1, low, mid, node, val);
        else
            pointUpdate(2 * ind + 2, mid + 1, high, node, val);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
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
        int l, r, k, u;
        cin >> l >> r >> k >> u;
        pointUpdate(0, 0, n - 1, k, u);
        cout << query(0, 0, n - 1, l, r) << " ";
    }
}

