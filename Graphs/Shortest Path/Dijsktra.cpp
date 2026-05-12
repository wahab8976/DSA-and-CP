#include"bits/stdc++.h"
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Build up adj List
        int E = edges.size();
        
        vector<vector<pair<int,int>>> adjList(V);
        
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        
        // Min - Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0,src});
        
        vector<int> distance(V,1e9);
        distance[src] = 0;
        
        while(!pq.empty())
        {
            int currDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            
            // Explore all neighbors
            for(auto it : adjList[node]){
                int neighbor = it.first;
                int wt = it.second;
                
                // Condition
                if(currDist + wt < distance[neighbor]){
                    distance[neighbor] = currDist + wt;
                    pq.push({currDist + wt, neighbor});
                }
                
            }
        }
        
        return distance;
    }