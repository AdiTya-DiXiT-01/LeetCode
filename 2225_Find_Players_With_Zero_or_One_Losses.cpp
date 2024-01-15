/*
LEETCODE DAILY STREAK QUESTION
FIRST INTUTIVE APPROACH USING MAPS AND COUNTING FREQUENCY
*/

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &m)
    {

        map<int, int> w;
        map<int, int> l;

        for (int i = 0; i < m.size(); i++)
        {
            w[m[i][0]]++;
            l[m[i][1]]++;
        }
        vector<int> a1, a2;
        for (auto it : w)
        {
            if (l.find(it.first) == l.end())
            {
                a1.push_back(it.first);
            }
        }
        for (auto it : l)
        {
            if (it.second == 1)
                a2.push_back(it.first);
        }
        vector<vector<int>> ans;
        ans.push_back(a1);
        ans.push_back(a2);

        return ans;
    }
};
