/*
* REDO THE PROBLEM
*/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long num = 0;
        int i = 0;

        while ((s[i] == ' ') and (i < n))
            i++;

        int c = 1;
        if (s[i] == '-') {
            c = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        while (i < n) {
            if (!isdigit(s[i])) {
                break;
            } else if (isdigit(s[i])) {
                if (num * 10 + (s[i] - '0') > INT_MAX) {
                    if (c == -1)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }

                int x = s[i] - '0';
                num = num * 10 + x;
            }
            i++;
        }

        if (c == -1)
            num *= -1;

        return (int)num;
    }
};
