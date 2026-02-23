class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total = 1 << k;
        vector<bool> seen(total, false);

        int mask = total - 1;
        int hash = 0;

        for (int i = 0; i < s.size(); i++) {
            hash = ((hash << 1) & mask) | (s[i] - '0');

            if (i >= k - 1) {
                seen[hash] = true;
            }
        }

        for (bool x : seen)
            if (!x)
                return false;

        return true;
    }
};