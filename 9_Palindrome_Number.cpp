// AS TO PREVENT THE INT FROM OVERFLOW WE USE LONG LONG INT INSTEAD OF INT TO PREVENT OVERFLOW WHILE MULTIPLING WITH 10 INSIDE THE WHILE LOOP(TO REVERSE THE NUMBER)

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int n = x;
        long long int palin = 0;
        while (n > 0)
        {
            int temp = n % 10;
            palin = palin * 10 + temp; //OVERFLOW IF INT USED
            n /= 10;
        }

        if (x == palin)
            return true;
        return false;
    }
};
