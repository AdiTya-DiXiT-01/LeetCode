/*
* DP MEMOIZATION CODE
*/

class Solution {
public:
    int f(int i, vector<int>& a, vector<int>& dp) {
        if (i < 0)
            return 0;
        if (i == 0)
            return a[i];

        if (dp[i] != -1)
            return dp[i];

        int pick = a[i] + f(i - 2, a, dp);
        int notpick = f(i - 1, a, dp);

        return dp[i] = max(pick, notpick);
    }
    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, -1);
        return f(n - 1, a, dp);
    }
};

/*
* MEMOIZATION CODE TO TABULATED CODE
*/

class Solution {
public:
    int rob(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 0);
        dp[0] = a[0];

        for (int i = 1; i < n; i++) {
            int pick = a[i];

            if (i >= 2)
                pick += dp[i - 2];

            int notpick = dp[i - 1];

            dp[i] = max(pick, notpick);
        }

        return dp[n - 1];
    }
};
