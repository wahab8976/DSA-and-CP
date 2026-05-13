#include "bits/stdc++.h"

// Helps us to find strongly connected components in a graph
void dfs(vector<int>& vis,int node,stack<int>& st,vector<vector<int>>& adj){
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it])   dfs(vis,it,st,adj);
        }
        
        st.push(node);
    } 
    
    void dfs2(vector<int>& vis,int node,vector<vector<int>>& adjT){
        vis[node] = 1;
        
        for(auto it : adjT[node]){
            if(!vis[it])   dfs2(vis,it,adjT);
        }
        
    } 
    
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> vis(V,0);
        stack<int> st;
        vector<vector<int>> adj(V);
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        // Sort according to finishing time 
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(vis,i,st,adj);
            }
        }
        
        vector<vector<int>> adjT(V);
        // Reverse the graph
        for(int i = 0; i < V; i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        // Count Strongly Connected Components
        int scc = 0;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs2(vis, node ,adjT);
            }
        }
        return scc;
    }