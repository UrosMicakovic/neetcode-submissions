/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        auto check = [&](auto& self, TreeNode* node) -> std::pair<bool, int> {
            if (node == nullptr) {
                return {true, 0};
            }

            auto [left_balanced, left_h] = self(self, node->left);
            if (!left_balanced) return {false, 0};

            auto [right_balanced, right_h] = self(self, node->right);
            if (!right_balanced) return {false, 0};

            if (std::abs(left_h - right_h) > 1) {
                return {false, 0};
            }

            return {true, 1 + std::max(left_h, right_h)};
        };

        return check(check, root).first;
    }
};
