class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        sort(people.begin(), people.end());
        int n = people.size();
        
        auto itr1 = people.begin();
        auto itr2 = people.end()-1;
        
        int count = 0; 
        
        while(itr1<=itr2){
            if(*itr2 + *itr1 <= limit){
                count++;
                itr2--;
                itr1++;
            }
            else{
                count++;
                itr2--;
            }
            
        }
        
        return count; 
    }
};