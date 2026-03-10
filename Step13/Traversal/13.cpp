#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
	public:
		vector<vector<int> > treeTraversal(TreeNode* root){
			stack<pair<TreeNode*, int>> st;
            st.push({root, 1});
            vector<int> pre_order, in_order, post_order;
            while(!st.empty()) {
                auto tp = st.top();
                TreeNode* curr = tp.first;
                int level = tp.second;
                st.pop();
                if(level == 1) {
                    pre_order.push_back(curr->val);
                    level++;
                    st.push({curr, level});
                    if(curr->left) st.push({curr->left, 1});
                }
                else if(level == 2) {
                    in_order.push_back(curr->val);
                    level++;
                    st.push({curr, level});
                    if(curr->right) st.push({curr->right, 1});
                }
                else {
                    post_order.push_back(curr->val);
                }
            }
            return {in_order, pre_order, post_order};
		}
};



int main() {
    /* 
       Constructing a sample tree:
             1
            / \
           2   3
          / \
         4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> results = sol.treeTraversal(root);

    string names[] = {"Inorder", "Preorder", "Postorder"};
    for (int i = 0; i < 3; i++) {
        cout << names[i] << ": ";
        for (int val : results[i]) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}