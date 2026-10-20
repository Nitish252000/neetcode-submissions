class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        // --- Method 1: HashSet --------------------------
        // set<int> seen(nums.begin(), nums.end());
        // int n = nums.size();
        // for (int i = 0; i <= n; i++) {
        //     if (!seen.count(i)) {
        //         return i;
        //     }
        // }
        // return -1;

        // ----- Method 2: Minimal and simple solution — Sum formula ------------
        // Time \(O(n)\), extra space \(O(1)\)
        // int n = nums.size();
        // int total = n * (n + 1) / 2;
        // for (auto& num : nums) {
        //     total -= num;
        // }
        // return total;

        // ----- Method 3: XOR : XOR of a number with itself is zero: x ^ x = 0.    Every number that appears in both the expected range and the array cancels out, leaving only the missing number ---------------------------
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            ans ^= i ^ nums[i];
        }
        return ans;
    }
};
