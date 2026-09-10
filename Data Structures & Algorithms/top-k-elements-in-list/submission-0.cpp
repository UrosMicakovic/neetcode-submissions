class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> res;
        res.reserve(k);
        std::unordered_map<int, int> count_map;
        for (int num:nums){
            count_map[num]++;
        }
        std::vector<std::vector<int>> buckets(nums.size()+1);
        for(const auto& [num, freq]: count_map){
            buckets[freq].push_back(num);
        }

        for(int i=buckets.size()-1;i>=0 && res.size()<k;i--){
            for (int num:buckets[i]){
                res.push_back(num);
                if(res.size()==k) break;
            }
        }
        return res;

    }
};
