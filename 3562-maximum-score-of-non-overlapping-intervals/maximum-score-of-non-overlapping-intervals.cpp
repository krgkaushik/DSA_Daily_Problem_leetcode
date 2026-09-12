class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int n = intervals.size();

        // Store:
        // [left, right, weight, original_index]
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting point
        sort(a.begin(), a.end());

        // dp[i][k] = best answer using intervals from i onward,
        // choosing at most k intervals.
        //
        // Store {score, indices}
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Option 1: don't take this interval
                dp[i][k] = dp[i + 1][k];

                // Option 2: take this interval
                long long score = a[i][2];

                vector<int> indices = {
                    (int)a[i][3]
                };

                // Find first interval whose left > current right
                int l = i + 1;
                int r = n - 1;
                int next = n;

                while (l <= r) {
                    int mid = l + (r - l) / 2;

                    if (a[mid][0] > a[i][1]) {
                        next = mid;
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }

                if (next < n && k > 1) {
                    score += dp[next][k - 1].first;

                    for (int x : dp[next][k - 1].second) {
                        indices.push_back(x);
                    }
                }

                sort(indices.begin(), indices.end());

                // Compare with current best
                if (score > dp[i][k].first) {
                    dp[i][k] = {score, indices};
                }
                else if (score == dp[i][k].first) {
                    if (indices < dp[i][k].second) {
                        dp[i][k] = {score, indices};
                    }
                }
            }
        }

        return dp[0][4].second;
    }
};