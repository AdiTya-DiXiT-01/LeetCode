class Solution
{
public:
    bool isPalindrome(string s)
    {

        int n = s.size();
        string s_new = "";
        string rev = "";
        for (int i = 0; i < n; i++)
        {
            if ((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z'))
            {
                s_new += tolower(s[i]);
            }
            else if (isdigit(s[i]))
            {
                s_new += s[i];
            }
        }
        rev = s_new;
        reverse(rev.begin(), rev.end());
        if (rev == s_new)
            return true;

        return false;
    }
};
