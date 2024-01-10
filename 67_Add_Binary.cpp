class Solution
{
public:
    string addBinary(string a, string b)
    {
        int x = 0, y = 0, carry = 0;
        string ans = "";
        while (a.size() != 0 or b.size() != 0)
        {
            if (a.size() != 0)
            {
                x = a[a.size() - 1] - '0';
                a.pop_back();
            }
            if (b.size() != 0)
            {
                y = b[b.size() - 1] - '0';
                b.pop_back();
            }

            if (x + y + carry == 3)
            {
                ans += '1';
                carry = 1;
            }
            else if (x + y + carry == 2)
            {
                ans += '0';
                carry = 1;
            }
            else if (x + y + carry == 1)
            {
                ans += '1';
                carry = 0;
            }
            else
            {
                ans += '0';
                carry = 0;
            }
            x = 0; y = 0;
        }
        if (carry == 1)
            ans += '1';

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
