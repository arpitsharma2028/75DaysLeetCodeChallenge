class Solution {
public:
    int calDist(int i , int  j , int k){
        return (abs(i - j) + abs(j - k) + abs(k - i));
    }
    int minimumDistance(vector<int>& nums) {
        unordered_map<int , vector<int>>mp;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto [value , indexes] : mp){
            if(indexes.size() >= 3){
                for(int k = 2 ; k < indexes.size(); k++){
                    ans = min(ans , calDist(indexes[k-2],indexes[k-1],indexes[k]));
                }
            }

        }
        return (ans==INT_MAX ? -1 : ans);
    }
};