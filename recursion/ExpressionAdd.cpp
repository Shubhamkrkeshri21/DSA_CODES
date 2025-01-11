#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void operators(int ind, string num, int target, string temp, vector<string> &ans, long long prev, long long res) {
        if (ind == num.size()) {
            if (res == target) {
                ans.push_back(temp);
            }
            return;
        }
        string st = "";//taking an empty string
        long long curr = 0;
        for (int i = ind; i < num.size(); i++) {
            if (i > ind && num[ind] == '0') {
                break;
            }
            st += num[i];
            curr = curr * 10 + num[i] - '0';
            if (ind == 0) {
                operators(i + 1, num, target, temp + st, ans, curr, curr);
            } else {
                operators(i + 1, num, target, temp + "+" + st, ans, curr, curr + res);
                operators(i + 1, num, target, temp + "-" + st, ans, -curr, res - curr);
                operators(i + 1, num, target, temp + "*" + st, ans, prev * curr, res - prev + prev * curr);
            }
        }
        return;
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string temp;
        long long prev = 0;
        operators(0, num, target, temp, ans, prev, 0);
        return ans;
    }
};

int main() {
    Solution solution;
    string num;
    int target;

    // Taking user input for num and target
    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the target: ";
    cin >> target;

    vector<string> result = solution.addOperators(num, target);

    // Displaying the result
    cout << "Resulting expressions:" << endl;
    for (const string &expr : result) {
        cout << expr << endl;
    }

    return 0;
}
