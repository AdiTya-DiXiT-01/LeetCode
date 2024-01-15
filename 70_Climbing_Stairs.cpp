/*
RECURSIVE MEMOIZATION APPROACH
*/
class Solution {
public:
    int f(int idx, vector<int>& dp) {
        if (idx < 2)
            return idx == 1 or idx == 0;
        if (dp[idx] != -1)
            return dp[idx];
        int one = f(idx - 1, dp);
        int two = f(idx - 2, dp);

        return dp[idx] = one + two;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};

/*
CONVERSION OF RECURSIVE APPROACH TO TABULATED CODE
*/

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int one = dp[i - 1];
            int two = dp[i - 2];

            dp[i] = one + two;
        }

        return dp[n];
    }
};
