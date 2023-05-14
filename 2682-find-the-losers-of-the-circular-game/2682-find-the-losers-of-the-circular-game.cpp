class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int, int>visited;
        int i = 1;
        int turn = 1;
        while(visited[i]==0){
            visited[i]++;
            i = (i + (turn*k) )%(n);
            turn++;
            if(i == 0) i = n;
        }
        vector<int>res;
        for(int i = 1;i<=n; i++){
            if(visited[i]==0)
                res.push_back(i);
        }
        return res;
        
    }
};