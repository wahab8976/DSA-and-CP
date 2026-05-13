#include "bits/stdc++.h"

int countPaths(int V, vector<vector<int>>& edges) {
    
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        
        vector<int> dist(V,1e9), ways(V,0);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        
        // Dijsktra's Algo
        while(!pq.empty())
        {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Logic main
            for(auto it : adj[node]){
                
                int neigh = it.first;
                int wt = it.second;
                 
                // Discovered  for first time
                if(currDist  + wt < dist[neigh]){
                    
                    dist[neigh] = currDist + wt;
                    pq.push({dist[neigh], neigh});
                    ways[neigh] = ways[node];
                    
                }else if(currDist  + wt == dist[neigh]){
                    // Already Visited with min Distance
                    ways[neigh] = ways[node] + ways[neigh];
                }
            }
            
        }
        return ways[V - 1];
    }