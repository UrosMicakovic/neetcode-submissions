class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> charSet;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); ++right) {
            // Shrink window from the left until s[right] is no longer in the set
            while (charSet.contains(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            // Insert current character and calculate current window size
            charSet.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
