#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 伪层序遍历构建二叉树
TreeNode* buildTree(vector<int>& nums) {
    if (nums.empty()) {
        return nullptr;
    }

    int n = nums.size();
    TreeNode* root = new TreeNode(nums[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        TreeNode* current = q.front();
        q.pop();

        if (nums[i] != -1) {
            current->left = new TreeNode(nums[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && nums[i] != -1) {
            current->right = new TreeNode(nums[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// 前序遍历
void preorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        cout << root->val << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 中序遍历
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

// 后序遍历
void postorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->val << " ";
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
        }

        TreeNode* root = buildTree(nums);

        preorderTraversal(root);
        cout << "\n";

        inorderTraversal(root);
        cout << "\n";

        postorderTraversal(root);
        cout << "\n";

        cout << endl;
    }

    return 0;
}
