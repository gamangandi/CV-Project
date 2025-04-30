#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sender(n);
    for (int i = 0; i < n; ++i) {
        cin >> sender[i];
    }

    int m;
    cin >> m;
    vector<int> receiver(m);
    for (int i = 0; i < m; ++i) {
        cin >> receiver[i];
    }

    // LCS DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill the LCS table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (sender[i - 1] == receiver[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
