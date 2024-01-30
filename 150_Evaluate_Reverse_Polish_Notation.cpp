class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op1 + op2);
            } else if (tokens[i] == "/") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 / op1);
            } else if (tokens[i] == "-") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op2 - op1);
            } else if (tokens[i] == "*") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(op1 * op2);
            } else {
                int x = stoi(tokens[i]);
                st.push(x);
            }
        }

        int ans = st.top();
        st.pop();
        return ans;
    }
};
