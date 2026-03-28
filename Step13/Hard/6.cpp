#include<iostream>
#include<queue>
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
    TreeNode* startNode = nullptr;

    void buildParentMap(TreeNode* node, TreeNode* parent, int start) {
        if (!node) return;
        
        if (node->val == start) {
            startNode = node;
        }
        
        parentMap[node] = parent;
        buildParentMap(node->left, node, start);
        buildParentMap(node->right, node, start);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        buildParentMap(root, nullptr, start);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> infected;
        
        q.push(startNode);
        infected.insert(startNode);
        
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                
                if (curr->left && !infected.count(curr->left)) {
                    q.push(curr->left);
                    infected.insert(curr->left);
                }
                if (curr->right && !infected.count(curr->right)) {
                    q.push(curr->right);
                    infected.insert(curr->right);
                }
                if (parentMap[curr] && !infected.count(parentMap[curr])) {
                    q.push(parentMap[curr]);
                    infected.insert(parentMap[curr]);
                }
            }

            if (!q.empty()) {
                time++;
            }
        }
        
        return time;
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

    cout << "Amount of time to infect binary tree is: " << sol.amountOfTime(root, 2) << endl; // Output: 2

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}