class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Create a hash set to store the numbers
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int longest = 0;
        
        // Iterate through the numbers in the hash set
        for (int num : numSet) {
            // Check if it's the start of a sequence (i.e., num-1 is not in the set)
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;
                
                // Continue checking the next consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }
                
                // Update the longest streak found
                longest = max(longest, currentStreak);
            }
        }
        
        return longest;
    }
};
