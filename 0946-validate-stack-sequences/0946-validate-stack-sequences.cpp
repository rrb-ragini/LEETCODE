class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int index = 0;
        
        for(auto p:pushed){
            st.push(p);
            while(!st.empty() and st.top()==popped[index]){
                index++;
                st.pop();
            }
        }
        
        if(st.empty()) return true;
        return false;
    }
};