class Solution {
        vector<int>v;
        int binarySearch(vector<int>potions, long long minPotion, int low, int high){
            while(low < high){
                int mid = low + (high-low)/2;

                if(potions[mid]>=minPotion){
                    high = mid; 
                }
                
                else if(potions[mid]<minPotion)
                    low = mid+1;
            }
            
            if(potions[low]>=minPotion) return low;
            else if(potions[high] >= minPotion) return high; 
            return 0;
        }

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        // v = vector<int>(m, 0);

        int n = potions.size();
        sort(potions.begin(), potions.end());
        long long minPotion = 0; 
        for(int i = 0; i < spells.size(); i++){
            minPotion = ceil((1.0 * success)/spells[i]);

            if(minPotion > potions[n-1]) {
                v.push_back(0);   
                continue; 
            }
            else if(minPotion == potions[0]) {
                v.push_back(n); 
                continue;
            }
            
            //binary search in potions array 
            // v.push_back(n-binarySearch(potions, minPotion, 0, n-1));
            v.push_back(potions.end() - lower_bound(potions.begin(), potions.end(), minPotion));    
        }
        
        return v; 
        
    }
};