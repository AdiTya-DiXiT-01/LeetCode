/*
* APPROACH USING QUEUE
*/

class Solution
{
public:
    bool rotateString(string s, string g)
    {
        if (s.size() != g.size())
            return false;
        int n = s.size();
        queue<char> q1, q2;

        for (int i = 0; i < n; i++)
        {
            q1.push(s[i]);
            q2.push(g[i]);
        }

        while (n--)
        {
            if (q1 == q2)
                return true;
                
            char c = q2.front();
            q2.pop();
            q2.push(c);
        }
        return false;
    }
};

/*
* GIVING WRONG ANSWER ON ONLY ONE TC
*/

class Solution
{
public:
    bool rotateString(string s, string g)
    {
        if (s.size() != g.size())
            return false;

        string str = g + g;
        int n = s.size();
        int j = 0, i = 0;
        while (i < (2 * n))
        {
            if (g[j] == str[i])
            {
                j++;
                i++;
                if (j == n)
                    return true;
            }
            else
            {
                if (j != 0)
                    j = 0;
                else
                    i++;
            }
        }

        return false;
    }
};
