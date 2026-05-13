#include "bits/stdc++.h"

    vector<int> topoSort(int V, vector<vector<int>> &adj) {
        vector<int> inDegree(V, 0);
        
        // Calculate Indegree
        for(int i = 0; i < V; i++) {
            for(auto neighbor : adj[i]) {
                if(neighbor >= V || neighbor < 0) continue; 
                inDegree[neighbor]++;
            }
        }
        
        // Push all nodes with 0 indegree into the queue
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        
        vector<int> topo; // This replaces your 'count' variable
        
        // BFS
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto neighbor : adj[node]) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        // Cycle Check 
        // If the size of our result array isn't equal to V, there is a cycle.
        // A cyclic graph cannot have a valid topological sort, so return an empty array.
        if (topo.size() != V) {
            return {}; 
        }
        return topo;
    }