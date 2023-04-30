class DSU{
    private:
        const int N = 1e5+10;
        vector<int> parent, size, rank;
    public:
        DSU(){
            parent.resize(N);
            iota(begin(parent),end(parent),0);
            size.resize(N,1);
            rank.resize(N,0);
        }
        DSU(int n){
            parent.resize(n+1);
            iota(begin(parent),end(parent),0);
            size.resize(n+1,1);
            rank.resize(n+1,0);
        }
        int find(int v){
            if(parent[v] == v) return v;
            //path compression
            return parent[v] = find(parent[v]);
        }
        // custom merging
        void merge(){
         
        }
        void unionS(int a,int b){
            a = find(a);
            b = find(b);
            if(a!=b){
                //union by size
                if(size[a] < size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
            }
        }
        void unionR(int x, int y) {
            x = find(x), y = find(y);
            if(x == y) return;
            //union by rank
            else if(rank[x] < rank[y]) parent[x] = y;
            else if (rank[x] > rank[y]) parent[y] = x;
            else parent[y] = x,rank[x]++;
      }
};

class Solution {
public:
    int maxNumEdgesToRemove(int v, vector<vector<int>>& edges) {
        int n = size(edges), extraedges = 0;
        partition(begin(edges),end(edges),[](auto a){return a[0]%3==0;});
        DSU alice(v),bob(v);
        for(auto&e: edges){
            int type = e[0], u = e[1], v = e[2];
            if(type == 3){
                if(alice.find(u) == alice.find(v)) extraedges++;
                else{
                    alice.unionS(u,v);
                    bob.unionS(u,v);
                }
            }else if(type == 1){
                if(alice.find(u) == alice.find(v)) extraedges++;
                else alice.unionS(u,v);
            }else{
                if(bob.find(u) == bob.find(v)) extraedges++;
                else bob.unionS(u,v);
            }
        }
        int cc = 0;
        for(int i=1; i<=v; ++i) if(alice.find(i) == i) cc++;
        if(cc != 1) return -1;
        cc = 0;
        for(int i=1; i<=v; ++i) if(bob.find(i) == i) cc++;
        if(cc != 1) return -1;
        return extraedges;
    }
};