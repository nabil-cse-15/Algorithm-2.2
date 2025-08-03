#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
int binExp(int base, int power)
{

    if (power == 0)
        return 1;
    long long res = binExp(base, power / 2);
    if (power & 1)
    {
        return (base * (res * res) % M) % M;
    }
    else
        return (res * res) % M;
}
int main()
{
    int base, power;
    cin >> base >> power;
    cout << binExp(base, power);
}