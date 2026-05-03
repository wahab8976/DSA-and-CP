// Used in graphs to check if both nodes belongs to the same component or not in 'Constant Size'
// TC: O($\alpha$(n))

#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++){
            size[i] = 1;
            parent[i] = i; 
        }
    }

    int findUltimateParent(int node) {
        if(node == parent[node]) return node;
        // Path Compression
        return parent[node] = findUltimateParent(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v) return;

        // Attach smaller rank tree to larger rank tree
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } 
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } 
        else {
            // If ranks are same, attach one to other and increase rank
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
    int ulp_u = findUltimateParent(u);
    int ulp_v = findUltimateParent(v);
    if(ulp_u == ulp_v) return;

    if(size[ulp_u] < size[ulp_v]) {
        parent[ulp_u] = ulp_v;       
        size[ulp_v] += size[ulp_u];   // Update size of the NEW parent (V)
    } else {
        parent[ulp_v] = ulp_u;       
        size[ulp_u] += size[ulp_v];   // Update size of the NEW parent (U)
    }
}
};

int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "We belong to same component" << endl;
    } else {
        cout << "We do not belong to same component" << endl;
    }

    ds.unionBySize(3, 7);
    
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "We belong to same component" << endl;
    } else {
        cout << "We do not belong to same component" << endl;
    }
    return 0;
}