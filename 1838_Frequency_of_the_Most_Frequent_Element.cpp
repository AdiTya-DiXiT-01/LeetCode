/*
* REDO THE PROBLEM 
* TWO APPROACHES TO SOLVE THE PROBLEM - 1.SLIDING WINDOW 
                                        2. BINARY SEARCH + PREFIX SUM (HIGH TC)
*/

class Solution
{
public:
    int maxFrequency(vector<int> &a, int k)
    {
        sort(a.begin(), a.end());

        int i = 0, j = 0, ans = 1;
        int currLen = 0, curr = 0;
        long long sum = 0;
        while (j < a.size())
        {
            curr = a[j];
            currLen++;
            sum += curr;

            while (curr * 1LL * currLen - sum > k)
            {
                sum -= a[i];
                currLen--;
                i++;
            }
            ans = max(ans, currLen);
            j++;
        }

        return ans;
    }
};
