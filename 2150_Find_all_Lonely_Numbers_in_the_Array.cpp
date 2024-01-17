/*
* THIS IS A INTUTIVE APPROACH 
* CAN ALSO BE SOLVED USING SORTING AND THEN USING IF_EL CONDITIONS IN THE FOR LOOP
*/

class Solution
{
public:
    vector<int> findLonely(vector<int> &a)
    {
        unordered_map<int, int> m;

        for (auto it : a)
            m[it]++;
        vector<int> ans;
        for (auto it : m)
        {
            int x = it.first;
            if (it.second > 1)
                continue;

            if (m.find(x + 1) == m.end() and m.find(x - 1) == m.end())
                ans.push_back(x);
        }

        return ans;
    }
};
