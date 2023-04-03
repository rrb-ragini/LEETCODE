class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        
        int itr1 = 0;
        int itr2 = n-1;
        
        int count = 0; 
        
        while(itr1<=itr2){
            if(people[itr2] + people[itr1] <= limit){
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