/*
* HERE WE USED A UNORDERED MAP TO STORE THE ELEMENTS COMING IN THE PATH 
* RATHER WE CAN USE A VECTOR FR OF SIZE 10 TO STORE FREQ OF EACH NUMBER
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, unordered_map<int, int>& m) {
        if (root == NULL)
            return 0;

        if (root->right == NULL and root->left == NULL) {
            m[root->val]++;
            int odd = 0;
            for (auto it : m) {
                if (it.second % 2 != 0)
                    odd++;
            }
            if (m[root->val] == 1) {
                m.erase(root->val);
            } else {
                m[root->val]--;
            }

            if (odd <= 1)
                return 1;

            return 0;
        }

        m[root->val]++;

        int l = solve(root->left, m);
        int r = solve(root->right, m);

        if (m[root->val] == 1) {
            m.erase(root->val);
        } else {
            m[root->val]--;
        }

        return l + r;
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> m;
        return solve(root, m);
    }
};
