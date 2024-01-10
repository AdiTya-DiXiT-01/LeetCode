// BASIC RECURSIVE CODE

class Solution {
public:
    int fib(int n) {
        
        if(n < 0)
            return 0;

        if(n == 1 or n == 0)
            return n;

        return fib(n - 2) + fib(n - 1);
    }
};

// OPTIMIZED MEMOIZED CODE

class Solution
{
public:
    int fib(int n)
    {   
        if(n == 0 or n == 1)
            return n;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }
};
