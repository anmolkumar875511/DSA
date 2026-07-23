#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class SGTree {
private:
    vector<int> tree;
public:
    SGTree(int n) {
        tree.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, vector<int>& nums) {
        if(low == high) {
            tree[idx] = nums[low];
            return;
        }
        int mid = low + ((high - low) >> 1);
        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);
        tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        if(l > high || r < low) {
            return INT_MAX;
        }
        if(low >= l && high <= r) {
            return tree[idx];
        }
        int mid = low + ((high - low) >> 1);
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    void update(int idx, int low, int high, int i, int val) {
        if(low == high) {
            tree[idx] = val;
            return;
        }
        int mid = low + ((high - low) >> 1);
        if(mid >= i) {
            update(2 * idx + 1, low , mid, i, val);
        }
        else {
            update(2 * idx + 2, mid + 1, high, i, val);
        }
        tree[idx] = min(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 0, 7, 4};
    vector<vector<int>> queries = {{0, 0, 3}, {1, 3, 2}, {0, 0, 3}};
    SGTree sg(nums.size());
    sg.build(0, 0, nums.size() - 1, nums);
    for(auto query : queries) {
        if(query[0] == 1) {
            sg.update(0, 0, nums.size() - 1, query[1], query[2]);
            nums[query[1]] = query[2];
        }
        else {
            cout << sg.query(0, 0, nums.size() - 1, query[1], query[2]) << endl;
        }
    }
    return 0;
}
