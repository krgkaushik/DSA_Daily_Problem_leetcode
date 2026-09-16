class Solution {
public:
    static const long long MOD = 1000000007;

    long long modPow(long long a, long long b) {
        long long ans = 1;

        while (b) {
            if (b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        long long ans = 1;

        // C(N, R)
        for (int i = 1; i <= R; i++) {
            ans = ans * (N - R + i) % MOD;
            ans = ans * modPow(i, MOD - 2) % MOD;
        }

        return ans;
    }
};