class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> rs;

        int i = 0, m = nums1.size();
        int j = 0, n = nums2.size();

        while(i < m && j < n){
            if(nums1[i] < nums2[j]){
                rs.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                rs.push_back(nums2[j]);
                j++;
            }
            else{
                continue;
            }
        }

        while(i < m){
            rs.push_back(nums1[i]);
            i++;
        }
        while(j < n){
            rs.push_back(nums2[j]);
            j++;
        }

        int len = rs.size();

        if(len % 2 == 0){
            int mid = (0 + len) / 2;
            return (double)(rs[mid-1] + rs[mid])/2;
        }

        else{
            return (double)rs[len/2];
        }
    }
};