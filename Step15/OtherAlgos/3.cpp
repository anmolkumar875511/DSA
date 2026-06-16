#include<iostream>
#include<vector>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution {
    // Phase 1 DFS: Order vertices by finish time
    void fillOrder(int u, const vector<unordered_set<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                fillOrder(v, adj, visited, st);
            }
        }
        st.push(u);
    }

    // Phase 3 DFS: Traverse the transposed graph to collect SCC members
    void dfsTranspose(int u, const vector<unordered_set<int>>& adjT, vector<bool>& visited, vector<int>& current_scc) {
        visited[u] = true;
        current_scc.push_back(u);
        for (int v : adjT[u]) {
            if (!visited[v]) {
                dfsTranspose(v, adjT, visited, current_scc);
            }
        }
    }

public:
    vector<string> maxNumOfSubstrings(string s)  {
        int n = s.length();
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        vector<bool> present(26, false);

        // Step 1: Track boundaries of each character
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (first[idx] == -1) first[idx] = i;
            last[idx] = i;
            present[idx] = true;
        }

        // Step 2: Build the original adjacency list
        vector<unordered_set<int>> adj(26);
        for (int i = 0; i < 26; ++i) {
            if (!present[i]) continue;
            for (int j = first[i]; j <= last[i]; ++j) {
                int neighbor = s[j] - 'a';
                if (i != neighbor) {
                    adj[i].insert(neighbor);
                }
            }
        }

        // Step 3: Kosaraju's Phase 1 - Standard DFS to fill the finish stack
        stack<int> st;
        vector<bool> visited(26, false);
        for (int i = 0; i < 26; ++i) {
            if (present[i] && !visited[i]) {
                fillOrder(i, adj, visited, st);
            }
        }

        // Step 4: Kosaraju's Phase 2 - Transpose the graph
        vector<unordered_set<int>> adjT(26);
        for (int u = 0; u < 26; ++u) {
            if (!present[u]) continue;
            for (int v : adj[u]) {
                adjT[v].insert(u);
            }
        }

        // Step 5: Kosaraju's Phase 3 - DFS on transposed graph to extract SCCs
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs;
        while (!st.empty()) {
            int u = st.top();
            st.pop();
            if (!visited[u]) {
                vector<int> current_scc;
                dfsTranspose(u, adjT, visited, current_scc);
                sccs.push_back(current_scc);
            }
        }

        // Step 6: Map each character to its SCC index
        vector<int> scc_id(26, -1);
        for (int i = 0; i < sccs.size(); ++i) {
            for (int node : sccs[i]) {
                scc_id[node] = i;
            }
        }

        // Step 7: Find out-degrees of the compressed components
        vector<int> out_degree(sccs.size(), 0);
        for (int u = 0; u < 26; ++u) {
            if (!present[u]) continue;
            for (int v : adj[u]) {
                if (scc_id[u] != scc_id[v]) {
                    out_degree[scc_id[u]]++;
                }
            }
        }

        // Step 8: Keep only Sink SCCs (out_degree == 0) and gather their physical ranges
        vector<pair<int, int>> valid_intervals;
        for (int i = 0; i < sccs.size(); ++i) {
            if (out_degree[i] == 0) {
                int start = n, end = -1;
                for (int node : sccs[i]) {
                    start = min(start, first[node]);
                    end = max(end, last[node]);
                }
                valid_intervals.push_back({end, start}); // Stored as {end, start} for easy greedy sorting
            }
        }

        // Step 9: Interval Scheduling (Greedy Selection)
        sort(valid_intervals.begin(), valid_intervals.end());
        vector<string> result;
        int last_right_boundary = -1;

        for (const auto& interval : valid_intervals) {
            int end = interval.first;
            int start = interval.second;
            if (start > last_right_boundary) {
                result.push_back(s.substr(start, end - start + 1));
                last_right_boundary = end;
            }
        }

        return result;
    }
};


int main() {
    Solution sol;
    string s = "abacaba";
    vector<string> result = sol.maxNumOfSubstrings(s);
    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}