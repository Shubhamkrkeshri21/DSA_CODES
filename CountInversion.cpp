#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to merge two halves and count inversions
    long long merge(vector<long long> &arr, int low, int mid, int high) {
        vector<long long> temp; // temporary array
        int left = low;   // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr

        long long cnt = 0; // to count the pairs

        // Merging elements in sorted order and counting inversions
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); // all elements in left half are greater than arr[right]
                right++;
            }
        }

        // If elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // If elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy sorted elements back to the original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    // Function to perform merge sort and count inversions
    long long mergeSort(vector<long long> &arr, int low, int high) {
        long long cnt = 0;
        if (low < high) {
            int mid = (low + high) / 2;
            cnt += mergeSort(arr, low, mid); // left half
            cnt += mergeSort(arr, mid + 1, high); // right half
            cnt += merge(arr, low, mid, high); // merging sorted halves
        }
        return cnt;
    }

    // Function to count inversions in the array
    long long int inversionCount(long long arr[], int n) {
        vector<long long> vec(arr, arr + n);
        return mergeSort(vec, 0, n - 1);
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    long long arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution sol;
    long long result = sol.inversionCount(arr, n);

    cout << "Number of inversions: " << result << endl;

    return 0;
}
