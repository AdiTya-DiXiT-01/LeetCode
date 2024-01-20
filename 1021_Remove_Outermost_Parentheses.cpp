/*
* FIRST INTUTIVE APPROACH USING STACK
*/

class Solution
{
public:
    string removeOuterParentheses(string s)
    {

        int n = s.size();
        stack<char> st;
        string ans = "";

        for (int i = 0; i < n; i++)
        {

            if (s[i] == '(')
            {
                if (!st.empty())
                    ans += s[i];

                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                st.pop();
                if (!st.empty())
                    ans += s[i];
            }
        }

        return ans;
    }
};

/*
* BETTER APPROACH WITHOUT STACK
*/
class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = s.size();
        string ans = "";
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' and cnt == 0)
            {
                cnt++;
            }
            else if (s[i] == '(' and cnt >= 1)
            {
                ans += s[i];
                cnt++;
            }
            else if (s[i] == ')' and cnt > 1)
            {
                ans += s[i];
                cnt--;
            }
            else if (s[i] == ')')
            {
                cnt--;
            }
        }

        return ans;
    }
};

