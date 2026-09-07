class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charMap;

        int longest = 0;
        int l = 0;
        int r;
        int maxFrequency = 0;
        int windowLen;

        for (int i = 0; i < s.length(); i++) {
            r = i;

            charMap[s[i]]++;

            maxFrequency = max(maxFrequency, charMap[s[i]]);

            windowLen = r - l + 1;

            while (windowLen - maxFrequency > k) {
                charMap[s[l]]--;
                l++;
                windowLen = r - l + 1;
            }

            longest = max(longest, windowLen);
        }

        return longest;
    }
};