// Basic intutive approach 
// vishal help
//REDO
class Solution
{
public:
    bool solve(int n, int m)
    {
        if ((n > 1 and n < 7) or (n == 8) or (n == 9))
            return false;

        int sum = 0;
        while (n > 0)
        {
            int x = n % 10;
            sum += pow(x, 2);
            n /= 10;
        }

        if (sum == 1)
            return true;
        if (sum == m)
            return false;

        return solve(sum, m);
    }
    bool isHappy(int n)
    {
        return solve(n, n);
    }
};

// INTUTION - ALL SINGLE DIGIT NUMBERS EXCEPT 1 AND 7 ARE NOT HAPPY NUMBERS....
// OPTIMIZED APPROACH

class Solution
{
public:
    int sum(int n)
    {
        int s = 0;
        while (n > 0)
        {
            int x = n % 10;
            s += x * x;
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n)
    {
        while (n >= 10)
        {
            n = sum(n);
        }

        return n == 1 or n == 7;
    }
};
