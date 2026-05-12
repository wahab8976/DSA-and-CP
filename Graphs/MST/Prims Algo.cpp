#include"bits/stdc++.h"


int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue< pair<int,int>, 
                                vector<pair<int,int>>,
                                                greater<pair<int,int>>> pq;
                       
        // build adj List
        vector<vector<pair<int,int>>> adjList(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        
        // {cost,node}
        pq.push({0,0});
        vector<int> vis(V,0);
        
        int sum = 0;
        while(!pq.empty())
        {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(vis[node])   continue;
            
            vis[node] = 1;
            sum += cost;    // Cost of edge
            
            
            for(auto it : adjList[node]){
                
                int neighbor = it.first;
                int neighborWt = it.second;
                
                if(!vis[neighbor]){
                    pq.push({neighborWt,neighbor});
                }
            }
            
        }
        
        return sum;
    }