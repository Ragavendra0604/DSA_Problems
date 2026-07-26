class Solution {
public:
    // Next Smaller Element Index
    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nse(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    // Previous Smaller or Equal Element Index
    vector<int> findPSEE(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> psee(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return psee;
    }

    // Next Greater Element Index
    vector<int> findNGE(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nge;
    }

    // Previous Greater or Equal Element Index
    vector<int> findPGEE(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> pgee(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pgee;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            sum += 1LL * arr[i] * left * right;
        }

        return sum;
    }

    long long sumSubarrayMaxs(vector<int>& arr) {
        vector<int> nge = findNGE(arr);
        vector<int> pgee = findPGEE(arr);

        long long sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            sum += 1LL * arr[i] * left * right;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};