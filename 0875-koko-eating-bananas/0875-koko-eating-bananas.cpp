class Solution {
public:
    int findMaxEle(vector<int> &arr){
        int n = arr.size();

        int max = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i] > max){
                max = arr[i];
            }
        }
        return max;
    }
    
    long long calculateTotalHours(vector<int> &arr, long long hours){
        int n = arr.size();

        long long totalHours = 0;
        for(int i=0;i<n;i++){
            totalHours += (arr[i] + hours - 1) / hours;
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMaxEle(piles);

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long totalHours = calculateTotalHours(piles, mid);
            if(totalHours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};