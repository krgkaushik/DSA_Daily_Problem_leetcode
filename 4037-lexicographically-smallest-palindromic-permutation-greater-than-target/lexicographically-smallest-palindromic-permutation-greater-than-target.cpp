class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int m = n / 2;

        auto build = [&](string half) {
            string res = half;

            if (n % 2)
                res += mid;

            reverse(half.begin(), half.end());
            res += half;

            return res;
        };

        string half = "";

        for (int i = 0; i < 26; i++)
            half += string(halfCnt[i], char('a' + i));

        string smallest = build(half);

        if (smallest > target)
            return smallest;

        string targetHalf = target.substr(0, m);

        vector<int> rem = halfCnt;

        for (int i = 0; i < m; i++) {
            int x = targetHalf[i] - 'a';

            if (rem[x] == 0) {
                for (int pos = i; pos >= 0; pos--) {
                    rem = halfCnt;

                    for (int j = 0; j < pos; j++)
                        rem[targetHalf[j] - 'a']--;

                    int cur = targetHalf[pos] - 'a';

                    for (int c = cur + 1; c < 26; c++) {
                        if (rem[c] == 0)
                            continue;

                        rem[c]--;

                        string h = targetHalf.substr(0, pos);
                        h += char('a' + c);

                        for (int j = 0; j < 26; j++)
                            h += string(rem[j], char('a' + j));

                        return build(h);
                    }
                }

                return "";
            }

            rem[x]--;
        }

        string candidate = build(targetHalf);

        if (candidate > target)
            return candidate;

        for (int pos = m - 1; pos >= 0; pos--) {
            rem = halfCnt;

            for (int j = 0; j < pos; j++)
                rem[targetHalf[j] - 'a']--;

            int cur = targetHalf[pos] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                rem[c]--;

                string h = targetHalf.substr(0, pos);
                h += char('a' + c);

                for (int j = 0; j < 26; j++)
                    h += string(rem[j], char('a' + j));

                string ans = build(h);

                if (ans > target)
                    return ans;
            }
        }

        return "";
    }
};