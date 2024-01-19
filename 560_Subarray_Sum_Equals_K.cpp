/*
****  IMPORTANT QUESTION ****
* REDO
*/

class Solution
{
public:
    int subarraySum(vector<int> &a, int k)
    {
        unordered_map<int, int> m;
        int ans = 0, sum = 0;
        m[0] = 1;
        for (int i = 0; i < a.size(); i++)
        {
            sum += a[i];
            auto it = m.find(sum - k);
            if (it != m.end())
            {
                ans += it->second;
            }
            m[sum]++;
        }

        return ans;
    }
};
