#include "bits/stdc++.h"

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;
    
    // Traverse all its neighbors
    for(auto neighbor : adj[node]) {
        // Ignore out-of-bounds nodes
        if(neighbor >= adj.size() || neighbor < 0) continue; 
        
        if(!vis[neighbor]) {
            dfs(neighbor, adj, vis, st);
        }
    }
    
    // Once all outgoing edges are explored, push the node to the stack
    st.push(node);
}

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    stack<int> st;
    // Call DFS for every unvisited node (handles disconnected components)
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, st);
        }
    }
    // Transfer the elements from the stack to our answer vector
    vector<int> topo;
    while(!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}