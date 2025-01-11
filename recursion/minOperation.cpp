#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        int count = 0;

        // Take user input for vector elements
        cout << "Enter " << nums.size() << " elements for nums:" << endl;
        for (int i = 0; i < nums.size(); ++i) {
            cin >> nums[i];
        }

        // Initialize the set with values 1 to k
        for (int i = 1; i <= k; i++){
            s.insert(i);
            cout<<"Iterataion at : "<<i<<endl;
        }

        // Iterate over nums in reverse and check for set membership
        for (int i = nums.size() - 1; i >= 0 && !s.empty(); i--) {
            count++;
            cout<<nums[i]<<endl;
            if (s.find(nums[i]) != s.end())
                s.erase(nums[i]);
        }

        return count;
    }
};

int main() {
    Solution solution;
    
    // Take user input for vector size and k
    int n, k;
    cout << "Enter the size of the vector (n): ";
    cin >> n;

    cout << "Enter the value of k: ";
    cin >> k;

    // Create vector of size n
    vector<int> nums(n);

    // Call the function
    int result = solution.minOperations(nums, k);

    // Output the result
    cout << "Result: " << result << endl;

    return 0;
}