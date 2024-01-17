/*
* FIRST INTUTIVE APPROACH USING VECTOR TO HASH UNIQUE FREQENCIES
<----------LEETCODE STREAK 5---------->
*/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &a)
    {

        unordered_map<int, int> m;
        vector<bool> freq(1000, false);

        for (auto it : a)
            m[it]++;

        for (auto it : m)
        {
            int curr = it.second;

            if (freq[curr])
            {
                return false;
            }
            else
            {
                freq[curr] = true;
            }
        }

        return true;
    }
};

/*
* OPTIMAL APPROACH 
* USING UNORDERED SET INSTEAD OF VECTOR TO REDUCE TC
*/

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &a)
    {

        unordered_map<int, int> m;

        for (auto it : a)
            m[it]++;

        unordered_set<int> s;
        for (auto it : m)
        {
            int curr = it.second;

            if (s.find(curr) == s.end())
            {
                s.insert(curr);
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};
