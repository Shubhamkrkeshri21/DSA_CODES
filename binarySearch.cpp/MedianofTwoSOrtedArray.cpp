#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()) {
        swap(a, b);
    }
    int n = a.size(), m = b.size();
    int low = 0, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        int pos = ((n + m + 1) / 2) - mid;
        
        if (mid < n && b[pos-1] > a[mid]) {
            low = mid + 1;
        } else if (mid > 0 && a[mid-1] > b[pos]) {
            high = mid - 1;
        } else {
            int maxLeft = 0;
            if (mid == 0) {
                maxLeft = b[pos-1];
            } else if (pos == 0) {
                maxLeft = a[mid-1];
            } else {
                maxLeft = max(a[mid-1], b[pos-1]);
            }
            
            if ((n + m) % 2 == 1) {
                return maxLeft;
            }
            
            int minRight = 0;
            if (mid == n) {
                minRight = b[pos];
            } else if (pos == m) {
                minRight = a[mid];
            } else {
                minRight = min(a[mid], b[pos]);
            }
            
            return (maxLeft + minRight) / 2.0;
        }
    }
    
    return 0.0;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    double median = findMedianSortedArrays(a, b);
    cout << median << endl;
    return 0;
}
