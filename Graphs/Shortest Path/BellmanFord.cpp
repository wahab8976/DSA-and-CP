#include"bits/stdc++.h"

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> distance (V,1e8);
        distance[src] = 0;
        
        for(int i = 0; i < V - 1; i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                // Relaxation
                if(distance[u] != 1e8 && distance[u] + wt < distance[v]){
                    distance[v] = distance[u] + wt;
                }
            }
        }
        
        // Required is V - 1, but if it takes V itterations, it means
        // there exist a negative weight cycle
        
        for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                // Relaxation again
                if(distance[u] != 1e8 && distance[u] + wt < distance[v]){
                    return {-1};
                }
            }
        
        return distance;
    }