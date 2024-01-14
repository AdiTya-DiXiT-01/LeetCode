/*
FIRST INTUTIVE APPROACH 
```````````````````````
GIVES RUNTIME ERROR
*/

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        map<char, int> m1;
        map<char, int> m2;

        if (word1.size() != word2.size())
            return false;

        for (int i = 0; i < word1.size(); i++)
        {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }

        sort(word1.begin(), word1.end());
        sort(word2.begin(), word2.end());

        if (word1 == word2)
        {
            return true;
        }
        else
        {
            for (auto it : m2)
            {
                auto itr = m1.find(it.first);

                if (itr == m1.end())
                {
                    return false;
                }
                else
                {
                    if (itr->second == it.second)
                    {
                        m1.erase(it.first);
                    }
                    else
                    {
                        for (auto i = m1.begin(); i != m1.end(); i++)
                        {
                            if (i->second == it.second)
                            {
                                i->second = itr->second;
                                m1.erase(it.first);
                            }
                        }
                    }
                }
            }
        }
        if (m1.empty())
        {
            return true;
        }

        return false;
    }
};

