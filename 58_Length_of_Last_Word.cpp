//INITIAL APPROACH
class Solution {
public:
    int lengthOfLastWord(string s) {

        int n = s.size();
        string lastWord = "";
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (lastWord.size() == 0)
                    continue;

                return lastWord.size();
            } else {
                lastWord += s[i];
            }
        }

        return lastWord.size();
    }
};

// OPTIMIZED APPROACH

class Solution {
public:
    int lengthOfLastWord(string s) {

        reverse(s.begin(), s.end());

        int i = 0;
        int j = 0;

        while (i < s.size() and s[i] == ' ')
            i++;

        while (i < s.size() and s[i] != ' ') {
            i++;
            j++;
        }

        return j;
    }
};
