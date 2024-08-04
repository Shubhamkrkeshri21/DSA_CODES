// Kadane's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long int maxSubarraySum(vector<int>& arr) {
        if (arr.empty()) return 0;
        
        long long int max_current = arr[0];
        long long int max_global = arr[0];
        
        for (size_t i = 1; i < arr.size(); ++i) {
            max_current = max((long long int)arr[i], max_current + arr[i]);
            if (max_current > max_global) {
                max_global = max_current;
            }
        }
        
        return max_global;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 3, -2, 5};
    vector<int> arr2 = {-1, -2, -3, -4};
    vector<int> arr3 = {5, 4, 7};
    
    cout << "Maximum Subarray Sum for arr1: " << sol.maxSubarraySum(arr1) << endl;
    cout << "Maximum Subarray Sum for arr2: " << sol.maxSubarraySum(arr2) << endl;
    cout << "Maximum Subarray Sum for arr3: " << sol.maxSubarraySum(arr3) << endl;
    
    return 0;
}
