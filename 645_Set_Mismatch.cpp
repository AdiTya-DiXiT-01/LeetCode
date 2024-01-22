class Solution
{
public:
    vector<int> findErrorNums(vector<int> &a)
    {
        int n = a.size();
        vector<int> hash(n + 1, 0);
        vector<int> ans(2, 0);
        for (int i : a)
        {
            hash[i]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (hash[i] == 2)
            {
                ans[0] = i;
            }
            else if (hash[i] == 0)
            {
                ans[1] = i;
            }
        }

        return ans;
    }
};
