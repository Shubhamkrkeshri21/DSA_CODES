#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Function to find all unique quadruplets in the array that sum up to zero
vector<vector<int>> fourSum(vector<int> &nums)
{
    vector<vector<int>> ans;        // Vector to store the result quadruplets
    int target = 0;                 // Target sum for the quadruplets
    sort(nums.begin(), nums.end()); // Sort the input array
    set<vector<int>> st;            // Set to store unique quadruplets
    int n = nums.size();

    // Iterate through the array with four pointers
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicates
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && nums[j] == nums[j - 1]) // Skip duplicates
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                int sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum == target)
                {
                    st.insert({nums[i], nums[j], nums[k], nums[l]}); // Insert quadruplet into set
                    k++;
                    l--;
                }
                else if (sum < target)
                {
                    k++; // Move the third pointer to the right
                }
                else
                {
                    l--; // Move the fourth pointer to the left
                }
            }
        }
    }

    // Convert set to vector
    for (auto &quad : st)
    {
        ans.push_back(quad);
    }

    return ans;
}

// Function to take user input and find the quadruplets that sum to zero
void takeUserInputAndFindFourSum()
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

    vector<vector<int>> result = fourSum(nums); // Find quadruplets
    cout << "The quadruplets that sum to zero are: \n";
    for (auto &quad : result)
    {
        cout << "[";
        for (size_t i = 0; i < quad.size(); i++)
        {
            cout << quad[i];
            if (i < quad.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
}

int main()
{
    takeUserInputAndFindFourSum();
    return 0;
}
