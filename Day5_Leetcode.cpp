class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        for (int i=0; i<nums.size(); i++){
            auto pos = lower_bound(res.begin(),res.end(),nums[i]);
            if (pos==res.end()){
                res.push_back(nums[i]);
            }
            else{
                *pos = nums[i];
            }
        }
        return res.size();
    }
};