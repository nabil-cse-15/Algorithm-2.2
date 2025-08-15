#include <bits/stdc++.h>
using namespace std;

int dp[205][20005]; // -1 means uncomputed

bool func(int ind, int target, vector<int> &arr) {
    if (target == 0) return true; // found subset
    if (ind < 0) return false;    // no elements left

    if (dp[ind][target] != -1) 
        return dp[ind][target]; // already computed

    // not take current element
    bool isPossible = func(ind - 1, target, arr);

    // take current element if it doesn't exceed target
    if (target >= arr[ind])
        isPossible |= func(ind - 1, target - arr[ind], arr);

    return dp[ind][target] = isPossible;
}

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 5, 6};
    int target = 5;

    memset(dp, -1, sizeof(dp)); // initialize dp with -1

    if (func(arr.size() - 1, target, arr))
        cout << "True\n";
    else
        cout << "False\n";
}
