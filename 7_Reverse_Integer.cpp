// BASIC FIRST SELF OPTIMAL APPROACH

class Solution {
public:
    int reverse(int x) {

        long long int y = 0;
        int n = 0;
        // 2147483648
        if (x < 0 and (x > -2147483648)) {
            n = -1 * x;
        } else {
            n = x;
        }

        while (n > 0) {
            int temp = n % 10;
            y = y * 10 + temp;
            n /= 10;
        }

        if(y > 2147483647)
            return 0;

        int ans = y;
        if (x < 0) {
            ans *= -1;
            return ans;
        }

        return ans;
    }
};

// BETTER OPTIMIZED CODE USING (INT_MAX / 10)

class Solution {
public:
    int reverse(int x) {

        int rev = 0;

        while (x != 0) {
            //WE CHECK IF VALUE OF REV SURPASSES INT_MAX/10 AS IN THE NEXT STEP WE NEED TO MULTIPLY WITH 10 AND IT MIGHT EXCEED INT VALUE
            if (rev > INT_MAX / 10 or rev < INT_MIN / 10)
                return 0;

            rev = rev * 10 + (x % 10);
            x /= 10;
        }

        return rev;
    }
};
