#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Global variable to store the final result
vector<string> result;

// Recursive function to generate letter combinations
void solve(int idx, string &digits, string &temp, unordered_map<char, string> &mp) {

    // Base case: If the index exceeds the length of digits, add the current combination to the result
    if (idx >= digits.length()) {
        result.push_back(temp);
        return;
    }

    // Get the current digit and its corresponding string
    char ch = digits[idx];
    string str = mp[ch];

    // Iterate over the characters in the string corresponding to the current digit
    for (int i = 0; i < str.length(); i++) {

        // Do: Append the current character to the temporary string
        temp.push_back(str[i]);
        cout<<"ans at iteration "<<i<<" : "<<temp<<endl;;
        // Recursively call the function for the next digit
        solve(idx + 1, digits, temp, mp);

        // Undo: Backtrack by removing the last character to explore other possibilities
        temp.pop_back();
    }
}

// Function to generate letter combinations for a given digit string
vector<string> letterCombinations(string digits) {
    // If the input string is empty, return an empty vector
    if (digits.length() == 0)
        return {};

    // Mapping of digits to corresponding strings
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    // Temporary string to store the current combination
    string temp = "";

    // Call the recursive function to generate letter combinations
    solve(0, digits, temp, mp);

    // Return the final result
    return result;
}

int main() {
    // Example usage
    string digits;
    cout << "Enter a string of digits (e.g., '23'): ";
    cin >> digits;

    // Generate and display letter combinations
    vector<string> combinations = letterCombinations(digits);
    cout << "Letter Combinations:\n";
    for (const string &combo : combinations) {
        cout << combo << " ";
    }

    return 0;
}
