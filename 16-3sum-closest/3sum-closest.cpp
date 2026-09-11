class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        priority_queue<int>pq;
        sort( nums.begin() , nums.end());

        for( int i = 0 ; i<n-2; i++ ){
            int left = i+1;
            int right = nums.size()-1;
                   while( left < right ){
                      int curr = nums[i] + nums[left] + nums[right];
                    pq.push(curr);

                      if( curr < target ){
                        left++;
                      }

                      else{
                        right--;
                      }
                   }
                      
        }

        int ans = 0;
        int diff = INT_MAX;
        while( !pq.empty() ){
            int c = pq.top();
            pq.pop();
            int n = abs(c-target);
            if( diff > n ){
                diff = n;
                ans = c;
            }

        }

        return ans;
    }
};