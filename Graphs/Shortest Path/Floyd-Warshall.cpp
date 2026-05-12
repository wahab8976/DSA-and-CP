#include"bits/stdc++.h"

void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == j)  dist[i][j] = 0;
                    
                    if(dist[i][via] != 1e8 && dist[via][j] != 1e8){
                        int currDistance = dist[i][j];
                        int newDistance = dist[i][via] + dist[via][j];
                        int bestDistance = min(currDistance,newDistance);
                        dist[i][j] = bestDistance;
                    }
                    
                }
        }
        }
        
    }