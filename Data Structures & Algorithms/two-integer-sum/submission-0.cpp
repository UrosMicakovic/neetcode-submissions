class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> num_to_index;

        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            if(num_to_index.find(diff)!=num_to_index.end()){
                return{num_to_index[diff], i};
            }

            num_to_index[nums[i]]=i;
        }

        return {};
    }
};
