//Using bitwise xor
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[9] = {1, 2, 4, 5, 6, 8, 9, 7};
    int xor1 = 0, xor2 = 0;
    for (int i = 1; i <= 9; i++)
    {
        xor1 ^= i;
    }
    for (int i = 0; i < 9; i++)
    {
        xor2 ^= a[i];
    }
    int ans = xor1 ^ xor2;
    cout << ans;
}