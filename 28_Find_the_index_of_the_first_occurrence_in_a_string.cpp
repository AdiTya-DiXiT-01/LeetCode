// Basic Approach 1
// High TC

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = needle.size();

        if(haystack.size() < n) return -1;

        for(int i = 0; i <= haystack.size() - n; i++)
        {
            int curr = i;
            int j = 0;
            while((haystack[curr] == needle[j]) and (curr < haystack.size())){
                curr++; j++;
            }
            if(j == n)
                return i;
        }

        return -1;
    }
};

//Optimal Approach
//Beats 100%
//String Matching Used

class Solution {
public:
    int strStr(string haystack, string needle) {

        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i < n - m + 1; i++) {
            if (haystack[i] == needle[0]) {
                int curr = i;
                int j = 0;

                while (j < m) {
                    if (haystack[curr] == needle[j]) {
                        curr++;
                        j++;
                    } else {
                        break;
                    }
                }

                if (j == m)
                    return i;
            }
        }

        return -1;
    }
};












