class Solution {
    vector<int>v;
//     int dp(int n){
//         if(n == 0) return 0;
//         if(n == 1) return 1;
        
//         if(v[n]!=-1)  return v[n];
//         return v[n] = dp(n-1) + dp(n-2);
        
//     }
    
public:
    int fib(int n) {
        v = vector<int>(n+2, -1);
        v[0] = 0;
        v[1] = 1;
        for(int i = 2; i <=n; i++){
            v[i] = v[i-1] + v[i-2];
        }
        
        // return dp(n);
        return v[n];
    }
};