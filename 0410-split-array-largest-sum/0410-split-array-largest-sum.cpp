class Solution {
public:
    int countStudents(vector<int> &arr, int pages) {
        int studentCount = 1;
        int studentPages = 0;
        
        for(int i=0;i<arr.size();i++){
            if(studentPages + arr[i] <= pages){
                studentPages += arr[i];
            }
            else{
                studentCount++;
                studentPages = arr[i];
            }
        }
        return studentCount;
    }
    
    int findMax(vector<int> &arr, int n){
        int maxEle = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i] > maxEle){
                maxEle = arr[i];
            }
        }
        
        return maxEle;
    }
    
    int findSum(vector<int> &arr, int n){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        
        return sum;
    }
    
    
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        
        if(k == 1) {
            return findSum(arr, n);
        }
        
        if(n < k){
            return -1;
        }
        
        int low = findMax(arr, n);
        int high = findSum(arr, n);
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(countStudents(arr, mid) <= k){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low; 
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums, k);
    }
};