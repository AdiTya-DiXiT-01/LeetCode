/*
FIRST INTUTIVE APPROACH USING VECTOR
*/

class RandomizedSet
{
public:
    vector<int> r;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        bool flag = true;
        for (int i = 0; i < r.size(); i++)
        {
            if (r[i] == val)
            {
                flag = false;
            }
        }
        if (flag)
            r.push_back(val);

        return flag;
    }

    bool remove(int val)
    {
        bool flag = false;
        auto itr = r.begin();
        for (int i = 0; i < r.size(); i++)
        {
            if (r[i] == val)
            {
                r.erase(itr + i);
                flag = true;
                break;
            }
        }

        return flag;
    }

    int getRandom()
    {
        random_shuffle(r.begin(), r.end());
        return r[0];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/*
* DISCUSSION SOLUTION USING UNORDERED MAP AND VECTOR
* OPTIMAL CODE
*/

class RandomizedSet
{
public:
    unordered_map<int, int> m;
    vector<int> r;
    RandomizedSet()
    {
        ios_base::sync_with_stdio(false);
    }

    bool insert(int val)
    {
        if (m.find(val) != m.end())
        {
            return false;
        }
        r.push_back(val);
        m[val] = r.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (m.find(val) == m.end())
            return false;

        int idx = m[val];
        int last = r.back();
        m[last] = idx;
        swap(r[r.size() - 1], r[idx]);
        r.pop_back();
        m.erase(val);
        return true;
    }

    int getRandom()
    {
        return r[rand() % r.size()];
    }
};
