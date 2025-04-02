class Solution {
public:
   vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Count the frequency of each element
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }
    
    // Step 2: Create a bucket where index represents the frequency
    vector<vector<int>> buckets(nums.size() + 1); // There can be at most nums.size() different frequencies
    for (auto& entry : freqMap) {
        buckets[entry.second].push_back(entry.first);
    }
    
    // Step 3: Collect the top k frequent elements from the buckets
    vector<int> result;
    for (int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
        for (int num : buckets[i]) {
            result.push_back(num);
            if (result.size() == k) {
                return result;
            }
        }
    }
    
    return result;
}
};
