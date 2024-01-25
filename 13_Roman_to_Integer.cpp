class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans = 0;
        int i = n - 1;
        while (i > 0) {
            if (m[s[i - 1]] < m[s[i]]) {
                ans = ans + (m[s[i]] - m[s[i - 1]]);
                i -= 2;
            } else {
                ans += m[s[i]];
                i--;
            }
        }
        if (i == 0) {
            ans += m[s[i]];
        }
        return ans;
    }
};
