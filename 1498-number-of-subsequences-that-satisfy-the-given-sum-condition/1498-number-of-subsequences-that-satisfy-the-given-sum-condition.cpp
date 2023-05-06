class Solution {
    long long mod = 1e9+7;
    long long powCal(long long a, long long n){
        long long res = 1;
        while(n>0){
            if(n%2 == 1) {res = (res * a)%mod ; n--;}
            else {a = (a*a)%mod; n = n/2;}
        }
        return res%mod;
    }
    public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        long long count = 0;
        int l = 0, r = n-1;
        while(l <= r){
            if(nums[l] + nums[r] > target) r--;
            else {
                count = (count + powCal(2, r - l))%mod; 
                l++;
            }
        }
        
        return count%mod; 
    }
};