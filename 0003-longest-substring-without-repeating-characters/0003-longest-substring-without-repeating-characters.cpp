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
};