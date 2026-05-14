#include<iostream>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // SERIALIZE
    void rec_serializer(TreeNode* node, string& s) {
        if (!node) {
            s += "n_";
            return;
        }
        s += to_string(node->val) + "_";
        rec_serializer(node->left, s);
        rec_serializer(node->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        rec_serializer(root, s);
        return s;
    }

    // DESERIALIZE
    TreeNode* rec_deserializer(string& s, int& i) {
        if (i >= s.size()) return NULL;
        if (s[i] == 'n') {
            i += 2;
            return NULL;
        }

        int val = 0;
        bool isNeg = false;
        if(s[i] == '-') {
            isNeg = true;
            i++;
        }
        while (i < s.size() && s[i] != '_') {
            val = val * 10 + (s[i] - '0');
            i++;
        }
        i++;
        if(isNeg) val *= -1;

        TreeNode* node = new TreeNode(val);
        node->left = rec_deserializer(s, i);
        node->right = rec_deserializer(s, i);

        return node;
    }

    TreeNode* deserialize(string data) {
        int i = 0;
        return rec_deserializer(data, i);
    }
};


int main() {
    Codec c;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    string s = c.serialize(root);
    TreeNode* root2 = c.deserialize(s);
    return 0;
}