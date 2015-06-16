
//Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

#include <stack>

struct TreeNode* invertTree(struct TreeNode* root) {
	std::stack<struct TreeNode*> stk;
	stk.push(root);
	struct TreeNode* tmp;
	while (!stk.empty()) {
		tmp = stk.top();
		stk.pop();
		if (tmp)
		{
			if (tmp->left) stk.push(tmp->left);
			if (tmp->right) stk.push(tmp->right);
			std::swap(tmp->left, tmp->right);
		}
	}
	return root;
}