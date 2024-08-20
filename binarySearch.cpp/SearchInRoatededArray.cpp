#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate the middle index
            if (nums[mid] == target) { // If middle element is the target, return its index
                return mid;
            }
            if (nums[s] <= nums[mid]) { // If left half is sorted
                if (nums[s] <= target && target < nums[mid]) { // If target is in left half
                    e = mid - 1; // Adjust end index to search in left half
                } else {
                    s = mid + 1; // Adjust start index to search in right half
                }
            } else { // If right half is sorted
                if (nums[mid] < target && target <= nums[e]) { // If target is in right half
                    s = mid + 1; // Adjust start index to search in right half
                } else {
                    e = mid - 1; // Adjust end index to search in left half
                }
            }
        }
        return -1; // Target not found
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example input vector
    int target = 0; // Target value to search for
    int result = solution.search(nums, target); // Call the search method
    if (result != -1) { // Check if target was found
        cout << "Target " << target << " found at index " << result << endl;
    } else {
        cout << "Target " << target << " not found in the array." << endl;
    }
    return 0; // Exit the program
}
