class Solution {
public:
    int count = 0;
    void merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid+1;

        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }    

        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }    
        for(int i=low;i<=high;i++){
            arr[i] = temp[i-low];
        }
    }
    void countPair(vector<int> &arr, int low, int mid, int high){
        int right = mid+1;
        for(int i=low;i<=mid;i++){
            while(right <= high && arr[i] > arr[right] * 2LL) right++;
            count += (right - (mid + 1));
        }
    }
    void divide(vector<int> &arr, int low, int high){
        if(low >= high){
            return;
        }

        int mid = (low + high) / 2;
        divide(arr, low, mid);
        divide(arr, mid+1, high);
        countPair(arr, low, mid, high);
        merge(arr, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        divide(nums, 0, n-1);
        return count;
    }
};