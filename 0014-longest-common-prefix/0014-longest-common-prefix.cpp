class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin() , strs.end());
        int n = strs.size();
        int i = 0;
        string ans = "";
        while(i < min(strs[0].size() , strs[n-1].size())){
            if(strs[0][i] != strs[n-1][i])break;
            ans.push_back(strs[0][i++]);
        }
        return ans;
    }
};