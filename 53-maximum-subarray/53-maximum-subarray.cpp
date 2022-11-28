class Solution {
private:
    const int MIN_INT = -1 * pow(10, 4);
public:
    int maxSubArray(vector<int>& nums) {
        int finalSum = MIN_INT;                                                 // Set default to lowest possible integers
        
        for (int index = 0; index < nums.size(); index++) {                     // Iterate through every element in vector TO:
            int tempSum = 0;                                                    // Initialize temporary sum for sub loop
            
            for (int subIndex = index; subIndex < nums.size(); subIndex++) {    // Iterate through sub vector (from index to EOV) TO:
              tempSum += nums[subIndex];                                        // Summate sub vector elements
              if (tempSum > finalSum) finalSum = tempSum;                       // IF: tempSum > finalSum THEN: update finalSum
            }
         }
        
        return finalSum;
    }
};
