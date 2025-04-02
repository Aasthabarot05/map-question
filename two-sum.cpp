class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>nummap;
        for(int i=0;i<nums.size();i++){
            int cap=target-nums[i];
            if(nummap.find(cap)!=nummap.end()){
                return{nummap[cap],i};
            }
            nummap[nums[i]]=i;
        }
     return {};   
    }
};
