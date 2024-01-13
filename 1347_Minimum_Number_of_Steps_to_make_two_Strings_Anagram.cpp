//FIRST TRY--- INTUTIVE APPROACH

class Solution
{
public:
    int minSteps(string s, string t)
    {

        map<char, int> m;

        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;

        sort(t.begin(), t.end());

        for (int i = 0; i < t.size(); i++)
        {
            auto it = m.find(t[i]);
            if (it != m.end())
            {
                if (it->second > 1)
                {
                    it->second--;
                }
                else
                {
                    m.erase(t[i]);
                }
            }
        }
        int ans = 0;
        for (auto it : m)
        {
            ans += it.second;
        }

        return ans;
    }
};
