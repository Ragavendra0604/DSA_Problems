class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int count = 1;
        int LastIndex = intervals[0][1];
        int n = intervals.size();

        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] >= LastIndex){
                count++;
                LastIndex = intervals[i][1];
            }
        }

        return n - count;
    }
};