class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagram_map;

        for (const std::string& s : strs){
            std::string key=s;
            std::sort(key.begin(), key.end());
            anagram_map[key].push_back(s);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(anagram_map.size());

        for (auto& pair:anagram_map){
            result.push_back(std::move(pair.second));
        }

        return result;
    }
};
