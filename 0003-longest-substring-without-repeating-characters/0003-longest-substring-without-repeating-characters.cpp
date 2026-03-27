class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char>q;
        unordered_map<char , int>freq;
        int ans = 0;
        for(char ch : s){
            freq[ch]++;
            while(!q.empty() && freq[ch]>1){
                freq[q.front()]--;
                q.pop();
            }
            q.push(ch);
            if(q.size() > ans)
                ans = q.size();
        }
        return ans;
    }
    // int lengthOfLongestSubstring(string s) {
    //     unordered_set<char>st;
    //     int l = 0  ,r = 0 , n = s.size(), ans = 0;
    //     while(r<n){
    //         while(l<n && st.count(s[r])){
    //             st.erase(s[l]);
    //             l++;
    //         }
    //         st.insert(s[r]);
    //         ans = max(ans , r-l+1);
    //         r++;
    //     }
    //     return ans;
    // }
};