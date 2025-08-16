#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> &arr, int target){

    int left = 0, right = arr.size() - 1;
    while (left < right){
        int sum = arr[left] + arr[right];

        if (sum == target)
            return true;
        
        // Move toward a higher sum
        else if (sum < target)
            left++; 
      
        // Move toward a lower sum
        else
            right--; 
    }
  
    // If no pair found
    return false;
}

int main(){
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    int target = 120;
    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";

    return 0;
}