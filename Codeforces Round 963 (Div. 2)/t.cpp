#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSubsequences(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();
    
    // Create a 2D DP array
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // If s1 is empty, there's exactly 1 subsequence of s2 that matches s1 (the empty subsequence)
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
    }
    
    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // If characters match, take sum of previous subsequences and exclude the current character
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    
    // The answer is in dp[m][n]
    return dp[m][n];
}

int main() {
    string s1 = "ab";
    string s2 = "abcbadb";

    int result = countSubsequences(s1, s2);
    cout << "Number of times \"" << s1 << "\" exists in \"" << s2 << "\": " << result << endl;

    return 0;
}
