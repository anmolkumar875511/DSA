#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    unordered_map<TreeNode*, TreeNode*> parentMap;
    unordered_set<TreeNode*> visited;
    vector<int> result;

    void buildParentMap(TreeNode* node, TreeNode* parent) {
        if (!node) return;
        parentMap[node] = parent;
        buildParentMap(node->left, node);
        buildParentMap(node->right, node);
    }

    void findDistanceK(TreeNode* node, int k) {
        if (!node || visited.count(node)) return;

        visited.insert(node);

        if (k == 0) {
            result.push_back(node->val);
            return;
        }

        findDistanceK(node->left, k - 1);
        findDistanceK(node->right, k - 1);
        findDistanceK(parentMap[node], k - 1);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        buildParentMap(root, nullptr);
        
        findDistanceK(target, k);
        
        return result;
    }
};

int main(){
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

    vector<int> result = sol.distanceK(root, root->left, 1);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}