#include "bits/stdc++.h"

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

int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<pair<int, pair<int,int>>> edgeList;
        
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            edgeList.push_back({wt, {u, v}});
        }
        
        int sum = 0;
        DisjointSet ds(V);
        sort(edgeList.begin(), edgeList.end());
        
        
        
        for(auto it : edgeList){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            cout << "U: "<<u <<"V: "<<v<<" WT: "<<wt<<endl;
            
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                sum += wt;
                ds.unionByRank(u,v);
            }
        }
        
        return sum;
    }