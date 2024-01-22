class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                int x = st.size();
                ans = max(ans, x);
            } else if (s[i] == ')') {
                st.pop();
            } else {
                continue;
            }
        }

        return ans;
    }
};
