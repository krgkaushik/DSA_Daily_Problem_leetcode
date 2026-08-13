class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        // start -> end of each group
        map<int, int> groups;

        // Lengths of all groups
        multiset<int> lengths;

        // Build initial groups
        int start = 0;

        for (int i = 1; i <= n; i++) {

            if (i == n || s[i] != s[i - 1]) {
                groups[start] = i - 1;
                lengths.insert(i - start);

                start = i;
            }
        }

        // Find the group containing position pos
        auto getGroup = [&](int pos) {

            auto it = groups.upper_bound(pos);
            --it;

            return it;
        };

        vector<int> ans;

        for (int q = 0; q < queryIndices.size(); q++) {

            int pos = queryIndices[q];
            char c = queryCharacters[q];

            // Nothing changes
            if (s[pos] == c) {
                ans.push_back(*lengths.rbegin());
                continue;
            }

            // Find old group containing pos
            auto it = getGroup(pos);

            int L = it->first;
            int R = it->second;

            // Remove old group length
            auto lenIt = lengths.find(R - L + 1);
            lengths.erase(lenIt);

            // Remove old group
            groups.erase(it);

            // ------------------------------------------------
            // Split old group into left and right parts
            // ------------------------------------------------

            if (L <= pos - 1) {
                groups[L] = pos - 1;
                lengths.insert(pos - L);
            }

            if (pos + 1 <= R) {
                groups[pos + 1] = R;
                lengths.insert(R - pos);
            }

            // The changed character itself
            groups[pos] = pos;
            lengths.insert(1);

            // Update string
            s[pos] = c;

            // ------------------------------------------------
            // Merge with left group if same character
            // ------------------------------------------------

            if (pos > 0 && s[pos - 1] == s[pos]) {

                auto leftIt = getGroup(pos - 1);

                int leftL = leftIt->first;
                int leftR = leftIt->second;

                // Remove two separate lengths
                lengths.erase(lengths.find(leftR - leftL + 1));
                lengths.erase(lengths.find(1));

                // Remove both groups
                groups.erase(leftIt);
                groups.erase(pos);

                // Create merged group
                groups[leftL] = pos;

                lengths.insert(pos - leftL + 1);
            }

            // ------------------------------------------------
            // Merge with right group if same character
            // ------------------------------------------------

            if (pos + 1 < n && s[pos + 1] == s[pos]) {

                auto current = getGroup(pos);
                int curL = current->first;
                int curR = current->second;

                auto rightIt = groups.upper_bound(pos);
                int rightL = rightIt->first;
                int rightR = rightIt->second;

                // Remove both lengths
                lengths.erase(lengths.find(curR - curL + 1));
                lengths.erase(lengths.find(rightR - rightL + 1));

                // Remove groups
                groups.erase(current);
                groups.erase(rightIt);

                // Merge
                groups[curL] = rightR;

                lengths.insert(rightR - curL + 1);
            }

            // Largest group
            ans.push_back(*lengths.rbegin());
        }

        return ans;
    }
};