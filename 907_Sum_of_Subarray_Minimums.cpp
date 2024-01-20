/*
* GOOD QUESTION OF MONOTONIC STACK 
* MUST REDO
*/

class Solution
{
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int> &a)
    {

        int n = a.size();
        stack<int> st;
        vector<int> left(n, -1), right(n, n);
        long ans = 0;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and (a[st.top()] >= a[i]))
            {
                st.pop();
            }

            if (!st.empty())
            {
                left[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and (a[st.top()] > a[i]))
            {
                st.pop();
            }

            if (!st.empty())
            {
                right[i] = st.top();
            }
            st.push(i);
        }

        for (int i = 0; i < n; i++)
        {
            long cnt = (i - left[i]) * (right[i] - i) % mod;
            ans += (cnt * a[i]) % mod;
            ans %= mod;
        }
        return static_cast<int>(ans);
    }
};
