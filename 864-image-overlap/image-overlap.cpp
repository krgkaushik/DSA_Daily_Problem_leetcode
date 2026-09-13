class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();
        int ans = 0;

        for (int dx = -n + 1; dx < n; dx++) {

            for (int dy = -n + 1; dy < n; dy++) {

                int overlap = 0;

                for (int i = 0; i < n; i++) {

                    for (int j = 0; j < n; j++) {

                        if (img1[i][j] == 1) {

                            int ni = i + dx;
                            int nj = j + dy;

                            if (ni >= 0 && ni < n &&
                                nj >= 0 && nj < n &&
                                img2[ni][nj] == 1) {

                                overlap++;
                            }
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};