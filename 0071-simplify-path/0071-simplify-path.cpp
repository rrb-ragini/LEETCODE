class Solution {
public:
    string simplifyPath(string path) {
        vector<string>v;
        string temp;
        stringstream ss(path);
        
        while(getline(ss, temp, '/')){
            if(!v.empty() and temp == "..") v.pop_back();
            else if(temp !=".." and temp !="" and temp!=".")
                v.push_back(temp);
        }
        string res="";
        for(string s:v){
            res+="/" + s;
        }
        return res.empty()?"/":res;
    }
};