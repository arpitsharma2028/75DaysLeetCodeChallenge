class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
        3 phase solution
        1. push till not overlapping
        2. now store merging intervals
        3. now push remainig
        */

        int st = newInterval[0];
        int end = newInterval[1];
        int n = intervals.size();
        vector<vector<int>> ans;
        // push till not overlapp
        int i=0;
        while(i<n && intervals[i][1] < st )ans.push_back(intervals[i++]);

        while(i<n && intervals[i][0] <=  end){
            st = min(intervals[i][0] , st);
            end = max(intervals[i][1] , end);
            i++;
        }
        ans.push_back({st,end});
        for(i ; i < n ; i++)ans.push_back(intervals[i]);
        return ans;
    }  
};