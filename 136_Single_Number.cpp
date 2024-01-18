/*
* THE KEY POINT TO REMEMBER IN THIS PROBLEM IS THAT THE -
                                        XOR OF A NUMBER WITH ITSELF IS ZERO AND XOR WITH ZERO OF A NUMBER GIVES THE SAME NUMBER
* THIS PROPERTY CAN BE USED IN THIS PROBLEM
*/

class Solution
{
public:
    int singleNumber(vector<int> &a)
    {

        int ans = 0;

        for (int i = 0; i < a.size(); i++)
        {
            ans = ans ^ a[i];
        }

        return ans;
    }
};
