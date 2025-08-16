#include <bits/stdc++.h>
using namespace std;

int dp[205][20005]; // -1 means uncomputed

bool func(int ind, int target, vector<int> &arr)
{
    if (target == 0)
        return true; // found subset
    if (ind < 0)
        return false; // no elements left

    if (dp[ind][target] != -1)
        return dp[ind][target]; // already computed

    // not take current element
    bool isPossible = func(ind - 1, target, arr);

    // take current element if it doesn't exceed target
    if (target >= arr[ind])
        isPossible |= func(ind - 1, target - arr[ind], arr);

    return dp[ind][target] = isPossible;
}

int main()
{
    // vector<int> arr = {1, 2, 3, 2, 4, 5, 6};
    vector<int> arr = {1, 5, 1, 4};
    int target = 15;
    memset(dp, -1, sizeof(dp)); // initialize dp with -1

    if (func(arr.size() - 1, target, arr))
        cout << "True\n";
    else
        cout << "False\n";
}

// #include <bits/stdc++.h>
// using namespace std;

// int dp[205][20005];

// bool func(int ind, int target, vector<int> &arr)
// {
//     if (target == 0)
//         return true;
//     if (ind < 0)
//         return false;

//     if (dp[ind][target] != -1)
//         return dp[ind][target];

//     bool isPossible = func(ind - 1, target, arr);

//     if (target >= arr[ind])
//         isPossible |= func(ind - 1, target - arr[ind], arr);

//     return dp[ind][target] = isPossible;
// }

// void collectSubsets(int ind, int target, vector<int> &arr,
//                     vector<int> &current, vector<vector<int>> &result)
// {
//     if (target == 0)
//     {
//         result.push_back(current);
//         return;
//     }
//     if (ind < 0)
//         return;

//     // Option 1: skip element
//     if (func(ind - 1, target, arr))
//     {
//         collectSubsets(ind - 1, target, arr, current, result);
//     }

//     // Option 2: take element
//     if (target >= arr[ind] && func(ind - 1, target - arr[ind], arr))
//     {
//         current.push_back(arr[ind]);
//         collectSubsets(ind - 1, target - arr[ind], arr, current, result);
//         current.pop_back();
//     }
// }

// int main()
// {
//     vector<int> arr = {1, 5, 1, 4};
//     int target = 6;

//     memset(dp, -1, sizeof(dp));

//     if (func(arr.size() - 1, target, arr))
//     {
//         cout << "True\n";
//         vector<vector<int>> result;
//         vector<int> current;

//         collectSubsets(arr.size() - 1, target, arr, current, result);

//         cout << "All subsets:\n";
//         for (auto &subset : result)
//         {
//             for (int x : subset)
//                 cout << x << " ";
//             cout << "\n";
//         }
//     }
//     else
//     {
//         cout << "False\n";
//     }
// }
