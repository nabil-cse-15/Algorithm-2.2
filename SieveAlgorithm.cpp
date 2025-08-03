#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
vector<bool> isPrime(N, 1);
//bitset<N>isPrime;
int main()
{
    //isPrime.set(); faster than vector<bool> for large N
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        if (isPrime[num])
        {
            cout << num << " is Prime" << endl;
        }
        else
            cout << num << " is NOT Prime" << endl;
    }
    // N*log(log(N))
}