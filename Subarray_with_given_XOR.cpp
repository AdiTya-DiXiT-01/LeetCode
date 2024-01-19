/*
* INTERVIEW-BIT PROBLEM
* SAME CONCEPT AS WE USED IN THE PROBLEM NUMBER OF SUBARRAYS WITH SUM K
* HERE WE USE A PREFIX XOR ARRAY AND A MAP TO STORE THE LAST PREFIX XOR
*/

int Solution::solve(vector<int> &A, int B)
{

    int n = A.size();
    unordered_map<int, int> m;
    m[0] = 1;
    int ans = 0;
    int prefixXor = 0;
    for (int i = 0; i < n; i++)
    {
        prefixXor ^= A[i];
        if (m.find(prefixXor ^ B) != m.end())
            ans += m[prefixXor ^ B];

        m[prefixXor]++;
    }

    return ans;
}
