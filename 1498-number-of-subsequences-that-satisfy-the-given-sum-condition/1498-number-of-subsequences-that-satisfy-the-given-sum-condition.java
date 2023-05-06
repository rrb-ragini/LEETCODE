class Solution {
    long mod = 1000000007;
    long powCal(long a, int n){
        long res = 1;
        while(n > 0){
            if(n%2==1) {
                res = (res * a)%mod;
                n--;
            }
            else {
                a = (a * 1L *a)%mod;
                n/=2;
            }
        }
        return res;
    }
    public int numSubseq(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        Arrays.sort(nums);
        int count = 0;
        while(l <= r){
            if(nums[l] + nums[r] > target) r--;
            else {
                count = (count + (int)powCal(2, r-l))%(int)mod;
                l++;
            }
        }
        return count;
    }
}