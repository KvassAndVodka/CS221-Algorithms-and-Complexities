/*
4. Edit Distance
Given two strings, find the minimum number of single-character edits (insertions,
deletions, substitutions) required to transform one string into the other.
*/

#include <iostream>

using namespace std;

int minEditDistance(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    // Create a table to store results of subproblems
    int dp[m + 1][n + 1];

    // Base cases
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
        if (str1[i - 1] == str2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
        } else {
            dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
        }
    }

    // Return the minimum edit distance
    return dp[m][n];
}

int main() {
    string str1, str2;

    cout << "str1: ";
    cin >> str1;
    cout << "str2: ";
    cin >> str2;

    int minDistance = minEditDistance(str1, str2);

    cout << "Minimum edit distance: " << minDistance << endl;

    return 0;
}
