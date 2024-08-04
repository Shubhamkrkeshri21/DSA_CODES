#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        int n = nums.size();
        std::vector<int> ans(n, 1);

        // Forward pass
        int prefixProduct = 1;
        for (int i = 0; i < n; ++i)
        {
            ans[i] *= prefixProduct;
            prefixProduct *= nums[i];
            cout << ans[i] << ",";
        }

        // Backward pass
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            ans[i] *= suffixProduct;
            suffixProduct *= nums[i];
            cout << ans[i] << ",";
        }
        cout << endl;
        return ans;
    }
};

int main()
{
    Solution solution;

    // Get user input for vector
    std::cout << "Enter the size of the vector: ";
    int size;
    std::cin >> size;

    std::vector<int> nums(size);
    std::cout << "Enter the elements of the vector: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> nums[i];
    }

    // Call the function and display the result
    std::vector<int> result = solution.productExceptSelf(nums);

    std::cout << "Result: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
