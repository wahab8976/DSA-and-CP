#include"bits/stdc++.h"

/*
    Used to find Articulation point in a graph
    Articulation Point:-> If we remove the edge from that particular point, the graph will split into different components
*/

class Solution {
    // Tarjan's Algorithm
public:
    int timer;

    Solution(){
        timer = 1;
    }

    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj,int parent,vector<int>& insertionTime,vector<int>& lowestTime,vector<vector<int>>& bridges)
    {
        vis[node] = 1;
        lowestTime[node] = insertionTime[node] = timer;
        timer++;


        for(auto it : adj[node]) 
        {
            if(it == parent)    continue;

            if(!vis[it]){
                dfs(it,vis,adj,node,insertionTime,lowestTime,bridges);
                lowestTime[node] = min(lowestTime[node], lowestTime[it]);

                if(lowestTime[it] > insertionTime[node]){
                    bridges.push_back({it,node});
                }
            }else{
                lowestTime[node] = min(lowestTime[node],lowestTime[it]);
            }
        }
    }


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> insertionTime(n),lowestTime(n);
        vector<vector<int>> bridges;
        vector<int> vis (n,0);
        dfs(0,vis,adj,-1,insertionTime,lowestTime,bridges);

        return bridges;
    }
};