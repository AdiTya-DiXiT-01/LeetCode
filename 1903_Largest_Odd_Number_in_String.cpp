class Solution {
public:
    string largestOddNumber(string s) {
        int i = s.size() - 1;
        while (s.size() > 0) {
            int x = s[i] - '0';
            if (x % 2 == 1) {
                break;
            }
            s.pop_back();
            i--;
        }

        return s;
    }
};
