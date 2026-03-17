class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,pair<int,bool>>mp;

    // ✅ define lambda with capture
    auto cmp = [&](int a, int b) {
        return mp[a].first < mp[b].first; 
    };

    // ✅ use decltype
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    for(int i = 0 ; i < nums.size() ; i++){
    if(mp.find(nums[i]) == mp.end())
    mp.insert({nums[i] ,{1,false}});
    else{
        mp[nums[i]].first++;
    }
    }

    for(int i = 0 ; i < nums.size() ; i++){
        if(!mp[nums[i]].second){
            pq.push(nums[i]);
            mp[nums[i]].second = true;
        }
    }
    vector<int>ans;
    for(int i = 0 ;  i < k   ; i++)
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
    }
};