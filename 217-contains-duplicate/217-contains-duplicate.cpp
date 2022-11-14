class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // Create a set, therefore removing any duplicates
        set<int> nums_singular;
        // Insert vector into set
        nums_singular.insert(nums.cbegin(), nums.cend());
        // Compare sizes to draw conclusion
        return (nums_singular.size() < nums.size());
        
    }
};