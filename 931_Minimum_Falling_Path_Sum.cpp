/*
* MEMOIZATION CODE 
* TLE
*/

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
    {
        if (j < 0 || j >= a.size())
            return 1e9;

        if (i == 0)
            return a[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int down = a[i][j] + f(i - 1, j, a, dp);
        int ld = a[i][j] + f(i - 1, j - 1, a, dp);
        int rd = a[i][j] + f(i - 1, j + 1, a, dp);

        return dp[i][j] = min(down, min(rd, ld));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, f(n - 1, i, matrix, dp));
        }
        return ans;
    }
};

/*
* PROBLEM ON DP
* TABULATION CODE
*/
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &a)
    {
        int n = a.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            dp[0][i] = a[0][i];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ld = 0, rd = 0;
                int down = a[i][j] + dp[i - 1][j];
                if (j - 1 >= 0)
                    ld = a[i][j] + dp[i - 1][j - 1];
                if (j + 1 < m)
                    rd = a[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min(down, min(rd, ld));
            }
        }

        int ans = dp[n - 1][0];
        for (int i = 1; i < n; i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }

        return ans;
    }
};
