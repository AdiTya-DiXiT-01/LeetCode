/*
* FIRST INTUTIVE APPROACH
*/

class Solution
{
public:
    int beautySum(string s)
    {

        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> m;
            m[s[i]]++;
            for (int j = i + 1; j < n; j++)
            {
                m[s[j]]++;

                int low = INT_MAX;
                int high = INT_MIN;

                for (auto it : m)
                {
                    low = min(low, it.second);
                    high = max(high, it.second);
                }

                if (low != INT_MAX and high != INT_MIN)
                {
                    ans += high - low;
                }
            }
        }

        return ans;
    }
};
