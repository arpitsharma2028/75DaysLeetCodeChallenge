class Solution {
public:
    bool pal(string &s, int st, int end) {
    while (st < end) {
        if (s[st] != s[end]) return false;
        st++;
        end--;
    }
    return true;
    }
    void helper(int idx , vector<vector<string>>&ans , vector<string>&temp , string s){
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = idx ; i < s.size() ; i++){
            if(pal(s,idx , i)){
                temp.push_back(s.substr(idx , i-idx+1 ));
                helper(i+1 ,ans , temp , s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans ; vector<string>temp;
        helper(0,ans,temp,s);
        return ans;
    }
};