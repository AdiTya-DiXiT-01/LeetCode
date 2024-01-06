class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        string temp = "";
        int smallest = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            if(strs[i].size() < smallest)
            {
                smallest = strs[i].size();
                temp = strs[i];
            }
        }
        smallest = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int j = 0;
            while(j < temp.size())
            {
                if(strs[i][j] == temp[j])
                {
                    j++;
                } else {
                    smallest = min(smallest, j);
                    break;
                }
            }
        }
        //cout<<smallest<<endl;
        string ans = temp.substr(0, smallest);

        return ans;
    }
};
