/*
* FIRST APPROACH USING A RECURSIVE APPROACH AND MEMOIZATION
*/

class Solution
{
public:
    int solve(string &s, int l, int r, vector<vector<int>> &dp)
    {
        if (l >= r)
            return 1;

        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] == s[r])
        {
            return solve(s, l + 1, r - 1, dp);
        }

        return dp[l][r] = false;
    }
    string longestPalindrome(string s)
    {

        int n = s.length();
        int ln = 1, maxln = 1;
        string ans = s.substr(0,1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (solve(s, i, j, dp))
                {
                    ln = j - i + 1;
                    if (ln > maxln)
                    {
                        ans = s.substr(i, ln);
                        maxln = ln;
                    }
                }
            }
        }

        return ans;
    }
};

/*
* OPTIMIZED APPROACH USING TWO POINTERS 
* TC - O(N2)
*/

class Solution
{
public:
    string longestPalindrome(string s)
    {

        int n = s.length();
        int ln = 1, maxln = 1;
        string ans = s.substr(0, 1);

        for (int i = 0; i < n - 1; i++)
        {
            int l = i, r = i;
            while (l >= 0 and r < n and s[l] == s[r])
            {
                if (maxln < (r - l + 1))
                {
                    maxln = r - l + 1;
                    ans = s.substr(l, maxln);
                }
                l--;
                r++;
            }

            l = i, r = i + 1;

            while (l >= 0 and r < n and s[l] == s[r])
            {
                if (maxln < (r - l + 1))
                {
                    maxln = r - l + 1;
                    ans = s.substr(l, maxln);
                }
                l--;
                r++;
            }
        }

        return ans;
    }
};
