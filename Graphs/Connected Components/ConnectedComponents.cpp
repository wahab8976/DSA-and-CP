#include"bits/stdc++.h"

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
        return parent[node] = findUltimateParent(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;       
            size[ulp_v] += size[ulp_u];   
        } else {
            parent[ulp_v] = ulp_u;       
            size[ulp_u] += size[ulp_v];   
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();
        
        // Grid formula: (row * total_columns) + col
        DisjointSet ds(n * m);
        
        int landCells = 0;
        
        // Count total initial land pieces
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == '1') {
                    landCells++;
                }
            }
        }
        
        if (landCells == 0) return 0;

        int dr[] = {1, 0};
        int dc[] = {0, 1};

        int mergeCount = 0;

        // Traverse and Union
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c] == '1') {
                    int currentNode = r * m + c;

                    for (int i = 0; i < 2; i++) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        // Check boundaries and if the neighbor is also land
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1') {
                            int neighborNode = nr * m + nc;

                            // If they belong to different components, merge them
                            if (ds.findUltimateParent(currentNode) != ds.findUltimateParent(neighborNode)) {
                                ds.unionBySize(currentNode, neighborNode);
                                mergeCount++; 
                            }
                        }
                    }
                }
            }
        }

        // Final Islands = Total Initial Lands - Successful Merges
        return landCells - mergeCount;
    }
};