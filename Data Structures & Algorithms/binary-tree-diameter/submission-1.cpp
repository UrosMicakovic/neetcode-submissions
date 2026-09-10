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
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;

        // Inline recursive lambda to calculate height and update max_diameter
        auto height = [&](auto& self, TreeNode* node) -> int {
            if (node == nullptr) return 0;

            int left_h = self(self, node->left);
            int right_h = self(self, node->right);

            max_diameter = std::max(max_diameter, left_h + right_h);

            return 1 + std::max(left_h, right_h);
        };

        height(height, root);
        return max_diameter;
    }
};
