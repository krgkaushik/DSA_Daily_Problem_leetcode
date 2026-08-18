class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        // Since elements are between 0 and 50, an array is faster than a hash map
        vector<int> subarray_counts(51, 0); 

        // Slide the window of size k
        for (int i = 0; i <= n - k; i++) {
            // Track elements seen in the CURRENT subarray to avoid duplicate counts
            vector<bool> seen_in_sub(51, false);
            
            for (int j = i; j < i + k; j++) {
                seen_in_sub[nums[j]] = true;
            }
            
            // Increment global subarray appearance for unique items in this window
            for (int val = 0; val <= 50; val++) {
                if (seen_in_sub[val]) {
                    subarray_counts[val]++;
                }
            }
        }

        // Find the largest integer that appeared in exactly ONE subarray
        int largestNumber = -1;
        for (int val = 0; val <= 50; val++) {
            if (subarray_counts[val] == 1) {
                largestNumber = max(largestNumber, val);
            }
        }

        return largestNumber;
    }
};
