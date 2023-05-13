class Solution {
    vector<int>v;
    int mod = 1000000007;
//     int fun(int i, int zero, int one){
//         if(i < 0) return 0;
//         if(i == 0) return 1;
        
//         if(v[i]!=0) return v[i]%mod;
        
//         return v[i] = (fun(i-zero, zero, one)%mod + fun(i-one, zero, one)%mod)%mod;
        
//     }
    
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        v = vector<int>(high + 1, 0);
        int count = 0;
        v[0] = 1;
        for(int i = 0; i <= high; i++){
            if(i - zero >= 0) v[i] = (v[i] + v[i-zero])%mod;
            if(i - one >= 0) v[i] = (v[i] + v[i-one])%mod;
        }
        for(int i = low; i <= high; ++i) count = (count + v[i])%mod;
        return count;
    }
};