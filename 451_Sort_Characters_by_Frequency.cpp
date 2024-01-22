/*
* INTUTIVE APPROACH 
* USING MAP AND ALSO A VECTOR OF PAIRS
*/

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> m;

        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;

        vector<pair<int, char>> v;
        for (auto it : m)
            v.push_back({it.second, it.first});

        sort(v.begin(), v.end());
        string ans = "";
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int k = v[i].first;
            while (k--)
                ans += v[i].second;
        }

        return ans;
    }
};

/*
* MORE SPACE OPTIMIZED METHOD WHICH ONLY USES VECTOR OF PAIR
*/

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> v;
        for (int i = 0; i < 256; i++) {
            v.push_back({0, i});
        };
        for (int i = 0; i < s.size(); i++) {
            v[s[i]].first++;
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());
        string ans = "";
        for (int i = 0; i < v.size(); i++) {
            int k = v[i].first;
            while (k--)
                ans += v[i].second;
        }

        return ans;
    }
};
