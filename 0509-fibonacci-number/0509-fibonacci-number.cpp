class Solution {
    vector<int>v;
    int dp(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        if(v[n]!=-1)  return v[n];
        return v[n] = dp(n-1) + dp(n-2);
        
    }
    
public:
    int fib(int n) {
        v = vector<int>(n+1, -1);
        return dp(n);
    }
};