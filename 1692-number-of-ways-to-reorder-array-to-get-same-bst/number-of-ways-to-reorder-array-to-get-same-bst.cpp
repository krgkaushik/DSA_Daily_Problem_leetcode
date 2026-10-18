#include <vector>

using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> comb;

    long long countWays(const vector<int>& nums) {
        if (nums.size() <= 2) {
            return 1;
        }

        int root = nums[0];
        vector<int> left, right;

        // Divide elements into left and right subtrees
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        int L = left.size();
        int R = right.size();

        long long waysLeft = countWays(left);
        long long waysRight = countWays(right);

        // Interleaving ways * left subtree ways * right subtree ways
        long long interleave = comb[L + R][L];
        long long totalWays = (interleave * waysLeft) % MOD;
        totalWays = (totalWays * waysRight) % MOD;

        return totalWays;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        // Initialize Pascal's Triangle table to compute nCr % MOD
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        // Subtract 1 to exclude the original input permutation
        return (countWays(nums) - 1 + MOD) % MOD;
    }
};