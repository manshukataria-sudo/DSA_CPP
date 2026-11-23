#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
   public:
    int find(int a, vector<int>& parent) {
        return parent[a] = (parent[a] == a) ? a : find(parent[a], parent);
    }
    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        a = find(a, parent);
        b = find(b, parent);

        if (a == b) {
            return;
        }

        if (rank[a] < rank[b]) {
            parent[a] = b;
            rank[b]++;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }
    int countConnected(int v, vector<vector<int>>& edges) {
        // code here
        vector<int> parent(v);
        vector<int> rank(v, 0);

        for (int i = 0; i < v; i++) {
            parent[i] = i;
        }

        int e = edges.size();

        for (int i = 0; i < e; i++) {
            Union(edges[i][0], edges[i][1], parent, rank);
        }

        unordered_set<int> parents;
        for (int i = 0; i < v; i++) {
            find(i, parent);
            parents.insert(parent[i]);
        }

        return parents.size();
    }
};
