/*
* FIRST INTUTIVE APPROACH
*/
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &a)
    {

        vector<int> pos;
        vector<int> neg;
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                neg.push_back(a[i]);
            }
            else
            {
                pos.push_back(a[i]);
            }
        }

        vector<int> ans;
        reverse(pos.begin(), pos.end());
        reverse(neg.begin(), neg.end());
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans.push_back(pos.back());
                pos.pop_back();
            }
            else
            {
                ans.push_back(neg.back());
                neg.pop_back();
            }
        }

        return ans;
    }
};

/*
* OPTIMAL APPROACH USING A SINGLE LOOP
*/

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &a)
    {
        int n = a.size();
        vector<int> ans(n, 0);
        int x = 0, y = 1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                ans[y] = a[i];
                y += 2;
            }
            else
            {
                ans[x] = a[i];
                x += 2;
            }
        }
        return ans;
    }
};
