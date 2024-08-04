#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Function to find all unique triplets in the array that sum up to zero
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans; // Vector to store the result triplets
    int n = nums.size();
    int target = 0;
    sort(nums.begin(), nums.end()); // Sort the input array
    set<vector<int>> st;            // Set to store unique triplets
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target)
            {
                st.insert({nums[i], nums[j], nums[k]}); // Insert triplet into set if sum is zero
                j++;
                k--;
            }
            else if (sum < target)
            {
                j++; // Move the left pointer to the right
            }
            else
            {
                k--; // Move the right pointer to the left
            }
        }
    }
    for (auto &tri : st)
    {
        ans.push_back(tri); // Convert set to vector
    }
    return ans;
}

// Function to take user input and find the triplets that sum to zero
void takeUserInputAndFindThreeSum()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> result = threeSum(nums); // Find triplets
    cout << "The triplets that sum to zero are: \n";
    for (auto &triplet : result)
    {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); i++)
        {
            cout << triplet[i];
            if (i < triplet.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
}

int main()
{
    takeUserInputAndFindThreeSum();
    return 0;
}
