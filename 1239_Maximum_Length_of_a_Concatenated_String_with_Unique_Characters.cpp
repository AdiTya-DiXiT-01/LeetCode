class Solution
{
public:
    void f(int i, int s, int &ans, int n, vector<int> vis, vector<string> &arr)
    {
        if (i >= n)
            return;
        f(i + 1, s, ans, n, vis, arr);

        for (int j = 0; j < arr[i].size(); j++)
        {
            int x = arr[i][j] - 'a';
            vis[x]++;
            if (vis[x] > 1)
                return;
        }

        s = s + arr[i].size();
        ans = max(s, ans);

        f(i + 1, s, ans, n, vis, arr);
    }
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        vector<int> vis(26, 0);
        int ans = 0;
        f(0, 0, ans, n, vis, arr);
        return ans;
    }
};
