class Solution {
    vector<int>parent, rank;
    
    int findUparent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUparent(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = findUparent(u); 
        int ulp_v = findUparent(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        rank.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        for(int i = 0; i < edges.size(); i++)
            unionByRank(edges[i][0], edges[i][1]);

        return findUparent(source) == findUparent(destination);
    }
};